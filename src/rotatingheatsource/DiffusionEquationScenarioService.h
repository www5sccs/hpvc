// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_SCENARIO_SERVICE_H_
#define _ROTATINGHEATSOURCE_SCENARIO_SERVICE_H_


#include "tarch/services/Service.h"
#include "rotatingheatsource/DiffusionEquationScenario.h"



namespace rotatingheatsource {
  class DiffusionEquationScenarioService;
}


/**
 * Service for the diffusion equation's scenario
 *
 *
 *
 * @author Tobias Weinzierl
 */
class rotatingheatsource::DiffusionEquationScenarioService: public tarch::services::Service {
  private:
	  DiffusionEquationScenarioService();

	  DiffusionEquationScenario* _scenario;
  public:
	  virtual ~DiffusionEquationScenarioService();

	  static DiffusionEquationScenarioService& getInstance();

	  /**
	   * This operation here is nop. Usually, it should for example react if the
	   * master node moves the geometry, e.g., or different boundary conditions
	   * are set.
	   */
    virtual void receiveDanglingMessages();

    DiffusionEquationScenario& getScenario();
    const DiffusionEquationScenario& getScenario() const;

    /**
     * Set the scenario. You are responsible to ensure that this scenario is
     * alive as long as anybody needs the service.
     */
    void setScenario(DiffusionEquationScenario* scenario);
};


#endif
