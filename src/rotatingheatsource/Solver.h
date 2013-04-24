// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EQUATION_SOLVER_H_
#define _ROTATINGHEATSOURCE_EQUATION_SOLVER_H_


#include "matrixfree/solver/Smoother.h"
#include "matrixfree/stencil/Stencil.h"
#include "matrixfree/stencil/ElementMatrix.h"
#include "tarch/multicore/BooleanSemaphore.h"
#include "tarch/logging/Log.h"


namespace rotatingheatsource {
  class Solver;
}


/**
 * Solver component for the diffusion equation
 *
 * This solver is basically a wrapper for the toolbox's solver classes such as
 * the Jacobi solver. It takes the application domain-specific values (such as
 * rhs and temperatures), combines them into the right-hand side vectors and
 * left-hand side vectors (unknowns), and forwards these two components to the
 * aggregated solver.
 *
 * !!! Statistics
 *
 * The toolbox solvers already provide a couple of statistics, and most of the
 * getters in this class that provide any statistics are basically forwards.
 * However, for implicit time stepping schemes, there's one difference: Those
 * schemes combine new and old temperature values, and the old values
 * co-determine the right-hand side of the equation systems. For the solver,
 * the right-hand side is just a vector, i.e. the solver can only keep track
 * of the current solution and of the updates of the current solution.
 * It cannot keep track of the difference of current solution to old solution.
 * So this is up to this class.
 *
 * !!! Workflow
 *
 * Steps:
 *
 * - beginIteration(): Inform solver about time step size (and remember the
 *   mesh width if you are on the regular grid)
 * - touchVertexFirstTime(): Invoke a clearResidual() call.
 * - handleCell(): Accumulate residual according to
 *   computeResidualContributionForExplicitEulerStep().
 * - touchVertexLastTime(): Call getNewTemperatureForExplicitEulerStep() and
 *   set temperature accordingly. Afterwards, invoke
 *   copyTemperatureToOldTemperature().
 *
 * !!! Multithreading
 *
 * You may copy a solver as it supports bit-wise copying. Afterwards, you should
 * always call clear if the solver is ran on a different thread. There's also a
 * merge operation merging two solvers. This one basically increments all the
 * counters.
 */
class rotatingheatsource::Solver {
  private:
    static tarch::logging::Log _log;

    double _timeStepSize;

    matrixfree::stencil::ElementWiseAssemblyMatrix _massMatrixWithoutHScaling;

    matrixfree::stencil::ElementMatrix             _elementMatrix;

    /**
     * Has only semantics with implicit time stepping. See class documentation.
     */
    double _differenceToOldTemperatureInHNorm;

    /**
     * Has only semantics with implicit time stepping. See class documentation.
     */
    double _differenceToOldTemperatureInMaxNorm;

  protected:
    matrixfree::solver::Smoother                   _smoother;

  public:
    Solver();

    /**
     * Copy constructor
     *
     * Used implicitly by the shared memory parallelisation
     */
    Solver(const Solver& solver);

    void setTimeStepSize( double tau );
    double getTimeStepSize() const;

    /**
     * Call this
     *
     * - only for inner points and
     * - with the residual computed with the residual computing method from
     *   the explicit Euler.
     *
     * !!! Rationale
     *
     * Method is not const as it updates internal counters/measurements.
     */
    double getNewTemperatureForExplicitEulerStep(
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      double                                       residual,
      const double &                               oldTemperature
    );

    /**
     * @param h               Not needed for the update but for the statistics
     * @param oldTemperature  Not needed for the update but for the statistics
     */
    double getNewTemperatureForImplicitEulerStep(
      double                                       residual,
      const matrixfree::stencil::Stencil&          stencil,
      const double &                               newTemperatureSoFar,
      const double &                               oldTemperature,
      const double &                               hVolume
    );

    /**
     * Please add the result to your residual
     */
    tarch::la::Vector<TWO_POWER_D,double> computeResidualContributionForExplicitEulerStep(
      const tarch::la::Vector<TWO_POWER_D,double>&                      rhss,
      const tarch::la::Vector<TWO_POWER_D,double>&                      oldTemperatures,
      const tarch::la::Vector<DIMENSIONS,double>&                       h,
      const tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double>&  stencils
    ) const;


    /**
     * Computes the cell contribution to the residual for the fine grid, i.e.
     * for the residual
     * @f$ - M(h^d) u(t+\tau ) - \tau A u(t+\tau )@f$
     */
    tarch::la::Vector<TWO_POWER_D,double> computeResidualContributionForImplicitEulerStepFromSolution(
      const tarch::la::Vector<TWO_POWER_D,double>&                      newTemperatures,
      const tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double>&  stencils
    ) const;

    /**
     * Computes the cell contribution to the residual for the fine grid, i.e.
     * for the residual
     * @f$ M(h^d) \cdot ( \tau rhss + u(t))@f$
     * This residual computation works only for the fine grid.
     */
    tarch::la::Vector<TWO_POWER_D,double> computeResidualContributionForImplicitEulerStepFromRhs(
      const tarch::la::Vector<TWO_POWER_D,double>&                      rhss,
      const tarch::la::Vector<TWO_POWER_D,double>&                      oldTemperatures,
      const tarch::la::Vector<DIMENSIONS,double>&                       h
    ) const;

    /**
     * Delegate to smoother.
     */
    void clearMeasurements();

    /**
     * Delegate to smoother.
     */
    double getSolutionInMaximumNorm() const;

    /**
     * Delegate to smoother.
     */
    double getSolutionInHNorm() const;

    /**
     * Delegate to smoother. Always referes to the current solution.
     */
    double getSolutionUpdateInMaximumNorm() const;

    /**
     * Delegate to smoother. Always referes to the current solution.
     */
    double getSolutionUpdateInHNorm() const;

    /**
     * Has only semantics for implicit time stepping.
     */
    double getDifferenceToOldTemperatureInMaxNorm() const;

    /**
     * Has only semantics for implicit time stepping.
     */
    double getDifferenceToOldTemperatureInHNorm() const;

    /**
     * Delegate to smoother.
     */
    int getNumberOfStencilUpdates() const;

    /**
     * Delegate to smoother.
     */
    void setOmega(double value);

    void mergeWithSolverFromOtherThread(const Solver& solver);

    std::string toString() const;

};


#endif

