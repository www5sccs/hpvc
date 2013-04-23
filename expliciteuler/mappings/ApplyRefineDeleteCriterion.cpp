#include "rotatingheatsource/expliciteuler/mappings/ApplyRefineDeleteCriterion.h"
#include "rotatingheatsource/DiffusionEquationScenarioService.h"


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


/**
 * @todo Please tailor the parameters to your mapping's properties.
 */
peano::MappingSpecification   rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


tarch::logging::Log                rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::_log( "rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion" ); 


rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::ApplyRefineDeleteCriterion():
  _surplusCalculator(
    0.1,0.1,
    tarch::la::min( rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getMinimalMeshSize() ),
    tarch::la::max( rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getMaximalMeshSize() )
  ),
  _globalMaxU(0.0) {
}


rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::~ApplyRefineDeleteCriterion() {
  logTraceIn( "~ApplyRefineDeleteCriterion()" );
  // @todo Insert your code here
  logTraceOut( "~ApplyRefineDeleteCriterion()" );
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::ApplyRefineDeleteCriterion(const ApplyRefineDeleteCriterion&  masterThread):
  _surplusCalculator(masterThread._surplusCalculator),
  _globalMaxU(0.0) {
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithWorkerThread(const ApplyRefineDeleteCriterion& workerThread) {
  _globalMaxU = _globalMaxU > workerThread._globalMaxU ? _globalMaxU : workerThread._globalMaxU;

  _surplusCalculator.mergeWithSurplusCalculatorFromOtherThread( workerThread._surplusCalculator );
}
#endif


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createHangingVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createHangingVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::destroyHangingVertex(
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


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createInnerVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createInnerVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createBoundaryVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createBoundaryVertex(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::destroyVertex(
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


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "createCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
  logTraceOutWith1Argument( "createCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::destroyCell(
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
void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
  logTraceInWith6Arguments( "mergeWithNeighbour(...)", vertex, neighbour, fromRank, fineGridX, fineGridH, level );
  // @todo Insert your code here
  logTraceOut( "mergeWithNeighbour(...)" );
}

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::prepareSendToNeighbour(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::prepareCopyToRemoteNode(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::prepareCopyToRemoteNode(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithRemoteDataDueToForkOrJoin(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithRemoteDataDueToForkOrJoin(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::prepareSendToWorker(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::prepareSendToMaster(
  rotatingheatsource::expliciteuler::Cell&                       localCell,
  rotatingheatsource::expliciteuler::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceInWith2Arguments( "prepareSendToMaster(...)", localCell, verticesEnumerator.toString() );
  // @todo Insert your code here
  logTraceOut( "prepareSendToMaster(...)" );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithMaster(
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
  // @todo Insert your code here
  logTraceOut( "mergeWithMaster(...)" );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::receiveDataFromMaster(
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


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithWorker(
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


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::mergeWithWorker(
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

void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexFirstTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );


  fineGridVertex.clearSurplusMeasurements();

  logTraceOutWith1Argument( "touchVertexFirstTime(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexLastTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  assertion( !fineGridVertex.isHangingNode() );

  if ( fineGridVertex.isInside() ) {
    switch (
      _surplusCalculator.analyse(
        fineGridVertex.getLinearSurplus(),
        fineGridVertex.getRefinementControl()==Vertex::Records::Refined,
        fineGridVertex.getRefinementControl()==Vertex::Records::Unrefined,
        fineGridH
      )
    ) {
      case matrixfree::solver::SurplusCalculator::Delete:
        fineGridVertex.erase();
        break;
      case matrixfree::solver::SurplusCalculator::Refine:
        fineGridVertex.refine();
        break;
      case matrixfree::solver::SurplusCalculator::NoAction:
        break;
    }
  }
  // boundary block
  else if (
    fineGridVertex.getRefinementControl()==Vertex::Records::Unrefined &&
    fineGridH(0) > _surplusCalculator.getMaximumMeshWidth()
  ) {
    fineGridVertex.refine();
  }

  // project up to coarser level
  if ( fineGridVertex.isInside() ) {
    Vertex::writeLinearSurplus(
      coarseGridVerticesEnumerator,
      coarseGridVertices,
      Vertex::readLinearSurplus(
        coarseGridVerticesEnumerator,
        coarseGridVertices
      ) +
      _surplusCalculator.getLinearSurplusContributionFromFineGrid(
        fineGridVertex.getLinearSurplus(),
        fineGridVertex.getRefinementControl()==Vertex::Records::Unrefined
      )
    );
  }

  logTraceOutWith1Argument( "touchVertexLastTime(...)", fineGridVertex );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::enterCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );


  Vertex::writeLinearSurplus(
    fineGridVerticesEnumerator,
    fineGridVertices,
    _surplusCalculator.getNewLinearSurplus(
      Vertex::readU(fineGridVerticesEnumerator,fineGridVertices),
      Vertex::readLinearSurplus(fineGridVerticesEnumerator,fineGridVertices)
    )
  );
  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "leaveCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
  // @todo Insert your code here
  logTraceOutWith1Argument( "leaveCell(...)", fineGridCell );
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );


  _globalMaxU = _globalMaxU>solverState.getUInMaxNorm() ? _globalMaxU : solverState.getUInMaxNorm();

  _surplusCalculator.setMinMaxMeshWidth(
    tarch::la::min(
      rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getMinimalMeshSize()
    ),
    tarch::la::max(
      rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getMaximalMeshSize()
    )
  );

  _surplusCalculator.clearMeasurements(
    tarch::la::min( rotatingheatsource::DiffusionEquationScenarioService::getInstance().getScenario().getMaximalMeshSize() )
    *
    _globalMaxU
  );

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
  logTraceInWith1Argument( "endIteration(State)", solverState );
  // @todo Insert your code here
  logTraceOutWith1Argument( "endIteration(State)", solverState);
}



void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::descend(
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


void rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::ascend(
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
