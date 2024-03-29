// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EXPLICITEULERREPOSITORIES__REPOSITORY_FACTORY_H_ 
#define _ROTATINGHEATSOURCE_EXPLICITEULERREPOSITORIES__REPOSITORY_FACTORY_H_


#include "peano/geometry/Geometry.h"
#include "tarch/la/Vector.h"
#include "peano/utils/Globals.h"


namespace rotatingheatsource { 
  namespace expliciteuler {
      namespace repositories {
        class RepositoryFactory;
        class Repository;
      } 
}
}



/**
 * Factory for the repositories.
 *
 * The factory is a singleton. Use getInstance() to get an instance of the class. 
 *
 * @author Peano Development Tool (PDT)
 */
class rotatingheatsource::expliciteuler::repositories::RepositoryFactory {
  private:
    RepositoryFactory();
  public:
    virtual ~RepositoryFactory();
    
    static RepositoryFactory& getInstance();
     
    /**
     * Create instance of repository. You are responsible to delete the instance 
     * in the end.
     *
     * @return New Repository.
     */
    Repository* createWithArrayStackImplementation(
      peano::geometry::Geometry&                   geometry,
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset,
      int                                          maxCellStackSize,    
      int                                          maxVertexStackSize,    
      int                                          maxTemporaryVertexStackSize    
    );    
    
    /**
     * Create instance of repository. You are responsible to delete the instance 
     * in the end.
     *
     * @return New Repository.
     */
    Repository* createWithSTDStackImplementation(
      peano::geometry::Geometry&                   geometry,
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
    );    
    
    /**
     * Shutdown all parallel datatypes and free their memory
     *
     * All MPI datatypes are implicitly registered by the factory the first 
     * time a factory is needed, i.e. by getInstance(). However, they are not 
     * freed automatically. Please free the datatypes as soon as you are sure 
     * that you won't need any factory or datatype of this project anymore.   
     */
    void shutdownAllParallelDatatypes();
};


#endif
