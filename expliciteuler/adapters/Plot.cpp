#include "rotatingheatsource/expliciteuler/adapters/Plot.h"



peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::touchVertexLastTimeSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::touchVertexFirstTimeSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::enterCellSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::enterCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::leaveCellSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::leaveCellSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::ascendSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::ascendSpecification()

;
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::Plot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()

   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_0::descendSpecification()
   & rotatingheatsource::expliciteuler::adapters::Plot2VTKPlotVertexValue_1::descendSpecification()

;
}


rotatingheatsource::expliciteuler::adapters::Plot::Plot() {
}


rotatingheatsource::expliciteuler::adapters::Plot::~Plot() {
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::adapters::Plot::Plot(const Plot&  masterThread):

 
  _map2Plot2VTKPlotVertexValue_0(masterThread._map2Plot2VTKPlotVertexValue_0) , 
  _map2Plot2VTKPlotVertexValue_1(masterThread._map2Plot2VTKPlotVertexValue_1) 

{
}


void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithWorkerThread(const Plot& workerThread) {


  _map2Plot2VTKPlotVertexValue_0.mergeWithWorkerThread(workerThread._map2Plot2VTKPlotVertexValue_0);
  _map2Plot2VTKPlotVertexValue_1.mergeWithWorkerThread(workerThread._map2Plot2VTKPlotVertexValue_1);

}
#endif


void rotatingheatsource::expliciteuler::adapters::Plot::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::destroyHangingVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::destroyVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {


  _map2Plot2VTKPlotVertexValue_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Plot2VTKPlotVertexValue_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::Plot::destroyCell(
      const rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {


  _map2Plot2VTKPlotVertexValue_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Plot2VTKPlotVertexValue_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {


   _map2Plot2VTKPlotVertexValue_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2Plot2VTKPlotVertexValue_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::prepareSendToNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {


   _map2Plot2VTKPlotVertexValue_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {


   _map2Plot2VTKPlotVertexValue_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::prepareCopyToRemoteNode(
  rotatingheatsource::expliciteuler::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {


   _map2Plot2VTKPlotVertexValue_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {


   _map2Plot2VTKPlotVertexValue_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Cell&  localCell,
  const rotatingheatsource::expliciteuler::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {


   _map2Plot2VTKPlotVertexValue_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::prepareSendToWorker(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {


   _map2Plot2VTKPlotVertexValue_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   _map2Plot2VTKPlotVertexValue_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

}

void rotatingheatsource::expliciteuler::adapters::Plot::prepareSendToMaster(
  rotatingheatsource::expliciteuler::Cell&                       localCell,
  rotatingheatsource::expliciteuler::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {


   _map2Plot2VTKPlotVertexValue_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2Plot2VTKPlotVertexValue_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithMaster(
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


   _map2Plot2VTKPlotVertexValue_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2Plot2VTKPlotVertexValue_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void rotatingheatsource::expliciteuler::adapters::Plot::receiveDataFromMaster(
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


   _map2Plot2VTKPlotVertexValue_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2Plot2VTKPlotVertexValue_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithWorker(
  rotatingheatsource::expliciteuler::Cell&           localCell, 
  const rotatingheatsource::expliciteuler::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {


   _map2Plot2VTKPlotVertexValue_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2Plot2VTKPlotVertexValue_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void rotatingheatsource::expliciteuler::adapters::Plot::mergeWithWorker(
  rotatingheatsource::expliciteuler::Vertex&        localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {


   _map2Plot2VTKPlotVertexValue_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2Plot2VTKPlotVertexValue_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void rotatingheatsource::expliciteuler::adapters::Plot::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {


  _map2Plot2VTKPlotVertexValue_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Plot2VTKPlotVertexValue_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void rotatingheatsource::expliciteuler::adapters::Plot::enterCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {


  _map2Plot2VTKPlotVertexValue_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Plot2VTKPlotVertexValue_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::Plot::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {


  _map2Plot2VTKPlotVertexValue_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Plot2VTKPlotVertexValue_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void rotatingheatsource::expliciteuler::adapters::Plot::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {


  _map2Plot2VTKPlotVertexValue_0.beginIteration( solverState );
  _map2Plot2VTKPlotVertexValue_1.beginIteration( solverState );

}


void rotatingheatsource::expliciteuler::adapters::Plot::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {


  _map2Plot2VTKPlotVertexValue_0.endIteration( solverState );
  _map2Plot2VTKPlotVertexValue_1.endIteration( solverState );

}




void rotatingheatsource::expliciteuler::adapters::Plot::descend(
  rotatingheatsource::expliciteuler::Cell * const          fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell
) {


  _map2Plot2VTKPlotVertexValue_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Plot2VTKPlotVertexValue_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void rotatingheatsource::expliciteuler::adapters::Plot::ascend(
  rotatingheatsource::expliciteuler::Cell * const    fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&           coarseGridCell
) {


  _map2Plot2VTKPlotVertexValue_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Plot2VTKPlotVertexValue_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
