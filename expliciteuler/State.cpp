#include "rotatingheatsource/expliciteuler/State.h"
#include "rotatingheatsource/expliciteuler/Cell.h"
#include "rotatingheatsource/expliciteuler/Vertex.h"

#include "peano/grid/Checkpoint.h"



rotatingheatsource::expliciteuler::State::State():
  Base() { 
}


rotatingheatsource::expliciteuler::State::State(const Base::PersistentState& argument):
  Base(argument) {
}


void rotatingheatsource::expliciteuler::State::writeToCheckpoint( peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell>& checkpoint ) const {
  // @todo Insert your code here
}

    
void rotatingheatsource::expliciteuler::State::readFromCheckpoint( const peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell>& checkpoint ) {
  // @todo Insert your code here
}


void rotatingheatsource::expliciteuler::State::setUMeasurements(
  double uInMaxNorm,
  double updateInMaxNorm,
  double uInHNorm,
  double updateInHNorm
) {
  _stateData.setUpdateUH(_stateData.getUpdateUH()+updateInHNorm);
  _stateData.setUH(_stateData.getUH()+uInHNorm);
  if (updateInMaxNorm > _stateData.getUpdateUMax()) {
    _stateData.setUpdateUMax(updateInMaxNorm);
  }
  if (uInMaxNorm > _stateData.getUMax() ) {
    _stateData.setUMax(uInMaxNorm);
  }
}


void rotatingheatsource::expliciteuler::State::clearMeasurements() {
  _stateData.setNumberOfStencilUpdates(0.0);
  _stateData.setUpdateUH(0.0);
  _stateData.setUH(0.0);
  _stateData.setUpdateUMax(0.0);
  _stateData.setUMax(0.0);
}


void rotatingheatsource::expliciteuler::State::incNumberOfStencilUpdates(double value) {
  assertion1(value==0.0 || value>=1.0, value);
  _stateData.setNumberOfStencilUpdates(_stateData.getNumberOfStencilUpdates()+value);
}



int rotatingheatsource::expliciteuler::State::getTimeStep() const {
  return _stateData.getTimeStep();
}


void rotatingheatsource::expliciteuler::State::setTimeStepSize(double value) {
  assertion1( value > 0.0, value );
  _stateData.setTimeStepSize(value);
}


void rotatingheatsource::expliciteuler::State::setNextTime(double value) {
  assertion( _stateData.getTimeStepSize()>0.0 );
  _stateData.setTimeStep( _stateData.getTimeStep()+1 );
  _stateData.setTime( value );
}


double rotatingheatsource::expliciteuler::State::getTimeStepSize() const {
  return _stateData.getTimeStepSize();
}

double rotatingheatsource::expliciteuler::State::getTime() const {
  return _stateData.getTime();
}


double rotatingheatsource::expliciteuler::State::getUInMaxNorm() const {
  return _stateData.getUMax();
}


double rotatingheatsource::expliciteuler::State::getUpdateInMaxNorm() const {
  return _stateData.getUpdateUMax();
}


double rotatingheatsource::expliciteuler::State::getUInHNorm() const {
  return _stateData.getUH();
}


double rotatingheatsource::expliciteuler::State::getUpdateInHNorm() const {
  return _stateData.getUpdateUH();
}


double rotatingheatsource::expliciteuler::State::getNumberOfStencilUpdates() const {
  return _stateData.getNumberOfStencilUpdates();
}

void rotatingheatsource::expliciteuler::State::setGlobalPlotCounter(int value) {
  _stateData.setGlobalPlotCounter(value);
}

int rotatingheatsource::expliciteuler::State::getGlobalPlotCounter() const {
  return _stateData.getGlobalPlotCounter();
}

std::string rotatingheatsource::expliciteuler::State::toString() const {
  return _stateData.toString();
}
