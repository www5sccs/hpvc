// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EQUATION_DIFFUSION_EQUATION_SCENARIO_H_
#define _ROTATINGHEATSOURCE_EQUATION_DIFFUSION_EQUATION_SCENARIO_H_


#include "peano/geometry/Geometry.h"
#include "rotatingheatsource/StartGrid.h"
#include "rotatingheatsource/ExperimentSetup.h"


namespace rotatingheatsource {
  class DiffusionEquationScenario;
}


/**
 * Poisson Scenario
 *
 * Like any scenario, the poisson scenario merged different views on the
 * experimental setup, i.e. an instance of a Poisson scenario is all a
 * poisson PDE solver has to know about the experimental setting.
 *
 * Before you start up a Poisson experiment, you although have to create a
 * poisson scenario on each node and add it to the local service.
 *
 * @author Tobias Weinzierl
 */
class rotatingheatsource::DiffusionEquationScenario:
  public peano::geometry::Geometry,
  public rotatingheatsource::StartGrid,
  public rotatingheatsource::ExperimentSetup
{
  public:

    DiffusionEquationScenario() : peano::geometry::Geometry() {}

    /**
     * This operation is important for time-dependent scnearios, i.e. it
     * allows the scenario (or, more often, the geometry) to change.
     */
    virtual void setTime( double t ) = 0;

    /**
     * Take the input data, and stream it into a file. This is in particular
     * useful for the complex domain models.
     */
    virtual void plotInputDataToVTKFile(const std::string& data) const = 0;

    /**
     * Get the file where to write the data to. The plotter should append the
     * time step and a proper file extension.
     */
    virtual std::string getOutputFileName() const = 0;
};

#endif
