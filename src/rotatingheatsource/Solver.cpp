#include "rotatingheatsource/Solver.h"
#include "tarch/Assertions.h"
#include "matrixfree/stencil/StencilFactory.h"


tarch::logging::Log rotatingheatsource::Solver::_log( "rotatingheatsource::Solver" );


rotatingheatsource::Solver::Solver():
  _timeStepSize(0.0) {
  #if defined(Dim2)
  _massMatrixWithoutHScaling =
    _elementMatrix.getElementWiseAssemblyMatrix(
      matrixfree::stencil::StencilFactory::stencilProduct(
        matrixfree::stencil::StencilFactory::get1DMassStencilWithoutHScaling(),
        matrixfree::stencil::StencilFactory::get1DMassStencilWithoutHScaling()
      )
    );
  #elif defined(Dim3)
  _massMatrixWithoutHScaling =
    _elementMatrix.getElementWiseAssemblyMatrix(
      matrixfree::stencil::StencilFactory::stencilProduct(
        matrixfree::stencil::StencilFactory::get1DMassStencilWithoutHScaling(),
        matrixfree::stencil::StencilFactory::get1DMassStencilWithoutHScaling(),
        matrixfree::stencil::StencilFactory::get1DMassStencilWithoutHScaling()
      )
    );
  #else
  #error Dimension not supported
  #endif
}



rotatingheatsource::Solver::Solver(const Solver& solver):
  _timeStepSize(solver._timeStepSize),
  _massMatrixWithoutHScaling(solver._massMatrixWithoutHScaling),
  _elementMatrix(solver._elementMatrix),
  _differenceToOldTemperatureInHNorm(0.0),
  _differenceToOldTemperatureInMaxNorm(0.0),
  _smoother(solver._smoother) {
}



void rotatingheatsource::Solver::setTimeStepSize( double tau ) {
  assertion1( tau > 0.0, tau );
  _timeStepSize = tau;
}


double rotatingheatsource::Solver::getTimeStepSize() const {
  return _timeStepSize;
}


double rotatingheatsource::Solver::getNewTemperatureForExplicitEulerStep(
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  double                                       residual,
  const double &                               oldTemperature
) {
  const double cellVolume = tarch::la::volume(h);

  assertion1( _timeStepSize>0.0, _timeStepSize );
  assertion1( cellVolume>0.0, cellVolume );

  residual *= _timeStepSize / cellVolume;

  const double diagonalValue = 1.0;
  assertion1( _smoother.getOmega(), 1.0 );

  return _smoother.getNewValueOfJacobiStep(oldTemperature,residual,diagonalValue,cellVolume);
}


double rotatingheatsource::Solver::getNewTemperatureForImplicitEulerStep(
  double                                   residual,
  const matrixfree::stencil::Stencil&      stencil,
  const double &                           newTemperatureSoFar,
  const double &                           oldTemperature,
  const double &                           h
) {
  assertion1( _timeStepSize>0.0, _timeStepSize );

  double diagonalElement = _elementMatrix.getDiagonalElement(stencil);
  assertion( diagonalElement>0.0 );

  double result = _smoother.getNewValueOfJacobiStep(
    newTemperatureSoFar,
    residual,
    diagonalElement,
    h
  );

  const double differenceToOldTemperature = std::abs( result - oldTemperature );

  if (differenceToOldTemperature>_differenceToOldTemperatureInMaxNorm) {
    _differenceToOldTemperatureInMaxNorm = differenceToOldTemperature;
  }
  _differenceToOldTemperatureInHNorm += differenceToOldTemperature*h;

  return result;
}


tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::Solver::computeResidualContributionForExplicitEulerStep(
  const tarch::la::Vector<TWO_POWER_D,double>&                      rhss,
  const tarch::la::Vector<TWO_POWER_D,double>&                      oldTemperatures,
  const tarch::la::Vector<DIMENSIONS,double>&                       h,
  const tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double>&  stencils
) const {
  tarch::la::Vector<TWO_POWER_D,double> residual;

  residual = _massMatrixWithoutHScaling * rhss * tarch::la::volume(h);
  matrixfree::stencil::ElementWiseAssemblyMatrix localStiffnessMatrix;
  localStiffnessMatrix = _elementMatrix.getElementWiseAssemblyMatrix(stencils);

  residual -= localStiffnessMatrix * oldTemperatures;

  return residual;
}



tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::Solver::computeResidualContributionForImplicitEulerStepFromSolution(
  const tarch::la::Vector<TWO_POWER_D,double>&                      newTemperatures,
  const tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double>&  stencils
) const {
  assertion1( _timeStepSize>0.0, _timeStepSize );

  tarch::la::Vector<TWO_POWER_D,double> residual;

  matrixfree::stencil::ElementWiseAssemblyMatrix localStiffnessMatrix;
  localStiffnessMatrix = _elementMatrix.getElementWiseAssemblyMatrix(stencils);

  residual = localStiffnessMatrix * newTemperatures * (-1.0);

  return residual;
}


tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::Solver::computeResidualContributionForImplicitEulerStepFromRhs(
  const tarch::la::Vector<TWO_POWER_D,double>&  rhss,
  const tarch::la::Vector<TWO_POWER_D,double>&  oldTemperatures,
  const tarch::la::Vector<DIMENSIONS,double>&   h
) const {
  logTraceInWith3Arguments( "computeResidualContributionForImplicitEulerStepFromRhs(...)", rhss, oldTemperatures, h );

  assertion1( _timeStepSize>0.0, _timeStepSize );

  tarch::la::Vector<TWO_POWER_D,double> residual;

  residual = _massMatrixWithoutHScaling * (rhss * _timeStepSize + oldTemperatures ) * tarch::la::volume(h);

  logTraceOutWith1Argument( "computeResidualContributionForImplicitEulerStepFromRhs(...)", residual );

  return residual;
}


void rotatingheatsource::Solver::setOmega(double value) {
  _smoother.setOmega(value);
}


void rotatingheatsource::Solver::clearMeasurements() {
  _smoother.clearMeasurements();

  _differenceToOldTemperatureInHNorm   = 0.0;
  _differenceToOldTemperatureInMaxNorm = 0.0;
}


void rotatingheatsource::Solver::mergeWithSolverFromOtherThread(const Solver& solver) {
  assertionEquals( _timeStepSize, solver._timeStepSize );

  _smoother.mergeWithSmootherFromOtherThread(solver._smoother);

  _differenceToOldTemperatureInHNorm   += solver._differenceToOldTemperatureInHNorm;
  _differenceToOldTemperatureInMaxNorm  = _differenceToOldTemperatureInMaxNorm > solver._differenceToOldTemperatureInMaxNorm ? _differenceToOldTemperatureInMaxNorm : solver._differenceToOldTemperatureInMaxNorm;
}


double rotatingheatsource::Solver::getSolutionInMaximumNorm() const {
  return _smoother.getSolutionInMaximumNorm();
}


double rotatingheatsource::Solver::getSolutionInHNorm() const {
  return _smoother.getSolutionInHNorm();
}


double rotatingheatsource::Solver::getSolutionUpdateInMaximumNorm() const {
  return _smoother.getSolutionUpdateInMaximumNorm();
}


double rotatingheatsource::Solver::getSolutionUpdateInHNorm() const {
  return _smoother.getSolutionUpdateInHNorm();
}


int rotatingheatsource::Solver::getNumberOfStencilUpdates() const {
  return _smoother.getNumberOfStencilUpdates();
}


double rotatingheatsource::Solver::getDifferenceToOldTemperatureInMaxNorm() const {
  return _differenceToOldTemperatureInMaxNorm;
}


double rotatingheatsource::Solver::getDifferenceToOldTemperatureInHNorm() const {
  return _differenceToOldTemperatureInHNorm;
}


std::string rotatingheatsource::Solver::toString() const {
  std::ostringstream msg;

  msg << "(|u(t+1)-u(t)|_L2=" << _differenceToOldTemperatureInHNorm
      << ",|u(t+1)-u(t)|_L2=" << _differenceToOldTemperatureInMaxNorm
      << ",solver=no toString() available yet"
      << ")";

  return msg.str();
}

