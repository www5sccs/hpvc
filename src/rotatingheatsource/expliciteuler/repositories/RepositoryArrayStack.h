// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EXPLICITEULER_REPOSITORIES_REPOSITORY_ARRAY_STACK_H_ 
#define _ROTATINGHEATSOURCE_EXPLICITEULER_REPOSITORIES_REPOSITORY_ARRAY_STACK_H_ 


#include "rotatingheatsource/expliciteuler/repositories/Repository.h"
#include "rotatingheatsource/expliciteuler/records/RepositoryState.h"

#include "rotatingheatsource/expliciteuler/State.h"
#include "rotatingheatsource/expliciteuler/Vertex.h"
#include "rotatingheatsource/expliciteuler/Cell.h"

#include "peano/grid/Grid.h"
#include "peano/stacks/CellArrayStack.h"
#include "peano/stacks/VertexArrayStack.h"


 #include "rotatingheatsource/expliciteuler/adapters/SetupExperiment.h" 
 #include "rotatingheatsource/expliciteuler/adapters/PerformExplicitEulerTimeStep.h" 
 #include "rotatingheatsource/expliciteuler/adapters/PerformExplicitEulerTimeStepAndPlot.h" 
 #include "rotatingheatsource/expliciteuler/adapters/Plot.h" 



namespace rotatingheatsource { 
  namespace expliciteuler {
      namespace repositories {
        class RepositoryArrayStack;  
      }
}
}


class rotatingheatsource::expliciteuler::repositories::RepositoryArrayStack: public rotatingheatsource::expliciteuler::repositories::Repository {
  private:
    static tarch::logging::Log _log;
  
    peano::geometry::Geometry& _geometry;
    
    typedef peano::stacks::CellArrayStack<rotatingheatsource::expliciteuler::Cell>       CellStack;
    typedef peano::stacks::VertexArrayStack<rotatingheatsource::expliciteuler::Vertex>   VertexStack;

    CellStack    _cellStack;
    VertexStack  _vertexStack;
    rotatingheatsource::expliciteuler::State          _solverState;
    peano::grid::RegularGridContainer<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell>  _regularGridContainer;
    peano::grid::TraversalOrderOnTopLevel                                         _traversalOrderOnTopLevel;

    peano::grid::Grid<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell,rotatingheatsource::expliciteuler::State,VertexStack,CellStack,rotatingheatsource::expliciteuler::adapters::SetupExperiment> _gridWithSetupExperiment;
    peano::grid::Grid<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell,rotatingheatsource::expliciteuler::State,VertexStack,CellStack,rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStep> _gridWithPerformExplicitEulerTimeStep;
    peano::grid::Grid<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell,rotatingheatsource::expliciteuler::State,VertexStack,CellStack,rotatingheatsource::expliciteuler::adapters::PerformExplicitEulerTimeStepAndPlot> _gridWithPerformExplicitEulerTimeStepAndPlot;
    peano::grid::Grid<rotatingheatsource::expliciteuler::Vertex,rotatingheatsource::expliciteuler::Cell,rotatingheatsource::expliciteuler::State,VertexStack,CellStack,rotatingheatsource::expliciteuler::adapters::Plot> _gridWithPlot;

  
   rotatingheatsource::expliciteuler::records::RepositoryState               _repositoryState;
   
    tarch::timing::Measurement _measureSetupExperimentCPUTime;
    tarch::timing::Measurement _measurePerformExplicitEulerTimeStepCPUTime;
    tarch::timing::Measurement _measurePerformExplicitEulerTimeStepAndPlotCPUTime;
    tarch::timing::Measurement _measurePlotCPUTime;

    tarch::timing::Measurement _measureSetupExperimentCalendarTime;
    tarch::timing::Measurement _measurePerformExplicitEulerTimeStepCalendarTime;
    tarch::timing::Measurement _measurePerformExplicitEulerTimeStepAndPlotCalendarTime;
    tarch::timing::Measurement _measurePlotCalendarTime;


  public:
    RepositoryArrayStack(
      peano::geometry::Geometry&                   geometry,
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset,
      int                                          maximumSizeOfCellInOutStack,
      int                                          maximumSizeOfVertexInOutStack,
      int                                          maximumSizeOfVertexTemporaryStack
    );
    
    /**
     * Parallel Constructor
     *
     * Used in parallel mode only where the size of the domain is not known 
     * when the type of repository is determined.  
     */
    RepositoryArrayStack(
      peano::geometry::Geometry&                   geometry,
      int                                          maximumSizeOfCellInOutStack,
      int                                          maximumSizeOfVertexInOutStack,
      int                                          maximumSizeOfVertexTemporaryStack
    );
    
    virtual ~RepositoryArrayStack();

    virtual void restart(
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
      int                                          domainLevel,
      const tarch::la::Vector<DIMENSIONS,int>&     positionOfCentralElementWithRespectToCoarserRemoteLevel
    );
         
    virtual void terminate();
        
    virtual rotatingheatsource::expliciteuler::State& getState();

    virtual void iterate( bool reduceState = true );
    
    virtual void writeCheckpoint(peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell> * const checkpoint); 
    virtual void readCheckpoint( peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell> const * const checkpoint );
    virtual peano::grid::Checkpoint<rotatingheatsource::expliciteuler::Vertex, rotatingheatsource::expliciteuler::Cell>* createEmptyCheckpoint(); 

    virtual void switchToSetupExperiment();    
    virtual void switchToPerformExplicitEulerTimeStep();    
    virtual void switchToPerformExplicitEulerTimeStepAndPlot();    
    virtual void switchToPlot();    

    virtual bool isActiveAdapterSetupExperiment() const;
    virtual bool isActiveAdapterPerformExplicitEulerTimeStep() const;
    virtual bool isActiveAdapterPerformExplicitEulerTimeStepAndPlot() const;
    virtual bool isActiveAdapterPlot() const;

     
    #ifdef Parallel
    virtual bool continueToIterate();
    #endif

    virtual void setMaximumMemoryFootprintForTemporaryRegularGrids(double value);
    virtual void logIterationStatistics() const;
    virtual void clearIterationStatistics();
};


#endif
