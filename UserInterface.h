// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_USER_INTERFACE_H_
#define _ROTATINGHEATSOURCE_USER_INTERFACE_H_


#include "peano/utils/UserInterface.h"


namespace rotatingheatsource {
  class UserInterface;
}


class rotatingheatsource::UserInterface: public peano::utils::UserInterface {
  private:
    int    _numberOfSpacesPerColumn;

    double _globalStencilUpdates;

    double _maxOfUEverMeasuredInHNorm;
    double _maxOfUEverMeasuredInMaxNorm;
  public:
    /**
     * For implicit Euler where one header per time step is written
     */
    UserInterface(
      const std::string& experimentTitle,
      double             simulationTime,
      double             timeStepSize,
      double             relaxationFactor,
      double             stencilEvaluationsDoneSoFar = 0.0,
      int                numberOfSpacesPerColumn = 12
    );

    /**
     * For explicit Euler where one header for the whole simulation is sufficient
     */
    UserInterface(
      const std::string& experimentTitle,
      double             timeStepSize,
      int                numberOfSpacesPerColumn = 14
    );

    void printIterationInfo(
      double t,
      double dt,
      double solutionInMaximumNorm,
      double solutionUpdateInMaximumNorm,
      double solutionInHNorm,
      double solutionUpdateInHNorm,
      double numberOfStencilUpdates,
      int    iterations,
      const std::string& comment
    );

    double getTotalStencilEvaluations() const;

    double getInverseOfBiggestUEverMeasuredInHNorm() const;
    double getInverseOfBiggestUEverMeasuredInMaxNorm() const;
};


#endif

