#include "rotatingheatsource/expliciteuler/mappings/PerformExplicitEulerTimeStep.h"
#include "rotatingheatsource/DiffusionEquationScenarioService.h"
#include "peano/grid/aspects/VertexStateAnalysis.h"
#include "rotatingheatsource/RotatingHeatSource.h"
#include "peano/utils/Globals.h"
// @todo Query
#include "queries/DummyQuery.h"
#include "queries/records/Answer.h"
#include "queries/records/AnswerConfiguration.h"
#include "peano/heap/Heap.h"



/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


tarch::logging::Log                rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::_log( "rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep" ); 


rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::PerformExplicitEulerTimeStep():
		  _solver(),
		  // @todo Query
		  _currentQuery(0) {

}


rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::~PerformExplicitEulerTimeStep() {
	logTraceIn( "~PerformExplicitEulerTimeStep()" );

	// @todo Query
	delete _currentQuery;

	logTraceOut( "~PerformExplicitEulerTimeStep()" );
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::PerformExplicitEulerTimeStep(const PerformExplicitEulerTimeStep&  masterThread):
		  _solver(masterThread._solver) {
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithWorkerThread(const PerformExplicitEulerTimeStep& workerThread) {
	_solver.mergeWithSolverFromOtherThread(workerThread._solver);
}
#endif


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
	logTraceInWith6Arguments( "createHangingVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

	fineGridVertex.initialiseHangingVertex(
			_multigrid.getDLinearInterpolatedValue(
					Vertex::readU(coarseGridVerticesEnumerator,coarseGridVertices),
					fineGridPositionOfVertex,
					1.0
			),
			_multigrid.getDLinearInterpolatedValue(
					Vertex::readRhs(coarseGridVerticesEnumerator,coarseGridVertices),
					fineGridPositionOfVertex,
					1.0/static_cast<double>(THREE_POWER_D)
			)
	);

	logTraceOutWith1Argument( "createHangingVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::destroyHangingVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "destroyHangingVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyHangingVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
	logTraceInWith6Arguments( "createInnerVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

	if ( peano::grid::aspects::VertexStateAnalysis::isOneCoarseGridVertexOutsideDomain(coarseGridVertices,coarseGridVerticesEnumerator)) {
		fineGridVertex.initialiseInnerVertex(
				rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getThermalDiffusivity(fineGridX),
				rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getInitialValue(fineGridX),
				rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getRhs(fineGridX),
				fineGridH
		);
	}
	else {
		fineGridVertex.initialiseInnerVertex(
				rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getThermalDiffusivity(fineGridX),
				_multigrid.getDLinearInterpolatedValue(
						Vertex::readU(coarseGridVerticesEnumerator,coarseGridVertices),
						fineGridPositionOfVertex,
						1.0
				),
				_multigrid.getDLinearInterpolatedValue(
						Vertex::readRhs(coarseGridVerticesEnumerator,coarseGridVertices),
						fineGridPositionOfVertex,
						1.0/static_cast<double>(THREE_POWER_D)
				),
				fineGridH
		);
	}

	logTraceOutWith1Argument( "createInnerVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
	logTraceInWith6Arguments( "createBoundaryVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

	fineGridVertex.initialiseBoundaryVertex(
			rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getRhs(fineGridX)
	);

	logTraceOutWith1Argument( "createBoundaryVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::destroyVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "destroyVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
	logTraceInWith4Arguments( "createCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
	// @todo Insert your code here
	logTraceOutWith1Argument( "createCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::destroyCell(
      const rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "destroyCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyCell(...)", fineGridCell );
}

#ifdef Parallel
void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
	logTraceInWith6Arguments( "mergeWithNeighbour(...)", vertex, neighbour, fromRank, fineGridX, fineGridH, level );

	//  if (vertex.isInside()) {
	//    assertionNumericalEquals4( vertex.getRhs(), neighbour.getRhs(), vertex, neighbour, fromRank, tarch::parallel::Node::getInstance().getRank() );
	//
	//    double neighbourResidual = neighbour.getResidual() /_solver.getTimeStepSize();
	//    vertex.setTemperature(
	//      _solver.getNewTemperatureForExplicitEulerStep( fineGridH, neighbourResidual, vertex.getTemperature() )
	//    );
	//  }
	//  else {
	//    assertionNumericalEquals4(
	//      vertex.getTemperature(),
	//      neighbour.getTemperature(),
	//      vertex, neighbour, fromRank, tarch::parallel::Node::getInstance().getRank()
	//    );
	//  }

	logTraceOut( "mergeWithNeighbour(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::prepareSendToNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
  logTraceInWith3Arguments( "prepareSendToNeighbour(...)", vertex, toRank, level );
  // @todo Insert your code here
  logTraceOut( "prepareSendToNeighbour(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localVertex, toRank, x, h, level );
  // @todo Insert your code here
  logTraceOut( "prepareCopyToRemoteNode(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localCell, toRank, cellCentre, cellSize, level );
  // @todo Insert your code here
  logTraceOut( "prepareCopyToRemoteNode(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
  logTraceInWith6Arguments( "mergeWithRemoteDataDueToForkOrJoin(...)", localVertex, masterOrWorkerVertex, fromRank, x, h, level );
  // @todo Insert your code here
  logTraceOut( "mergeWithRemoteDataDueToForkOrJoin(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Cell&  localCell,
  const rotatingheatsource::expliciteuler::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
  logTraceInWith3Arguments( "mergeWithRemoteDataDueToForkOrJoin(...)", localCell, masterOrWorkerCell, fromRank );
  // @todo Insert your code here
  logTraceOut( "mergeWithRemoteDataDueToForkOrJoin(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::prepareSendToWorker(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  logTraceIn( "prepareSendToWorker(...)" );
  // @todo Insert your code here
  logTraceOut( "prepareSendToWorker(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::prepareSendToMaster(
  rotatingheatsource::expliciteuler::Cell&                       localCell,
  rotatingheatsource::expliciteuler::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
	if(_currentQuery!=NULL
			&&_currentQuery->intersectsWithQuery(verticesEnumerator.getCellCenter(),verticesEnumerator.getCellSize()))
	{
		std::cout<<"sending on rank: "<<tarch::parallel::Node::getInstance().getRank()<<" heap:"<<_heapId<<" for "<<verticesEnumerator.getCellCenter()<<" to: "<<tarch::parallel::NodePool::getInstance().getMasterRank()<<"on level:"<<verticesEnumerator.getLevel()<<std::endl;
		//queries::records::Answer a;
		//peano::heap::Heap<queries::records::Answer>::getInstance().getData(localCell.getCellHeapId()).push_back(a);
		((queries::DummyQuery*)_currentQuery)->fillAnswers(peano::heap::Heap<queries::records::Answer>::getInstance().getData(_heapId));
		((queries::DummyQuery*)_currentQuery)->release(peano::heap::Heap<queries::records::Answer>::getInstance().getData(_heapId));

		peano::heap::Heap<queries::records::Answer>::getInstance().sendData(_heapId,tarch::parallel::NodePool::getInstance().getMasterRank(),verticesEnumerator.getCellCenter(),verticesEnumerator.getLevel(),peano::heap::MasterWorkerCommunication);
		peano::heap::Heap<queries::records::Answer>::getInstance().deleteData(_heapId);
	}
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithMaster(
  const rotatingheatsource::expliciteuler::Cell&           workerGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        workerGridVertices,
 const peano::grid::VertexEnumerator& workerEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker,
  const rotatingheatsource::expliciteuler::State&          workerState,
  rotatingheatsource::expliciteuler::State&                masterState
) {
	logTraceIn( "mergeWithMaster(...)" );

	assertionEquals2( masterState._stateData.getTimeStep(),     workerState.getTimeStep(),     masterState.toString(), workerState.toString() );
	assertionEquals2( masterState._stateData.getTimeStepSize(), workerState.getTimeStepSize(), masterState.toString(), workerState.toString() );
	assertionEquals2( masterState._stateData.getTime(),         workerState.getTime(),         masterState.toString(), workerState.toString() );

	if (masterState._stateData.getUpdateUH()<workerState._stateData.getUpdateUH()) {
		masterState._stateData.setUpdateUH( workerState._stateData.getUpdateUH() );
	}
	if (masterState._stateData.getUpdateUMax()<workerState._stateData.getUpdateUMax()) {
		masterState._stateData.setUpdateUMax( workerState._stateData.getUpdateUMax() );
	}
	if (masterState._stateData.getUH()<workerState._stateData.getUH()) {
		masterState._stateData.setUH( workerState._stateData.getUH() );
	}
	if (masterState._stateData.getUMax()<workerState._stateData.getUMax()) {
		masterState._stateData.setUMax( workerState._stateData.getUMax() );
	}

	//bool mergeQuery = false;
	if(_currentQuery!=NULL&&_currentQuery->intersectsWithQuery(fineGridVerticesEnumerator.getCellCenter(),fineGridVerticesEnumerator.getCellSize()))
	{
		std::cout<<"merging on rank: "<<tarch::parallel::Node::getInstance().getRank()<<" for "<<fineGridVerticesEnumerator.getCellCenter()<<"with:"<<worker <<" on level:"<<fineGridVerticesEnumerator.getLevel()<<std::endl;

		std::vector<queries::records::Answer>&  masterAnswer = peano::heap::Heap<queries::records::Answer>::getInstance().getData(_heapId);
		std::vector<queries::records::Answer>  workerAnswer = peano::heap::Heap<queries::records::Answer>::getInstance().receiveData(worker, fineGridVerticesEnumerator.getCellCenter(),fineGridVerticesEnumerator.getLevel(), peano::heap::MasterWorkerCommunication);
		mergeAnswer(masterAnswer,workerAnswer);

		//if(coarseGridCell.isInside()){
				std::cout<<"write answer"<<std::endl;
				//std::vector<queries::records::Answer>&  masterAnswer = peano::heap::Heap<queries::records::Answer>::getInstance().getData(coarseGridCell.getCellHeapId());

		//	}
	}

	masterState._stateData.setNumberOfStencilUpdates( masterState._stateData.getNumberOfStencilUpdates() + workerState._stateData.getNumberOfStencilUpdates() );

	logTraceOut( "mergeWithMaster(...)" );
}

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeAnswer(std::vector<queries::records::Answer>& masterAnswer,std::vector<queries::records::Answer> workerAnswer){
	if(masterAnswer.size()==0)
	{
		masterAnswer= workerAnswer;
	}else{
		std::unordered_map<int,int> masterAnswerMap;
		for(unsigned int i=0;i<masterAnswer.size();i++)
			masterAnswerMap[masterAnswer[i].getDataIndex()]=i;
		for (unsigned int i=0;i<workerAnswer.size();i++){
			if(masterAnswerMap.find(workerAnswer[i].getDataIndex())!=masterAnswerMap.end()){
				if(masterAnswer[masterAnswerMap[workerAnswer[i].getDataIndex()]].getPosition()>workerAnswer[i].getPosition()){
					masterAnswer[masterAnswerMap[workerAnswer[i].getDataIndex()]].setData(workerAnswer[i].getData());
					masterAnswer[masterAnswerMap[workerAnswer[i].getDataIndex()]].setPosition(workerAnswer[i].getPosition());

				}
			}else{

				masterAnswer.push_back(workerAnswer[i]);
				masterAnswerMap[workerAnswer[i].getDataIndex()]=masterAnswer.size()-1;
			}
		}
	}
}
void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::receiveDataFromMaster(
      rotatingheatsource::expliciteuler::Cell&                        receivedCell, 
      rotatingheatsource::expliciteuler::Vertex *                     receivedVertices,
      const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const               receivedCoarseGridVertices,
      const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                        receivedCoarseGridCell,
      rotatingheatsource::expliciteuler::Vertex * const               workersCoarseGridVertices,
      const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                        workersCoarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
  logTraceIn( "receiveDataFromMaster(...)" );
  // @todo Insert your code here
  logTraceOut( "receiveDataFromMaster(...)" );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithWorker(
  rotatingheatsource::expliciteuler::Cell&           localCell, 
  const rotatingheatsource::expliciteuler::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localCell.toString(), receivedMasterCell.toString() );
  // @todo Insert your code here
  logTraceOutWith1Argument( "mergeWithWorker(...)", localCell.toString() );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::mergeWithWorker(
  rotatingheatsource::expliciteuler::Vertex&        localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localVertex.toString(), receivedMasterVertex.toString() );
  // @todo Insert your code here
  logTraceOutWith1Argument( "mergeWithWorker(...)", localVertex.toString() );
}
#endif

void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
	logTraceInWith6Arguments( "touchVertexFirstTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

	fineGridVertex.clearResidual();

	logTraceOutWith1Argument( "touchVertexFirstTime(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
	logTraceInWith6Arguments( "touchVertexLastTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );


	if (fineGridVertex.isInside() && fineGridVertex.getRefinementControl()!=Vertex::Records::Refined) {
		fineGridVertex.setTemperature(
				_solver.getNewTemperatureForExplicitEulerStep( fineGridH, fineGridVertex.getResidual(), fineGridVertex.getTemperature() )
		);
		const double newRhs = rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getRhs(fineGridX);
		fineGridVertex.setNewRhs(newRhs);
	}

	// @todo Query


	logTraceOutWith1Argument( "touchVertexLastTime(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::enterCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {



  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
	logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

	tarch::la::Vector<TWO_POWER_D,double> rhs;
	tarch::la::Vector<TWO_POWER_D,double> u;

	rhs = Vertex::readRhs(fineGridVerticesEnumerator,fineGridVertices);
	u   = Vertex::readU(fineGridVerticesEnumerator,fineGridVertices);

	Vertex::writeResidual(
			fineGridVerticesEnumerator,
			fineGridVertices,
			Vertex::readResidual(fineGridVerticesEnumerator,fineGridVertices) +
			_solver.computeResidualContributionForExplicitEulerStep(
					rhs,u,
					fineGridVerticesEnumerator.getCellSize(),
					Vertex::readStencil(fineGridVerticesEnumerator,fineGridVertices)
			)
	);


	if(fineGridCell.isLeaf()){
		  dfor2(x)
			    if (
						_currentQuery->getScope()==0 &&
						_currentQuery->intersectsWithQuery(fineGridVerticesEnumerator.getVertexPosition(x)-fineGridVerticesEnumerator.getCellSize()/2.0,fineGridVerticesEnumerator.getCellSize())

			  ) {

					_currentQuery->setData(
							fineGridVerticesEnumerator.getVertexPosition(x),
							fineGridVerticesEnumerator.getCellSize(),
							fineGridVertices[fineGridVerticesEnumerator(x)].getTemperature());
			  }

		  enddforx
	}
	  //if(fineGridCell.isLeaf()){
		  //std::cout<<"rank:"<<tarch::parallel::Node::getInstance().getRank()<<" filling heap:"<<fineGridCell.getCellHeapId()<<std::endl;


	  //}

	logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
	logTraceInWith1Argument( "beginIteration(State)", solverState );

	rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().setTime( solverState.getTime() );
	_solver.setTimeStepSize(solverState.getTimeStepSize());
	_solver.clearMeasurements();
	tarch::la::Vector<DIMENSIONS,int> dim;
	for(int i=0;i<DIMENSIONS;i++){
		dim[i]=17;

	}
	// @todo Query
	rotatingheatsource::RotatingHeatSource scenario=(rotatingheatsource::RotatingHeatSource&)(rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario());

	//_currentQuery = new queries::vtkClientQuery(scenario.getStimulusCenter()-scenario.getStimulusRadius(),2.0*scenario.getStimulusRadius(),dim,0,scenario.getTime());
	_heapId=peano::heap::Heap<queries::records::Answer>::getInstance().createData();
	logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
	logTraceInWith1Argument( "endIteration(State)", solverState );

	solverState.setUMeasurements(
			_solver.getSolutionInMaximumNorm(),
			_solver.getSolutionUpdateInMaximumNorm(),
			_solver.getSolutionInHNorm(),
			_solver.getSolutionUpdateInHNorm()
	);
	solverState.incNumberOfStencilUpdates( _solver.getNumberOfStencilUpdates() );
	//if(_currentQuery!=NULL){
	// @todo Query
		//_currentQuery->release();
		//delete _currentQuery;
		//_currentQuery=NULL;
	//}
	logTraceOutWith1Argument( "endIteration(State)", solverState);
}



void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::descend(
  rotatingheatsource::expliciteuler::Cell * const          fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell
) {
  logTraceInWith2Arguments( "descend(...)", coarseGridCell.toString(), coarseGridVerticesEnumerator.toString() );
  // @todo Insert your code here
  logTraceOut( "descend(...)" );
}


void rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::ascend(
  rotatingheatsource::expliciteuler::Cell * const    fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&           coarseGridCell
) {
  logTraceInWith2Arguments( "ascend(...)", coarseGridCell.toString(), coarseGridVerticesEnumerator.toString() );
  // @todo Insert your code here
  logTraceOut( "ascend(...)" );
}
