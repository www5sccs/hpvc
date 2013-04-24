// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATING_HEAT_SOURCE_DYNAMIC_LOAD_BALANCING_DEMO_NODE_POOL_STRATEGY_H_
#define _ROTATING_HEAT_SOURCE_DYNAMIC_LOAD_BALANCING_DEMO_NODE_POOL_STRATEGY_H_


#include "tarch/parallel/NodePoolStrategy.h"
#include "tarch/parallel/FCFSNodePoolStrategy.h"
#include "tarch/logging/Log.h"


#include <set>


namespace rotatingheatsource {
  class DynamicLoadBalancingDemoNodePoolStrategy;
}


/**
 * In this stragegy, I basically plug into the superclass and make the
 * deployment deterministic for a couple of rank-request combinations.
 */
class rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy: public tarch::parallel::FCFSNodePoolStrategy {
  private:
    /**
     * Logging Device
     */
    static tarch::logging::Log _log;

    /**
     * I use this counter for multi step load balancing scenarios.
     */
    int _scenarioPhase;

    void moveIdleNodeToFrontInNodesContainer(int idleNodeNumber);
  public:
  /**
   * Constructor
   *
   * Construct all the attributes.
   */
    DynamicLoadBalancingDemoNodePoolStrategy();
    virtual ~DynamicLoadBalancingDemoNodePoolStrategy();

//    virtual void setNodePoolTag(int tag);
//    virtual tarch::parallel::messages::WorkerRequestMessage extractElementFromRequestQueue(RequestQueue& queue);
//    virtual void fillWorkerRequestQueue(RequestQueue& queue);
//    virtual void addNode(const tarch::parallel::messages::RegisterAtNodePoolMessage& node );
//    virtual void removeNode( int rank );
//    virtual int getNumberOfIdleNodes() const;
//    virtual void setNodeIdle( int rank );
    virtual int reserveNode(int forMaster);
//    virtual bool isRegisteredNode(int rank) const;
//    virtual bool isIdleNode(int rank) const;
//    virtual void clearRegisteredNodes();
//    virtual int getNumberOfRegisteredNodes() const;
//    virtual std::string toString() const;
    virtual bool hasIdleNode(int forMaster) const;
//    virtual int removeNextIdleNode();
};



#endif
