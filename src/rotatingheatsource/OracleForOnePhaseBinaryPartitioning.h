// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ORACLE_FOR_ONE_PHASE_BINARY_PARTITIONING_H_
#define _ORACLE_FOR_ONE_PHASE_BINARY_PARTITIONING_H_


#include "peano/parallel/loadbalancing/OracleForOnePhase.h"
#include "tarch/logging/Log.h"


#include <set>
#include <vector>
#include <algorithm>


namespace poissonwithjacobi_wittmanr {
  class OracleForOnePhaseBinaryPartitioning;
  class WorkerInfo;
  struct _OracleState;
  typedef struct _OracleState OracleState;
      
  enum BinaryPartitioningMode {
    MAX_PART=0,    /* refine those areas with the maximum number of cells */
    MEDIAN_PART=1,  /* refine those areas where the number of cells is larger than the median */
    AVERAGE_PART=2 /* refine those areas where the numner of cells is larger than the average */
  };
}


class poissonwithjacobi_wittmanr::WorkerInfo {
    public:
        WorkerInfo();
        WorkerInfo(int rank);
        WorkerInfo(int rank, double localWorkload, double totalWorkload, 
                             double localWorkloadOfParent, double totalWorkloadOfParent,
                             int maxLevel);
        int getRank();
        double getLocalWorkload();
        double getTotalWorkload();
        double getLocalWorkloadOfParent();
        double getTotalWorkloadOfParent();
        void update(double localWorkload, double totalWorkload, double localWorkloadOfParent, double totalWorkloadOfParent, int maxLevel);
 
        bool isIdle();
        int getStability();
        void resetStability();

        bool isMarkedForRemoval();
        void markForRemoval();

        int getMaxLevel();
    private:
        int _rank;
        int _stability;
        int _maxLevel;
        double _localWorkload;
        double _totalWorkload;
        double _localWorkloadOfParent;
        double _totalWorkloadOfParent;
        bool _removal;
};

struct poissonwithjacobi_wittmanr::_OracleState {
    poissonwithjacobi_wittmanr::BinaryPartitioningMode mode;
    bool isGridBalanced;
    std::vector<poissonwithjacobi_wittmanr::WorkerInfo> workerSet;
};

class poissonwithjacobi_wittmanr::OracleForOnePhaseBinaryPartitioning: public peano::parallel::loadbalancing::OracleForOnePhase {
  public:

    OracleForOnePhaseBinaryPartitioning(bool joinsAllowed, OracleState& oracleState);
    virtual ~OracleForOnePhaseBinaryPartitioning();

    virtual void receivedStartCommand(const peano::parallel::loadbalancing::LoadBalancingFlag& commandFromMaster );

    /**
     * This operation is not const, as it might update some local stuff.
     */
    virtual peano::parallel::loadbalancing::LoadBalancingFlag getCommandForWorker( int workerRank, bool forkIsAllowed, bool joinIsAllowed );
    virtual int getCoarsestRegularInnerAndOuterGridLevel() const;
    /**
     * Information about termination call
     *
     * Is called whenever the master receives the acknowledgement from the
     * worker that the latter has finished its local traversal. Provides
     * statistics that you might want to bookkeep for load balancing. All t
     * the workload doubles stem from the cells' workload. See
     * Cell::setNodeWorkload() to adopt these figures to your own workload
     * model.
     *
     * @see receivedStartCommand()
     * @see getCommandForWorker()
     * @see Oracle
     *
     * @param workerRank   Rank of the worker that has just reported that it
     *                     finished its traversal.
     * @param waitedTime   Time (user time) that the master had to wait until
     *                     the worker delivered its finish message. This time
     *                     is zero, if the message was already in the MPI queue
     *                     when the master checked for the worker.
     * @param workerNumberOfInnerVertices  Number of inner vertices handled by
     *                     this worker. If you require the total number, you
     *                     have to feed your oracle manually within
     *                     endIteration(). Here, you have access to the state
     *                     object holding the total numbers.
     * @param workerNumberOfBoundaryVertices Number of boundary vertices
     *                     handled by this worker.
     * @param workerNumberOfOuterVertices Number of outer vertices handled by
     *                     this worker.
     * @param workerNumberOfInnerCells Number of inner cells handled by
     *                     this worker.
     * @param workerNumberOfOuterCells Number of outer cells handled by this
     *                     worker.
     * @param workerMaxLevel Maximum level handled by the worker. If you
     *                     compare it to current level, you have information
     *                     about the height of the worker tree.
     * @param workerLocalWorkload The workload handled by the worker. This is
     *                     the worker's local workload, i.e. if the worker has
     *                     forked itself again, workload of these children is
     *                     not contained within this figure.
     * @param workerTotalWorkload The workload represented by the worker. This
     *                     number is equal to workerLocalWorkload if the worker
     *                     has not forked again, i.e. if it does not have any
     *                     children. Otherwise, total workload comprises both
     *                     the worker's workload and those of its children.
     * @param currentLevel Current level, i.e. level of the root cell of the
     *                     worker partition.
     * @param parentCellLocalWorkload Local workload of the next coarser cell
     *                     on this rank. This number does not comprise workload
     *                     of any worker, i.e. it does in particular neither
     *                     comprise workerLocalWorkload nor
     *                     workerTotalWorkload.
     * @param parentCellTotalWorkload Total workload of the next coarser cell
     *                     comprising the ranks workload of the whole tree
     *                     induced by this cell plus the workloads of all
     *                     forked subtrees.
     * @param boundingBoxOffset Bounding box of this worker subtree.
     * @param boundingBoxSize   Bounding box of this worker subtree.
     */
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

    /**
     * Plot something to info log device.
     */
    virtual void plotStatistics();

    /**
     * Clone this oracle. This operation is used by the singleton whenever a
     * piece of code asks for parallelisation that never asked before.
     *
     * @param adapterNumber Number of your adapter. Have a closer look to your
     *        repository's state if you want to find out which adapters are
     *        mapped to which state. You can even use the toString() operation
     *        there to map this parameter to a string.
     */
    virtual OracleForOnePhase* createNewOracle(int adapterNumber) const;

    virtual void forkFailed();
 
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

    /**
     * Global flag set at construction time.
     */
    bool                        _joinsAllowed;

    OracleState& _oracleState;
    
    peano::parallel::loadbalancing::LoadBalancingFlag _commandFromMaster;
};



#endif
