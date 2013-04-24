// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATING_HEAT_SOURCE_DYNAMIC_LOAD_BALANCING_DEMO_ORACLE_H_
#define _ROTATING_HEAT_SOURCE_DYNAMIC_LOAD_BALANCING_DEMO_ORACLE_H_



// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PEANO_PARALLEL_LOADBALANCING_ORACLE_FOR_ONE_PHASE_WITH_GREEDY_PARTITIONING_H_
#define _PEANO_PARALLEL_LOADBALANCING_ORACLE_FOR_ONE_PHASE_WITH_GREEDY_PARTITIONING_H_


#include "peano/parallel/loadbalancing/OracleForOnePhase.h"
#include "tarch/logging/Log.h"


#include <set>


namespace rotatingheatsource {
  class DynamicLoadBalancingDemoOracle;
}


/**
 * Demo Oracle
 *
 * This is a very simple oracle to control the load balancing. It has two
 * different phases: By default, it realises a greedy pratitioning, i.e.
 * each node asks for additional workers all the time. Every K traversals
 * however, it decides to merge aggressively.
 *
 * @author Tobias Weinzierl
 */
class rotatingheatsource::DynamicLoadBalancingDemoOracle: public peano::parallel::loadbalancing::OracleForOnePhase {
  private:
    /**
     * Logging device
     */
    static tarch::logging::Log  _log;

    /**
     * If a fork failed, all the oracles should stop to ask for further forks.
     * Wouldn't make sense and just slow down the application.
     */
    static bool                 _forkHasFailed;

    int                         _iterationCountSinceLastJoin;

    static const int            JoinEveryKIterations;

  public:
    DynamicLoadBalancingDemoOracle();
    virtual ~DynamicLoadBalancingDemoOracle();

    virtual void receivedStartCommand(const peano::parallel::loadbalancing::LoadBalancingFlag& commandFromMaster );
    virtual peano::parallel::loadbalancing::LoadBalancingFlag getCommandForWorker( int workerRank, bool forkIsAllowed, bool joinIsAllowed );
    virtual void receivedTerminateCommand(
      int     workerRank,
      double  waitedTime,
      double  workerNumberOfInnerVertices,
      double  workerNumberOfBoundaryVertices,
      double  workerNumberOfOuterVertices,
      double  workerNumberOfInnerCells,
      double  workerNumberOfOuterCells,
      int     workerMaxLevel,
      double  workerLocalWorkload,
      double  workerTotalWorkload,
      int     currentLevel,
      double  parentCellLocalWorkload,
      double  parentCellTotalWorkload,
      const tarch::la::Vector<DIMENSIONS,double>& boundingBoxOffset,
      const tarch::la::Vector<DIMENSIONS,double>& boundingBoxSize
    );
    virtual void plotStatistics();
    virtual OracleForOnePhase* createNewOracle(int adapterNumber) const;
    virtual void forkFailed();
    virtual int getCoarsestRegularInnerAndOuterGridLevel() const;
};



#endif



#endif
