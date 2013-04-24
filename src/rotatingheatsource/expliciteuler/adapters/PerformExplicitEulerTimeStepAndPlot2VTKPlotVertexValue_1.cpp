#include "rotatingheatsource/expliciteuler/adapters/PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1.h"

#include <sstream>

#include "peano/utils/Loop.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#endif


int rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::_snapshotCounter = 0;


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


std::map<tarch::la::Vector<DIMENSIONS,double> , int, tarch::la::VectorCompare<DIMENSIONS> >  rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::_vertex2IndexMap;


rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1():
  _vtkWriter(0),
  _vertexWriter(0),
  _cellWriter(0),
  _vertexValueWriter(0) {
}


rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::~PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1() {
}


#if defined(SharedMemoryParallelisation)
rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1(const PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1&  masterThread):
  _vtkWriter(masterThread._vtkWriter),
  _vertexWriter(masterThread._vertexWriter),
  _cellWriter(masterThread._cellWriter),
  _vertexValueWriter(masterThread._vertexValueWriter) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithWorkerThread(const PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1& workerThread) {
}
#endif





void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::plotVertex(
  const rotatingheatsource::expliciteuler::Vertex&                 fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX
) {
  if ( 
    fineGridVertex.getRefinementControl() != rotatingheatsource::expliciteuler::Vertex::Records::Refined &&
    fineGridVertex.getRefinementControl() != rotatingheatsource::expliciteuler::Vertex::Records::Refining &&
    _vertex2IndexMap.find(fineGridX) == _vertex2IndexMap.end() 
  ) {  
    #if defined(Dim2) || defined(Dim3)
    _vertex2IndexMap[fineGridX] = _vertexWriter->plotVertex(fineGridX);
    #else
    _vertex2IndexMap[fineGridX] = _vertexWriter->plotVertex(tarch::la::Vector<3,double>(fineGridX.data()));
    #endif
    _vertexValueWriter->plotVertex             (_vertex2IndexMap[fineGridX],fineGridVertex.getRhs() );
  }
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::createHangingVertex(
      rotatingheatsource::expliciteuler::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX ); 
}



void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::destroyHangingVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::createInnerVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::createBoundaryVertex(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::destroyVertex(
      const rotatingheatsource::expliciteuler::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::createCell(
      rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::destroyCell(
      const rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


#ifdef Parallel
void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithNeighbour(
  rotatingheatsource::expliciteuler::Vertex&  vertex,
  const rotatingheatsource::expliciteuler::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::prepareSendToNeighbour(
      rotatingheatsource::expliciteuler::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::prepareCopyToRemoteNode(
      rotatingheatsource::expliciteuler::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::prepareCopyToRemoteNode(
      rotatingheatsource::expliciteuler::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Vertex&  localVertex,
  const rotatingheatsource::expliciteuler::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithRemoteDataDueToForkOrJoin(
  rotatingheatsource::expliciteuler::Cell&  localCell,
  const rotatingheatsource::expliciteuler::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::prepareSendToWorker(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::prepareSendToMaster(
      rotatingheatsource::expliciteuler::Cell&                       localCell,
      rotatingheatsource::expliciteuler::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithMaster(
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
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::receiveDataFromMaster(
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
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithWorker(
      rotatingheatsource::expliciteuler::Cell&           localCell, 
      const rotatingheatsource::expliciteuler::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::mergeWithWorker(
      rotatingheatsource::expliciteuler::Vertex&        localVertex,
      const rotatingheatsource::expliciteuler::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}
#endif


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexFirstTime(
      rotatingheatsource::expliciteuler::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX ); 
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::touchVertexLastTime(
      rotatingheatsource::expliciteuler::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::enterCell(
  rotatingheatsource::expliciteuler::Cell&                 fineGridCell,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&            fineGridPositionOfCell
) {
  #ifdef Parallel
  if (fineGridCell.isLeaf() && !fineGridCell.isAssignedToRemoteRank()) {
  #else
  if (fineGridCell.isLeaf()) {
  #endif
    assertion( DIMENSIONS==2 || DIMENSIONS==3 );
    int vertexIndex[TWO_POWER_D];
     dfor2(i)
      tarch::la::Vector<DIMENSIONS,double> currentVertexPosition = fineGridVerticesEnumerator.getVertexPosition(i);
      assertion4 ( 
        _vertex2IndexMap.find(currentVertexPosition) != _vertex2IndexMap.end(), 
        currentVertexPosition, 
        fineGridCell.toString(),
        fineGridVerticesEnumerator.toString(),
        fineGridVertices[ fineGridVerticesEnumerator(i) ].toString()
      );
      vertexIndex[iScalar] = _vertex2IndexMap[currentVertexPosition];
    enddforx
  
    if (DIMENSIONS==2) {
      _cellWriter->plotQuadrangle(vertexIndex);
    }
    if (DIMENSIONS==3) {
      _cellWriter->plotHexahedron(vertexIndex);
    }
  }
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::leaveCell(
      rotatingheatsource::expliciteuler::Cell&           fineGridCell,
      rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      rotatingheatsource::expliciteuler::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::beginIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
  assertion( _vtkWriter==0 );
  
  _vtkWriter = new tarch::plotter::griddata::unstructured::vtk::VTKTextFileWriter();
  
  _vertexWriter     = _vtkWriter->createVertexWriter();
  _cellWriter       = _vtkWriter->createCellWriter();
  
  _vertexValueWriter               = _vtkWriter->createVertexDataWriter("rhs",1);
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::endIteration(
  rotatingheatsource::expliciteuler::State&  solverState
) {
  _vertexWriter->close();
  _cellWriter->close();
  _vertexValueWriter->close();
  
  delete _vertexWriter;
  delete _cellWriter;
  delete _vertexValueWriter;
  
  _vertexWriter                  = 0;
  _cellWriter                    = 0;
  _vertexValueWriter             = 0;
  
  std::ostringstream snapshotFileName;
  snapshotFileName << "rhs"
                   #ifdef Parallel
                   << "-rank-" << tarch::parallel::Node::getInstance().getRank()
                   #endif
                   << "-" << _snapshotCounter
                   << ".vtk";
  _vtkWriter->writeToFile( snapshotFileName.str() );
  
  _snapshotCounter++;                  
  
  _vertex2IndexMap.clear();
  
  delete _vtkWriter;
  _vtkWriter = 0;
}




void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::descend(
  rotatingheatsource::expliciteuler::Cell * const          fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&                 coarseGridCell
) {
}


void rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot2VTKPlotVertexValue_1::ascend(
  rotatingheatsource::expliciteuler::Cell * const    fineGridCells,
  rotatingheatsource::expliciteuler::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  rotatingheatsource::expliciteuler::Cell&           coarseGridCell
) {
}
