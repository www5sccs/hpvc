#include "rotatingheatsource/expliciteuler/adapters/PerformExplicitEulerTimeStepAndPlot.h"



peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexLastTimeSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::touchVertexLastTimeSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexLastTimeSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::touchVertexLastTimeSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::touchVertexFirstTimeSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::touchVertexFirstTimeSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::touchVertexFirstTimeSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::touchVertexFirstTimeSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::enterCellSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::enterCellSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::enterCellSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::enterCellSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::enterCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::leaveCellSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::leaveCellSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::leaveCellSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::leaveCellSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::leaveCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::ascendSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::ascendSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::ascendSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::ascendSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::ascendSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::PerformExplicitEulerTimeStep::descendSpecification()
   & rotatingheatsource::expliciteuler::mappings::CoarseSolution::descendSpecification()
   & rotatingheatsource::expliciteuler::mappings::ApplyRefineDeleteCriterion::descendSpecification()

   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0::descendSpecification()
   & rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::descendSpecification()

;
}


rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::PerformExplicitEulerTimeStepAndPlot() {
}


rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::~PerformExplicitEulerTimeStepAndPlot() {
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::PerformExplicitEulerTimeStepAndPlot(const PerformExplicitEulerTimeStepAndPlot&  masterThread):
  _map2PerformExplicitEulerTimeStep(masterThread._map2PerformExplicitEulerTimeStep) , 
  _map2CoarseSolution(masterThread._map2CoarseSolution) , 
  _map2ApplyRefineDeleteCriterion(masterThread._map2ApplyRefineDeleteCriterion) 

 ,
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0(masterThread._map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0) , 
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1(masterThread._map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1) 

{
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithWorkerThread(const PerformExplicitEulerTimeStepAndPlot& workerThread) {

  _map2PerformExplicitEulerTimeStep.mergeWithWorkerThread(workerThread._map2PerformExplicitEulerTimeStep);
  _map2CoarseSolution.mergeWithWorkerThread(workerThread._map2CoarseSolution);
  _map2ApplyRefineDeleteCriterion.mergeWithWorkerThread(workerThread._map2ApplyRefineDeleteCriterion);

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithWorkerThread(workerThread._map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0);
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithWorkerThread(workerThread._map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1);

}
#endif


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::destroyHangingVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::destroyVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2PerformExplicitEulerTimeStep.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2CoarseSolution.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2ApplyRefineDeleteCriterion.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::destroyCell(
      const rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2PerformExplicitEulerTimeStep.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2CoarseSolution.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2ApplyRefineDeleteCriterion.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {

   _map2PerformExplicitEulerTimeStep.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2CoarseSolution.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2ApplyRefineDeleteCriterion.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::prepareSendToNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2PerformExplicitEulerTimeStep.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2CoarseSolution.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2ApplyRefineDeleteCriterion.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2PerformExplicitEulerTimeStep.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2CoarseSolution.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2ApplyRefineDeleteCriterion.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {

   _map2PerformExplicitEulerTimeStep.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2CoarseSolution.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2ApplyRefineDeleteCriterion.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {

   _map2PerformExplicitEulerTimeStep.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2CoarseSolution.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2ApplyRefineDeleteCriterion.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Cell&  localCell,
  const rotatingheatsource::expliciteuler::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {

   _map2PerformExplicitEulerTimeStep.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2CoarseSolution.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2ApplyRefineDeleteCriterion.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::prepareSendToWorker(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {

   _map2PerformExplicitEulerTimeStep.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   _map2CoarseSolution.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   _map2ApplyRefineDeleteCriterion.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::prepareSendToMaster(
  rotatingheatsource::expliciteuler::Cell&                       localCell,
  rotatingheatsource::expliciteuler::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2PerformExplicitEulerTimeStep.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2CoarseSolution.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2ApplyRefineDeleteCriterion.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithMaster(
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

   _map2PerformExplicitEulerTimeStep.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2CoarseSolution.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2ApplyRefineDeleteCriterion.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::receiveDataFromMaster(
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

   _map2PerformExplicitEulerTimeStep.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2CoarseSolution.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2ApplyRefineDeleteCriterion.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithWorker(
  rotatingheatsource::expliciteuler::Cell&           localCell, 
  const rotatingheatsource::expliciteuler::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {

   _map2PerformExplicitEulerTimeStep.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2CoarseSolution.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2ApplyRefineDeleteCriterion.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::mergeWithWorker(
  rotatingheatsource::expliciteuler::Vertex&        localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2PerformExplicitEulerTimeStep.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2CoarseSolution.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2ApplyRefineDeleteCriterion.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2PerformExplicitEulerTimeStep.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2CoarseSolution.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2ApplyRefineDeleteCriterion.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::enterCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2PerformExplicitEulerTimeStep.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2CoarseSolution.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2ApplyRefineDeleteCriterion.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2PerformExplicitEulerTimeStep.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2CoarseSolution.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2ApplyRefineDeleteCriterion.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {

  _map2PerformExplicitEulerTimeStep.beginIteration( solverState );
  _map2CoarseSolution.beginIteration( solverState );
  _map2ApplyRefineDeleteCriterion.beginIteration( solverState );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.beginIteration( solverState );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.beginIteration( solverState );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {

  _map2PerformExplicitEulerTimeStep.endIteration( solverState );
  _map2CoarseSolution.endIteration( solverState );
  _map2ApplyRefineDeleteCriterion.endIteration( solverState );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.endIteration( solverState );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.endIteration( solverState );

}




void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::descend(
  rotatingheatsource::expliciteuler::Cell * const          fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell
) {

  _map2PerformExplicitEulerTimeStep.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2CoarseSolution.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2ApplyRefineDeleteCriterion.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot::ascend(
  rotatingheatsource::expliciteuler::Cell * const    fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&           coarseGridCell
) {

  _map2PerformExplicitEulerTimeStep.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2CoarseSolution.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2ApplyRefineDeleteCriterion.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
