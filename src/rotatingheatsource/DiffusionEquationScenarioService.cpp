#include "rotatingheatsource/DiffusionEquationScenarioService.h"



#include "tarch/services/ServiceFactory.h"
registerService(rotatingheatsource::DiffusionEquationScenarioService)



rotatingheatsource::DiffusionEquationScenarioService::DiffusionEquationScenarioService():
  _scenario(0) {
}


void rotatingheatsource::DiffusionEquationScenarioService::setScenario(DiffusionEquationScenario* scenario) {
  _scenario = scenario;
}


rotatingheatsource::DiffusionEquationScenarioService::~DiffusionEquationScenarioService() {
}


rotatingheatsource::DiffusionEquationScenarioService& rotatingheatsource::DiffusionEquationScenarioService::getInstance() {
  static DiffusionEquationScenarioService singleton;
  return singleton;
}


rotatingheatsource::DiffusionEquationScenario& rotatingheatsource::DiffusionEquationScenarioService::getScenario() {
  assertion( _scenario!=0 );
  return *_scenario;
}


const rotatingheatsource::DiffusionEquationScenario& rotatingheatsource::DiffusionEquationScenarioService::getScenario() const {
  assertion( _scenario!=0 );
  return *_scenario;
}


void rotatingheatsource::DiffusionEquationScenarioService::receiveDanglingMessages() {
}
