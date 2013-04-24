#include "rotatingheatsource/expliciteuler/repositories/RepositoryFactory.h"

#include "rotatingheatsource/expliciteuler/repositories/RepositoryArrayStack.h"
#include "rotatingheatsource/expliciteuler/repositories/RepositorySTDStack.h"

#include "rotatingheatsource/expliciteuler/records/RepositoryState.h"

#ifdef Parallel
#include "tarch/parallel/NodePool.h"
#include "peano/parallel/Partitioner.h"
#endif


rotatingheatsource::expliciteuler::repositories::RepositoryFactory::RepositoryFactory() {
  #ifdef Parallel
  peano::parallel::Partitioner::initDatatypes();

  rotatingheatsource::expliciteuler::State::initDatatype();
  rotatingheatsource::expliciteuler::Vertex::initDatatype();
  rotatingheatsource::expliciteuler::Cell::initDatatype();

  if (rotatingheatsource::expliciteuler::records::RepositoryState::Datatype==0) {
    rotatingheatsource::expliciteuler::records::RepositoryState::initDatatype();
  }
  #endif
}


rotatingheatsource::expliciteuler::repositories::RepositoryFactory::~RepositoryFactory() {
}


void rotatingheatsource::expliciteuler::repositories::RepositoryFactory::shutdownAllParallelDatatypes() {
  #ifdef Parallel
  peano::parallel::Partitioner::shutdownDatatypes();

  rotatingheatsource::expliciteuler::State::shutdownDatatype();
  rotatingheatsource::expliciteuler::Vertex::shutdownDatatype();
  rotatingheatsource::expliciteuler::Cell::shutdownDatatype();

  if (rotatingheatsource::expliciteuler::records::RepositoryState::Datatype!=0) {
    rotatingheatsource::expliciteuler::records::RepositoryState::shutdownDatatype();
    rotatingheatsource::expliciteuler::records::RepositoryState::Datatype = 0;
  }
  #endif
}


rotatingheatsource::expliciteuler::repositories::RepositoryFactory& rotatingheatsource::expliciteuler::repositories::RepositoryFactory::getInstance() {
  static rotatingheatsource::expliciteuler::repositories::RepositoryFactory singleton;
  return singleton;
}

    
rotatingheatsource::expliciteuler::repositories::Repository* 
rotatingheatsource::expliciteuler::repositories::RepositoryFactory::createWithArrayStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset,
  int                                          maxCellStackSize,    
  int                                          maxVertexStackSize,    
  int                                          maxTemporaryVertexStackSize    
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new rotatingheatsource::expliciteuler::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
  }
  else
  #endif
  return new rotatingheatsource::expliciteuler::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
}    


rotatingheatsource::expliciteuler::repositories::Repository* 
rotatingheatsource::expliciteuler::repositories::RepositoryFactory::createWithSTDStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new rotatingheatsource::expliciteuler::repositories::RepositorySTDStack(geometry);
  }
  else
  #endif
  return new rotatingheatsource::expliciteuler::repositories::RepositorySTDStack(geometry, domainSize, computationalDomainOffset);
}
