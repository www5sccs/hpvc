#include "rotatingheatsource/DynamicLoadBalancingDemoNodePoolStrategy.h"
#include "tarch/parallel/Node.h"


tarch::logging::Log rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::_log( "tarch::parallel::DynamicLoadBalancingDemoNodePoolStrategy" );


rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::DynamicLoadBalancingDemoNodePoolStrategy():
  _scenarioPhase(0) {
}


rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::~DynamicLoadBalancingDemoNodePoolStrategy() {
}

void rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::moveIdleNodeToFrontInNodesContainer(int idleNodeNumber) {
  NodeContainer::iterator p = _nodes.begin();

  while( p->getRank()!=idleNodeNumber) {
    p++;
    assertion( p!=_nodes.end());
  }

  assertion1( p->isIdle(), p->toString() );

  _nodes.erase(p);
  _nodes.push_front(*p);
}


bool rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::hasIdleNode(int forMaster) const {
  bool result = FCFSNodePoolStrategy::hasIdleNode(forMaster);

  if (
    tarch::parallel::Node::getInstance().getNumberOfNodes()==4 &&
    _scenarioPhase==3
  ) {
    result &= (forMaster==3);
  }

  return result;
}


int rotatingheatsource::DynamicLoadBalancingDemoNodePoolStrategy::reserveNode(int forMaster) {
  if (
    tarch::parallel::Node::getInstance().getNumberOfNodes()==4 &&
    _scenarioPhase==0
  ) {
    assertionEquals(getNumberOfRegisteredNodes(),3);
    moveIdleNodeToFrontInNodesContainer(1);
    int result = FCFSNodePoolStrategy::reserveNode(forMaster);
    _scenarioPhase++;
    return result;
  }
  else if (
    tarch::parallel::Node::getInstance().getNumberOfNodes()==4 &&
    _scenarioPhase==1
  ) {
    assertionEquals(getNumberOfRegisteredNodes(),3);
    moveIdleNodeToFrontInNodesContainer(2);
    int result = FCFSNodePoolStrategy::reserveNode(forMaster);
    _scenarioPhase++;
    return result;
  }
  else if (
    tarch::parallel::Node::getInstance().getNumberOfNodes()==4 &&
    _scenarioPhase==2
  ) {
    assertionEquals(getNumberOfRegisteredNodes(),3);
    moveIdleNodeToFrontInNodesContainer(3);
    int result = FCFSNodePoolStrategy::reserveNode(forMaster);
    _scenarioPhase++;
    return result;
  }
  else if (
    tarch::parallel::Node::getInstance().getNumberOfNodes()==4 &&
    _scenarioPhase==3
  ) {
    assertionEquals(forMaster,3);
    int result = FCFSNodePoolStrategy::reserveNode(forMaster);
    _scenarioPhase++;
    return result;
  }
  else {
    return FCFSNodePoolStrategy::reserveNode(forMaster);
  }
}
