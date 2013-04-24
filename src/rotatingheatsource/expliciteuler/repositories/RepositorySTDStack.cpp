#include "rotatingheatsource/expliciteuler/repositories/RepositorySTDStack.h"

#include "tarch/Assertions.h"
#include "tarch/timing/Watch.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#include "tarch/parallel/NodePool.h"
#include "peano/parallel/SendReceiveBufferPool.h"
#include "peano/parallel/loadbalancing/Oracle.h"
#endif

#include "peano/datatraversal/autotuning/Oracle.h"


tarch::logging::Log rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::_log( "rotatingheatsource::expliciteuler::repositories::RepositorySTDStack" );


rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::RepositorySTDStack(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
):
  _geometry(geometry),
  _cellStack(),
  _vertexStack(),
  _solverState(),
  _gridWithSetupExperiment(_vertexStack,_cellStack,_geometry,_solverState,domainSize,computationalDomainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPerformExplicitEulerTimeStep(_vertexStack,_cellStack,_geometry,_solverState,domainSize,computationalDomainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPerformExplicitEulerTimeStepAndPlot(_vertexStack,_cellStack,_geometry,_solverState,domainSize,computationalDomainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPlot(_vertexStack,_cellStack,_geometry,_solverState,domainSize,computationalDomainOffset,_regularGridContainer,_traversalOrderOnTopLevel),

  _repositoryState() {
  logTraceIn( "RepositorySTDStack(...)" );
  _repositoryState.setAction( rotatingheatsource::expliciteuler::records::RepositoryState::Terminate );

  peano::datatraversal::autotuning::Oracle::getInstance().setNumberOfOracles(4 +3);
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().setNumberOfOracles(4 +3 );
  #endif
  
  
  logTraceOut( "RepositorySTDStack(...)" );
}



rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::RepositorySTDStack(
  peano::geometry::Geometry&                   geometry
):
  _geometry(geometry),
  _cellStack(),
  _vertexStack(),
  _solverState(),
  _gridWithSetupExperiment(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPerformExplicitEulerTimeStep(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPerformExplicitEulerTimeStepAndPlot(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithPlot(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),

  _repositoryState() {
  logTraceIn( "RepositorySTDStack(Geometry&)" );

  _repositoryState.setAction( rotatingheatsource::expliciteuler::records::RepositoryState::Terminate );
  
  peano::datatraversal::autotuning::Oracle::getInstance().setNumberOfOracles(4 +3);
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().setNumberOfOracles(4 +3 );
  #endif
  
  
  logTraceOut( "RepositorySTDStack(Geometry&)" );
}
    
   
rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::~RepositorySTDStack() {
  assertionMsg( _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::Terminate, "terminate() must be called before destroying repository." );
}


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::restart(
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
  int                                          domainLevel,
  const tarch::la::Vector<DIMENSIONS,int>&     positionOfCentralElementWithRespectToCoarserRemoteLevel
) {
  logTraceInWith4Arguments( "restart(...)", domainSize, domainOffset, domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel );
  #ifdef Parallel
  assertion( !tarch::parallel::Node::getInstance().isGlobalMaster());
  #endif
  
  logInfo( "restart(...)", "start node for subdomain " << domainOffset << "x" << domainSize << " on level " << domainLevel );
  
  assertion( _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::Terminate );

  _vertexStack.clear();
  _cellStack.clear();

  _gridWithSetupExperiment.restart(domainSize,domainOffset,domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithPerformExplicitEulerTimeStep.restart(domainSize,domainOffset,domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithPerformExplicitEulerTimeStepAndPlot.restart(domainSize,domainOffset,domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithPlot.restart(domainSize,domainOffset,domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel);


  _solverState.restart();

  logTraceOut( "restart(...)" );
}


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::terminate() {
  logTraceIn( "terminate()" );
  
  _repositoryState.setAction( rotatingheatsource::expliciteuler::records::RepositoryState::Terminate );
  
  #ifdef Parallel
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    tarch::parallel::NodePool::getInstance().broadcastToWorkingNodes(
      _repositoryState,
      peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag()
    );
  }
  peano::parallel::SendReceiveBufferPool::getInstance().terminate();
  #endif

  _gridWithSetupExperiment.terminate();
  _gridWithPerformExplicitEulerTimeStep.terminate();
  _gridWithPerformExplicitEulerTimeStepAndPlot.terminate();
  _gridWithPlot.terminate();


  logInfo( "terminate()", "rank has terminated" );
  logTraceOut( "terminate()" );
}


rotatingheatsource::expliciteuler::State& rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::getState() {
  return _solverState;
}


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::iterate(bool reduceState) {
  tarch::timing::Watch watch( "rotatingheatsource::expliciteuler::repositories::RepositorySTDStack", "iterate(bool)", false);
  
  #ifdef Parallel
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    _repositoryState.setReduceState(reduceState);
    tarch::parallel::NodePool::getInstance().broadcastToWorkingNodes(
      _repositoryState,
      peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag()
    );
  }
  else {
    reduceState = _repositoryState.getReduceState();
  }
  #endif
  
  peano::datatraversal::autotuning::Oracle::getInstance().switchToOracle(_repositoryState.getAction());
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().switchToOracle(_repositoryState.getAction());
  #endif
  
  
  switch ( _repositoryState.getAction()) {
    case rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterSetupExperiment: watch.startTimer(); _gridWithSetupExperiment.iterate(reduceState); watch.stopTimer(); _measureSetupExperimentCPUTime.setValue( watch.getCPUTime() ); _measureSetupExperimentCalendarTime.setValue( watch.getCalendarTime() ); break;
    case rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStep: watch.startTimer(); _gridWithPerformExplicitEulerTimeStep.iterate(reduceState); watch.stopTimer(); _measurePerformExplicitEulerTimeStepCPUTime.setValue( watch.getCPUTime() ); _measurePerformExplicitEulerTimeStepCalendarTime.setValue( watch.getCalendarTime() ); break;
    case rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStepAndPlot: watch.startTimer(); _gridWithPerformExplicitEulerTimeStepAndPlot.iterate(reduceState); watch.stopTimer(); _measurePerformExplicitEulerTimeStepAndPlotCPUTime.setValue( watch.getCPUTime() ); _measurePerformExplicitEulerTimeStepAndPlotCalendarTime.setValue( watch.getCalendarTime() ); break;
    case rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPlot: watch.startTimer(); _gridWithPlot.iterate(reduceState); watch.stopTimer(); _measurePlotCPUTime.setValue( watch.getCPUTime() ); _measurePlotCalendarTime.setValue( watch.getCalendarTime() ); break;

    case rotatingheatsource::expliciteuler::records::RepositoryState::Terminate:
      assertionMsg( false, "this branch/state should never be reached" ); 
      break;
    case rotatingheatsource::expliciteuler::records::RepositoryState::ReadCheckpoint:
      assertionMsg( false, "not implemented yet" );
      break;
    case rotatingheatsource::expliciteuler::records::RepositoryState::WriteCheckpoint:
      assertionMsg( false, "not implemented yet" );
      break;
  }
}

 void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::switchToSetupExperiment() { _repositoryState.setAction(rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterSetupExperiment); }
 void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::switchToPerformExplicitEulerTimeStep() { _repositoryState.setAction(rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStep); }
 void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::switchToPerformExplicitEulerTimeStepAndPlot() { _repositoryState.setAction(rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStepAndPlot); }
 void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::switchToPlot() { _repositoryState.setAction(rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPlot); }



 bool rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::isActiveAdapterSetupExperiment() const { return _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterSetupExperiment; }
 bool rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::isActiveAdapterPerformExplicitEulerTimeStep() const { return _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStep; }
 bool rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::isActiveAdapterPerformExplicitEulerTimeStepAndPlot() const { return _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPerformExplicitEulerTimeStepAndPlot; }
 bool rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::isActiveAdapterPlot() const { return _repositoryState.getAction() == rotatingheatsource::expliciteuler::records::RepositoryState::UseAdapterPlot; }



peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell>* rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::createEmptyCheckpoint() {
  return new peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell>();
} 


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::writeCheckpoint(peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell> * const checkpoint) {
  _solverState.writeToCheckpoint( *checkpoint );
  _vertexStack.writeToCheckpoint( *checkpoint );
  _cellStack.writeToCheckpoint( *checkpoint );
} 


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::readCheckpoint( peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell> const * const checkpoint ) {
  assertionMsg( checkpoint->isValid(), "checkpoint has to be valid if you call this operation" );

  _solverState.readFromCheckpoint( *checkpoint );
  _vertexStack.readFromCheckpoint( *checkpoint );
  _cellStack.readFromCheckpoint( *checkpoint );
}


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::setMaximumMemoryFootprintForTemporaryRegularGrids(double value) {
  _regularGridContainer.setMaximumMemoryFootprintForTemporaryRegularGrids(value);
}


#ifdef Parallel
bool rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::continueToIterate() {
  logTraceIn( "continueToIterate()" );

  assertion( !tarch::parallel::Node::getInstance().isGlobalMaster());

  bool result;
  if ( _solverState.hasJoinedWithMaster() ) {
    result = false;
  }
  else {
    int masterNode = tarch::parallel::Node::getInstance().getGlobalMasterRank();
    assertion( masterNode != -1 );

    _repositoryState.receive( masterNode, peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag(), true );

    result = _repositoryState.getAction()!=rotatingheatsource::expliciteuler::records::RepositoryState::Terminate;
  }
   
  logTraceOutWith1Argument( "continueToIterate()", result );
  return result;
}
#endif


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::logIterationStatistics() const {
  logInfo( "logIterationStatistics()", "|| adapter name \t || iterations \t || total CPU time [t]=s \t || average CPU time [t]=s \t || total user time [t]=s \t || average user time [t]=s  || CPU time properties  || user time properties " );  
   logInfo( "logIterationStatistics()", "| SetupExperiment \t |  " << _measureSetupExperimentCPUTime.getNumberOfMeasurements() << " \t |  " << _measureSetupExperimentCPUTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentCPUTime.getValue()  << " \t |  " << _measureSetupExperimentCalendarTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentCalendarTime.getValue() << " \t |  " << _measureSetupExperimentCPUTime.toString() << " \t |  " << _measureSetupExperimentCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| PerformExplicitEulerTimeStep \t |  " << _measurePerformExplicitEulerTimeStepCPUTime.getNumberOfMeasurements() << " \t |  " << _measurePerformExplicitEulerTimeStepCPUTime.getAccumulatedValue() << " \t |  " << _measurePerformExplicitEulerTimeStepCPUTime.getValue()  << " \t |  " << _measurePerformExplicitEulerTimeStepCalendarTime.getAccumulatedValue() << " \t |  " << _measurePerformExplicitEulerTimeStepCalendarTime.getValue() << " \t |  " << _measurePerformExplicitEulerTimeStepCPUTime.toString() << " \t |  " << _measurePerformExplicitEulerTimeStepCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| PerformExplicitEulerTimeStepAndPlot \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCPUTime.getNumberOfMeasurements() << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCPUTime.getAccumulatedValue() << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCPUTime.getValue()  << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCalendarTime.getAccumulatedValue() << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCalendarTime.getValue() << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCPUTime.toString() << " \t |  " << _measurePerformExplicitEulerTimeStepAndPlotCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| Plot \t |  " << _measurePlotCPUTime.getNumberOfMeasurements() << " \t |  " << _measurePlotCPUTime.getAccumulatedValue() << " \t |  " << _measurePlotCPUTime.getValue()  << " \t |  " << _measurePlotCalendarTime.getAccumulatedValue() << " \t |  " << _measurePlotCalendarTime.getValue() << " \t |  " << _measurePlotCPUTime.toString() << " \t |  " << _measurePlotCalendarTime.toString() );

}


void rotatingheatsource::expliciteuler::repositories::RepositorySTDStack::clearIterationStatistics() {
   _measureSetupExperimentCPUTime.erase();
   _measurePerformExplicitEulerTimeStepCPUTime.erase();
   _measurePerformExplicitEulerTimeStepAndPlotCPUTime.erase();
   _measurePlotCPUTime.erase();

   _measureSetupExperimentCalendarTime.erase();
   _measurePerformExplicitEulerTimeStepCalendarTime.erase();
   _measurePerformExplicitEulerTimeStepAndPlotCalendarTime.erase();
   _measurePlotCalendarTime.erase();

}
