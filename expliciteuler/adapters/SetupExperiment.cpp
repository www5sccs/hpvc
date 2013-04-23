#include "rotatingheatsource/expliciteuler/adapters/SetupExperiment.h"



peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::touchVertexLastTimeSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::touchVertexFirstTimeSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::enterCellSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::enterCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::leaveCellSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::leaveCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::ascendSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::ascendSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::SetupExperiment::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & rotatingheatsource::expliciteuler::mappings::SetupExperiment::descendSpecification()

   & rotatingheatsource::expliciteuler::adapters::SetupExperiment2VTKGridVisualiser_0::descendSpecification()

;
}


rotatingheatsource::expliciteuler::adapters::SetupExperiment::SetupExperiment() {
}


rotatingheatsource::expliciteuler::adapters::SetupExperiment::~SetupExperiment() {
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::adapters::SetupExperiment::SetupExperiment(const SetupExperiment&  masterThread):
  _map2SetupExperiment(masterThread._map2SetupExperiment) 

 ,
  _map2SetupExperiment2VTKGridVisualiser_0(masterThread._map2SetupExperiment2VTKGridVisualiser_0) 

{
}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithWorkerThread(const SetupExperiment& workerThread) {

  _map2SetupExperiment.mergeWithWorkerThread(workerThread._map2SetupExperiment);

  _map2SetupExperiment2VTKGridVisualiser_0.mergeWithWorkerThread(workerThread._map2SetupExperiment2VTKGridVisualiser_0);

}
#endif


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {

  _map2SetupExperiment.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::destroyHangingVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2SetupExperiment.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2SetupExperiment.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2SetupExperiment.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::destroyVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2SetupExperiment.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2SetupExperiment.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperiment2VTKGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::destroyCell(
      const rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2SetupExperiment.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperiment2VTKGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {

   _map2SetupExperiment.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::prepareSendToNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2SetupExperiment.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2SetupExperiment.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {

   _map2SetupExperiment.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {

   _map2SetupExperiment.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Cell&  localCell,
  const rotatingheatsource::expliciteuler::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {

   _map2SetupExperiment.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::prepareSendToWorker(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {

   _map2SetupExperiment.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   _map2SetupExperiment2VTKGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::prepareSendToMaster(
  rotatingheatsource::expliciteuler::Cell&                       localCell,
  rotatingheatsource::expliciteuler::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2SetupExperiment.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2SetupExperiment2VTKGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithMaster(
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

   _map2SetupExperiment.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::receiveDataFromMaster(
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

   _map2SetupExperiment.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

   _map2SetupExperiment2VTKGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithWorker(
  rotatingheatsource::expliciteuler::Cell&           localCell, 
  const rotatingheatsource::expliciteuler::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {

   _map2SetupExperiment.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::mergeWithWorker(
  rotatingheatsource::expliciteuler::Vertex&        localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2SetupExperiment.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2SetupExperiment2VTKGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void rotatingheatsource::expliciteuler::adapters::SetupExperiment::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {

  _map2SetupExperiment.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2SetupExperiment.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperiment2VTKGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::enterCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2SetupExperiment.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperiment2VTKGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2SetupExperiment.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperiment2VTKGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {

  _map2SetupExperiment.beginIteration( solverState );

  _map2SetupExperiment2VTKGridVisualiser_0.beginIteration( solverState );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {

  _map2SetupExperiment.endIteration( solverState );

  _map2SetupExperiment2VTKGridVisualiser_0.endIteration( solverState );

}




void rotatingheatsource::expliciteuler::adapters::SetupExperiment::descend(
  rotatingheatsource::expliciteuler::Cell * const          fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell
) {

  _map2SetupExperiment.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2SetupExperiment2VTKGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void rotatingheatsource::expliciteuler::adapters::SetupExperiment::ascend(
  rotatingheatsource::expliciteuler::Cell * const    fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&           coarseGridCell
) {

  _map2SetupExperiment.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2SetupExperiment2VTKGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
