#include "rotatingheatsource/expliciteuler/records/State.h"

#if defined(Parallel)
   rotatingheatsource::expliciteuler::records::State::PersistentRecords::PersistentRecords() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::PersistentRecords::PersistentRecords(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const LoadBalancingState& loadRebalancingState, const bool& reduceStateAndCell):
   _updateUMax(updateUMax),
   _updateUH(updateUH),
   _uMax(uMax),
   _uH(uH),
   _timeStep(timeStep),
   _timeStepSize(timeStepSize),
   _time(time),
   _numberOfStencilUpdates(numberOfStencilUpdates),
   _globalPlotCounter(globalPlotCounter),
   _minMeshWidth(minMeshWidth),
   _maxMeshWidth(maxMeshWidth),
   _numberOfInnerVertices(numberOfInnerVertices),
   _numberOfBoundaryVertices(numberOfBoundaryVertices),
   _numberOfOuterVertices(numberOfOuterVertices),
   _numberOfInnerCells(numberOfInnerCells),
   _numberOfOuterCells(numberOfOuterCells),
   _maxLevel(maxLevel),
   _hasRefined(hasRefined),
   _hasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration),
   _hasErased(hasErased),
   _hasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration),
   _hasChangedVertexOrCellState(hasChangedVertexOrCellState),
   _isTraversalInverted(isTraversalInverted),
   _loadRebalancingState(loadRebalancingState),
   _reduceStateAndCell(reduceStateAndCell) {
      
   }
   
   rotatingheatsource::expliciteuler::records::State::State() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::State(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._updateUMax, persistentRecords._updateUH, persistentRecords._uMax, persistentRecords._uH, persistentRecords._timeStep, persistentRecords._timeStepSize, persistentRecords._time, persistentRecords._numberOfStencilUpdates, persistentRecords._globalPlotCounter, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._maxLevel, persistentRecords._hasRefined, persistentRecords._hasTriggeredRefinementForNextIteration, persistentRecords._hasErased, persistentRecords._hasTriggeredEraseForNextIteration, persistentRecords._hasChangedVertexOrCellState, persistentRecords._isTraversalInverted, persistentRecords._loadRebalancingState, persistentRecords._reduceStateAndCell) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::State(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const LoadBalancingState& loadRebalancingState, const bool& reduceStateAndCell):
   _persistentRecords(updateUMax, updateUH, uMax, uH, timeStep, timeStepSize, time, numberOfStencilUpdates, globalPlotCounter, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted, loadRebalancingState, reduceStateAndCell) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::~State() { }
   
   std::string rotatingheatsource::expliciteuler::records::State::toString(const LoadBalancingState& param) {
      switch (param) {
         case NoRebalancing: return "NoRebalancing";
         case ForkTriggered: return "ForkTriggered";
         case Forking: return "Forking";
         case JoinTriggered: return "JoinTriggered";
         case Joining: return "Joining";
         case JoinWithMasterTriggered: return "JoinWithMasterTriggered";
         case JoiningWithMaster: return "JoiningWithMaster";
         case HasJoinedWithMaster: return "HasJoinedWithMaster";
         case IsNewWorkerDueToForkOfExistingDomain: return "IsNewWorkerDueToForkOfExistingDomain";
      }
      return "undefined";
   }
   
   std::string rotatingheatsource::expliciteuler::records::State::getLoadBalancingStateMapping() {
      return "LoadBalancingState(NoRebalancing=0,ForkTriggered=1,Forking=2,JoinTriggered=3,Joining=4,JoinWithMasterTriggered=5,JoiningWithMaster=6,HasJoinedWithMaster=7,IsNewWorkerDueToForkOfExistingDomain=8)";
   }
   
   
   std::string rotatingheatsource::expliciteuler::records::State::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::State::toString (std::ostream& out) const {
      out << "("; 
      out << "updateUMax:" << getUpdateUMax();
      out << ",";
      out << "updateUH:" << getUpdateUH();
      out << ",";
      out << "uMax:" << getUMax();
      out << ",";
      out << "uH:" << getUH();
      out << ",";
      out << "timeStep:" << getTimeStep();
      out << ",";
      out << "timeStepSize:" << getTimeStepSize();
      out << ",";
      out << "time:" << getTime();
      out << ",";
      out << "numberOfStencilUpdates:" << getNumberOfStencilUpdates();
      out << ",";
      out << "globalPlotCounter:" << getGlobalPlotCounter();
      out << ",";
      out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
      out << ",";
      out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
      out << ",";
      out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
      out << ",";
      out << "numberOfInnerCells:" << getNumberOfInnerCells();
      out << ",";
      out << "numberOfOuterCells:" << getNumberOfOuterCells();
      out << ",";
      out << "maxLevel:" << getMaxLevel();
      out << ",";
      out << "hasRefined:" << getHasRefined();
      out << ",";
      out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
      out << ",";
      out << "hasErased:" << getHasErased();
      out << ",";
      out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
      out << ",";
      out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
      out << ",";
      out << "isTraversalInverted:" << getIsTraversalInverted();
      out << ",";
      out << "loadRebalancingState:" << toString(getLoadRebalancingState());
      out << ",";
      out << "reduceStateAndCell:" << getReduceStateAndCell();
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::State::PersistentRecords rotatingheatsource::expliciteuler::records::State::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::StatePacked rotatingheatsource::expliciteuler::records::State::convert() const{
      return StatePacked(
         getUpdateUMax(),
         getUpdateUH(),
         getUMax(),
         getUH(),
         getTimeStep(),
         getTimeStepSize(),
         getTime(),
         getNumberOfStencilUpdates(),
         getGlobalPlotCounter(),
         getMinMeshWidth(),
         getMaxMeshWidth(),
         getNumberOfInnerVertices(),
         getNumberOfBoundaryVertices(),
         getNumberOfOuterVertices(),
         getNumberOfInnerCells(),
         getNumberOfOuterCells(),
         getMaxLevel(),
         getHasRefined(),
         getHasTriggeredRefinementForNextIteration(),
         getHasErased(),
         getHasTriggeredEraseForNextIteration(),
         getHasChangedVertexOrCellState(),
         getIsTraversalInverted(),
         getLoadRebalancingState(),
         getReduceStateAndCell()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::State::_log( "rotatingheatsource::expliciteuler::records::State" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::State::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::State::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::State::initDatatype() {
         {
            State dummyState[2];
            
            const int Attributes = 24;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._updateUMax))), 		&disp[23] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::Datatype );
            MPI_Type_commit( &State::Datatype );
            
         }
         {
            State dummyState[2];
            
            const int Attributes = 26;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_INT,		 //loadRebalancingState
               MPI_CHAR,		 //reduceStateAndCell
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1,		 //loadRebalancingState
               1,		 //reduceStateAndCell
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._loadRebalancingState))), 		&disp[23] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._reduceStateAndCell))), 		&disp[24] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._updateUMax))), 		&disp[25] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::FullDatatype );
            MPI_Type_commit( &State::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::State::shutdownDatatype() {
         MPI_Type_free( &State::Datatype );
         MPI_Type_free( &State::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::State::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         _senderDestinationRank = destination;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::State "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::State "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::State",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::State",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
      
      
      void rotatingheatsource::expliciteuler::records::State::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::State from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::State failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::State",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::State",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         _senderDestinationRank = status.MPI_SOURCE;
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
      
      
      bool rotatingheatsource::expliciteuler::records::State::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Status status;
         int  flag        = 0;
         MPI_Iprobe(
            MPI_ANY_SOURCE, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
         );
         if (flag) {
            int  messageCounter;
            if (exchangeOnlyAttributesMarkedWithParallelise) {
               MPI_Get_count(&status, Datatype, &messageCounter);
            }
            else {
               MPI_Get_count(&status, FullDatatype, &messageCounter);
            }
            return messageCounter > 0;
         }
         else return false;
         
      }
      
      int rotatingheatsource::expliciteuler::records::State::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords::PersistentRecords() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords::PersistentRecords(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const LoadBalancingState& loadRebalancingState, const bool& reduceStateAndCell):
   _updateUMax(updateUMax),
   _updateUH(updateUH),
   _uMax(uMax),
   _uH(uH),
   _timeStep(timeStep),
   _timeStepSize(timeStepSize),
   _time(time),
   _numberOfStencilUpdates(numberOfStencilUpdates),
   _globalPlotCounter(globalPlotCounter),
   _minMeshWidth(minMeshWidth),
   _maxMeshWidth(maxMeshWidth),
   _numberOfInnerVertices(numberOfInnerVertices),
   _numberOfBoundaryVertices(numberOfBoundaryVertices),
   _numberOfOuterVertices(numberOfOuterVertices),
   _numberOfInnerCells(numberOfInnerCells),
   _numberOfOuterCells(numberOfOuterCells),
   _maxLevel(maxLevel),
   _isTraversalInverted(isTraversalInverted),
   _loadRebalancingState(loadRebalancingState) {
      setHasRefined(hasRefined);
      setHasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration);
      setHasErased(hasErased);
      setHasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration);
      setHasChangedVertexOrCellState(hasChangedVertexOrCellState);
      setReduceStateAndCell(reduceStateAndCell);
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._updateUMax, persistentRecords._updateUH, persistentRecords._uMax, persistentRecords._uH, persistentRecords._timeStep, persistentRecords._timeStepSize, persistentRecords._time, persistentRecords._numberOfStencilUpdates, persistentRecords._globalPlotCounter, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._maxLevel, persistentRecords.getHasRefined(), persistentRecords.getHasTriggeredRefinementForNextIteration(), persistentRecords.getHasErased(), persistentRecords.getHasTriggeredEraseForNextIteration(), persistentRecords.getHasChangedVertexOrCellState(), persistentRecords._isTraversalInverted, persistentRecords._loadRebalancingState, persistentRecords.getReduceStateAndCell()) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const LoadBalancingState& loadRebalancingState, const bool& reduceStateAndCell):
   _persistentRecords(updateUMax, updateUH, uMax, uH, timeStep, timeStepSize, time, numberOfStencilUpdates, globalPlotCounter, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted, loadRebalancingState, reduceStateAndCell) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::~StatePacked() { }
   
   std::string rotatingheatsource::expliciteuler::records::StatePacked::toString(const LoadBalancingState& param) {
      return rotatingheatsource::expliciteuler::records::State::toString(param);
   }
   
   std::string rotatingheatsource::expliciteuler::records::StatePacked::getLoadBalancingStateMapping() {
      return rotatingheatsource::expliciteuler::records::State::getLoadBalancingStateMapping();
   }
   
   
   
   std::string rotatingheatsource::expliciteuler::records::StatePacked::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::StatePacked::toString (std::ostream& out) const {
      out << "("; 
      out << "updateUMax:" << getUpdateUMax();
      out << ",";
      out << "updateUH:" << getUpdateUH();
      out << ",";
      out << "uMax:" << getUMax();
      out << ",";
      out << "uH:" << getUH();
      out << ",";
      out << "timeStep:" << getTimeStep();
      out << ",";
      out << "timeStepSize:" << getTimeStepSize();
      out << ",";
      out << "time:" << getTime();
      out << ",";
      out << "numberOfStencilUpdates:" << getNumberOfStencilUpdates();
      out << ",";
      out << "globalPlotCounter:" << getGlobalPlotCounter();
      out << ",";
      out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
      out << ",";
      out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
      out << ",";
      out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
      out << ",";
      out << "numberOfInnerCells:" << getNumberOfInnerCells();
      out << ",";
      out << "numberOfOuterCells:" << getNumberOfOuterCells();
      out << ",";
      out << "maxLevel:" << getMaxLevel();
      out << ",";
      out << "hasRefined:" << getHasRefined();
      out << ",";
      out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
      out << ",";
      out << "hasErased:" << getHasErased();
      out << ",";
      out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
      out << ",";
      out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
      out << ",";
      out << "isTraversalInverted:" << getIsTraversalInverted();
      out << ",";
      out << "loadRebalancingState:" << toString(getLoadRebalancingState());
      out << ",";
      out << "reduceStateAndCell:" << getReduceStateAndCell();
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords rotatingheatsource::expliciteuler::records::StatePacked::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::State rotatingheatsource::expliciteuler::records::StatePacked::convert() const{
      return State(
         getUpdateUMax(),
         getUpdateUH(),
         getUMax(),
         getUH(),
         getTimeStep(),
         getTimeStepSize(),
         getTime(),
         getNumberOfStencilUpdates(),
         getGlobalPlotCounter(),
         getMinMeshWidth(),
         getMaxMeshWidth(),
         getNumberOfInnerVertices(),
         getNumberOfBoundaryVertices(),
         getNumberOfOuterVertices(),
         getNumberOfInnerCells(),
         getNumberOfOuterCells(),
         getMaxLevel(),
         getHasRefined(),
         getHasTriggeredRefinementForNextIteration(),
         getHasErased(),
         getHasTriggeredEraseForNextIteration(),
         getHasChangedVertexOrCellState(),
         getIsTraversalInverted(),
         getLoadRebalancingState(),
         getReduceStateAndCell()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::StatePacked::_log( "rotatingheatsource::expliciteuler::records::StatePacked" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::StatePacked::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::StatePacked::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::initDatatype() {
         {
            StatePacked dummyStatePacked[2];
            
            const int Attributes = 20;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //isTraversalInverted
               MPI_SHORT,		 //_packedRecords0
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //isTraversalInverted
               1,		 //_packedRecords0
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._updateUMax))), 		&disp[19] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::Datatype );
            MPI_Type_commit( &StatePacked::Datatype );
            
         }
         {
            StatePacked dummyStatePacked[2];
            
            const int Attributes = 21;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //isTraversalInverted
               MPI_INT,		 //loadRebalancingState
               MPI_SHORT,		 //_packedRecords0
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //isTraversalInverted
               1,		 //loadRebalancingState
               1,		 //_packedRecords0
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._loadRebalancingState))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._updateUMax))), 		&disp[20] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::FullDatatype );
            MPI_Type_commit( &StatePacked::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::shutdownDatatype() {
         MPI_Type_free( &StatePacked::Datatype );
         MPI_Type_free( &StatePacked::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::StatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         _senderDestinationRank = destination;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::StatePacked "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::StatePacked "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::StatePacked from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::StatePacked failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         _senderDestinationRank = status.MPI_SOURCE;
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
      
      
      bool rotatingheatsource::expliciteuler::records::StatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Status status;
         int  flag        = 0;
         MPI_Iprobe(
            MPI_ANY_SOURCE, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
         );
         if (flag) {
            int  messageCounter;
            if (exchangeOnlyAttributesMarkedWithParallelise) {
               MPI_Get_count(&status, Datatype, &messageCounter);
            }
            else {
               MPI_Get_count(&status, FullDatatype, &messageCounter);
            }
            return messageCounter > 0;
         }
         else return false;
         
      }
      
      int rotatingheatsource::expliciteuler::records::StatePacked::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   
#elif !defined(Parallel)
   rotatingheatsource::expliciteuler::records::State::PersistentRecords::PersistentRecords() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::PersistentRecords::PersistentRecords(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
   _updateUMax(updateUMax),
   _updateUH(updateUH),
   _uMax(uMax),
   _uH(uH),
   _timeStep(timeStep),
   _timeStepSize(timeStepSize),
   _time(time),
   _numberOfStencilUpdates(numberOfStencilUpdates),
   _globalPlotCounter(globalPlotCounter),
   _minMeshWidth(minMeshWidth),
   _maxMeshWidth(maxMeshWidth),
   _numberOfInnerVertices(numberOfInnerVertices),
   _numberOfBoundaryVertices(numberOfBoundaryVertices),
   _numberOfOuterVertices(numberOfOuterVertices),
   _numberOfInnerCells(numberOfInnerCells),
   _numberOfOuterCells(numberOfOuterCells),
   _maxLevel(maxLevel),
   _hasRefined(hasRefined),
   _hasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration),
   _hasErased(hasErased),
   _hasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration),
   _hasChangedVertexOrCellState(hasChangedVertexOrCellState),
   _isTraversalInverted(isTraversalInverted) {
      
   }
   
   rotatingheatsource::expliciteuler::records::State::State() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::State(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._updateUMax, persistentRecords._updateUH, persistentRecords._uMax, persistentRecords._uH, persistentRecords._timeStep, persistentRecords._timeStepSize, persistentRecords._time, persistentRecords._numberOfStencilUpdates, persistentRecords._globalPlotCounter, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._maxLevel, persistentRecords._hasRefined, persistentRecords._hasTriggeredRefinementForNextIteration, persistentRecords._hasErased, persistentRecords._hasTriggeredEraseForNextIteration, persistentRecords._hasChangedVertexOrCellState, persistentRecords._isTraversalInverted) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::State(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
   _persistentRecords(updateUMax, updateUH, uMax, uH, timeStep, timeStepSize, time, numberOfStencilUpdates, globalPlotCounter, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::State::~State() { }
   
   
   
   std::string rotatingheatsource::expliciteuler::records::State::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::State::toString (std::ostream& out) const {
      out << "("; 
      out << "updateUMax:" << getUpdateUMax();
      out << ",";
      out << "updateUH:" << getUpdateUH();
      out << ",";
      out << "uMax:" << getUMax();
      out << ",";
      out << "uH:" << getUH();
      out << ",";
      out << "timeStep:" << getTimeStep();
      out << ",";
      out << "timeStepSize:" << getTimeStepSize();
      out << ",";
      out << "time:" << getTime();
      out << ",";
      out << "numberOfStencilUpdates:" << getNumberOfStencilUpdates();
      out << ",";
      out << "globalPlotCounter:" << getGlobalPlotCounter();
      out << ",";
      out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
      out << ",";
      out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
      out << ",";
      out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
      out << ",";
      out << "numberOfInnerCells:" << getNumberOfInnerCells();
      out << ",";
      out << "numberOfOuterCells:" << getNumberOfOuterCells();
      out << ",";
      out << "maxLevel:" << getMaxLevel();
      out << ",";
      out << "hasRefined:" << getHasRefined();
      out << ",";
      out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
      out << ",";
      out << "hasErased:" << getHasErased();
      out << ",";
      out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
      out << ",";
      out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
      out << ",";
      out << "isTraversalInverted:" << getIsTraversalInverted();
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::State::PersistentRecords rotatingheatsource::expliciteuler::records::State::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::StatePacked rotatingheatsource::expliciteuler::records::State::convert() const{
      return StatePacked(
         getUpdateUMax(),
         getUpdateUH(),
         getUMax(),
         getUH(),
         getTimeStep(),
         getTimeStepSize(),
         getTime(),
         getNumberOfStencilUpdates(),
         getGlobalPlotCounter(),
         getMinMeshWidth(),
         getMaxMeshWidth(),
         getNumberOfInnerVertices(),
         getNumberOfBoundaryVertices(),
         getNumberOfOuterVertices(),
         getNumberOfInnerCells(),
         getNumberOfOuterCells(),
         getMaxLevel(),
         getHasRefined(),
         getHasTriggeredRefinementForNextIteration(),
         getHasErased(),
         getHasTriggeredEraseForNextIteration(),
         getHasChangedVertexOrCellState(),
         getIsTraversalInverted()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::State::_log( "rotatingheatsource::expliciteuler::records::State" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::State::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::State::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::State::initDatatype() {
         {
            State dummyState[2];
            
            const int Attributes = 24;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._updateUMax))), 		&disp[23] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::Datatype );
            MPI_Type_commit( &State::Datatype );
            
         }
         {
            State dummyState[2];
            
            const int Attributes = 24;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._updateUMax))), 		&disp[23] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::FullDatatype );
            MPI_Type_commit( &State::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::State::shutdownDatatype() {
         MPI_Type_free( &State::Datatype );
         MPI_Type_free( &State::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::State::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         _senderDestinationRank = destination;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::State "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::State "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::State",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::State",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
      
      
      void rotatingheatsource::expliciteuler::records::State::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::State from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::State failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::State",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::State",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         _senderDestinationRank = status.MPI_SOURCE;
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
      
      
      bool rotatingheatsource::expliciteuler::records::State::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Status status;
         int  flag        = 0;
         MPI_Iprobe(
            MPI_ANY_SOURCE, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
         );
         if (flag) {
            int  messageCounter;
            if (exchangeOnlyAttributesMarkedWithParallelise) {
               MPI_Get_count(&status, Datatype, &messageCounter);
            }
            else {
               MPI_Get_count(&status, FullDatatype, &messageCounter);
            }
            return messageCounter > 0;
         }
         else return false;
         
      }
      
      int rotatingheatsource::expliciteuler::records::State::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords::PersistentRecords() {
      assertion((5 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords::PersistentRecords(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
   _updateUMax(updateUMax),
   _updateUH(updateUH),
   _uMax(uMax),
   _uH(uH),
   _timeStep(timeStep),
   _timeStepSize(timeStepSize),
   _time(time),
   _numberOfStencilUpdates(numberOfStencilUpdates),
   _globalPlotCounter(globalPlotCounter),
   _minMeshWidth(minMeshWidth),
   _maxMeshWidth(maxMeshWidth),
   _numberOfInnerVertices(numberOfInnerVertices),
   _numberOfBoundaryVertices(numberOfBoundaryVertices),
   _numberOfOuterVertices(numberOfOuterVertices),
   _numberOfInnerCells(numberOfInnerCells),
   _numberOfOuterCells(numberOfOuterCells),
   _maxLevel(maxLevel),
   _isTraversalInverted(isTraversalInverted) {
      setHasRefined(hasRefined);
      setHasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration);
      setHasErased(hasErased);
      setHasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration);
      setHasChangedVertexOrCellState(hasChangedVertexOrCellState);
      assertion((5 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked() {
      assertion((5 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._updateUMax, persistentRecords._updateUH, persistentRecords._uMax, persistentRecords._uH, persistentRecords._timeStep, persistentRecords._timeStepSize, persistentRecords._time, persistentRecords._numberOfStencilUpdates, persistentRecords._globalPlotCounter, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._maxLevel, persistentRecords.getHasRefined(), persistentRecords.getHasTriggeredRefinementForNextIteration(), persistentRecords.getHasErased(), persistentRecords.getHasTriggeredEraseForNextIteration(), persistentRecords.getHasChangedVertexOrCellState(), persistentRecords._isTraversalInverted) {
      assertion((5 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::StatePacked(const double& updateUMax, const double& updateUH, const double& uMax, const double& uH, const int& timeStep, const double& timeStepSize, const double& time, const double& numberOfStencilUpdates, const int& globalPlotCounter, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
   _persistentRecords(updateUMax, updateUH, uMax, uH, timeStep, timeStepSize, time, numberOfStencilUpdates, globalPlotCounter, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted) {
      assertion((5 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::~StatePacked() { }
   
   
   
   std::string rotatingheatsource::expliciteuler::records::StatePacked::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::StatePacked::toString (std::ostream& out) const {
      out << "("; 
      out << "updateUMax:" << getUpdateUMax();
      out << ",";
      out << "updateUH:" << getUpdateUH();
      out << ",";
      out << "uMax:" << getUMax();
      out << ",";
      out << "uH:" << getUH();
      out << ",";
      out << "timeStep:" << getTimeStep();
      out << ",";
      out << "timeStepSize:" << getTimeStepSize();
      out << ",";
      out << "time:" << getTime();
      out << ",";
      out << "numberOfStencilUpdates:" << getNumberOfStencilUpdates();
      out << ",";
      out << "globalPlotCounter:" << getGlobalPlotCounter();
      out << ",";
      out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
      out << ",";
      out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
      out << ",";
      out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
      out << ",";
      out << "numberOfInnerCells:" << getNumberOfInnerCells();
      out << ",";
      out << "numberOfOuterCells:" << getNumberOfOuterCells();
      out << ",";
      out << "maxLevel:" << getMaxLevel();
      out << ",";
      out << "hasRefined:" << getHasRefined();
      out << ",";
      out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
      out << ",";
      out << "hasErased:" << getHasErased();
      out << ",";
      out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
      out << ",";
      out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
      out << ",";
      out << "isTraversalInverted:" << getIsTraversalInverted();
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::StatePacked::PersistentRecords rotatingheatsource::expliciteuler::records::StatePacked::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::State rotatingheatsource::expliciteuler::records::StatePacked::convert() const{
      return State(
         getUpdateUMax(),
         getUpdateUH(),
         getUMax(),
         getUH(),
         getTimeStep(),
         getTimeStepSize(),
         getTime(),
         getNumberOfStencilUpdates(),
         getGlobalPlotCounter(),
         getMinMeshWidth(),
         getMaxMeshWidth(),
         getNumberOfInnerVertices(),
         getNumberOfBoundaryVertices(),
         getNumberOfOuterVertices(),
         getNumberOfInnerCells(),
         getNumberOfOuterCells(),
         getMaxLevel(),
         getHasRefined(),
         getHasTriggeredRefinementForNextIteration(),
         getHasErased(),
         getHasTriggeredEraseForNextIteration(),
         getHasChangedVertexOrCellState(),
         getIsTraversalInverted()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::StatePacked::_log( "rotatingheatsource::expliciteuler::records::StatePacked" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::StatePacked::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::StatePacked::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::initDatatype() {
         {
            StatePacked dummyStatePacked[2];
            
            const int Attributes = 20;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //isTraversalInverted
               MPI_SHORT,		 //_packedRecords0
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //isTraversalInverted
               1,		 //_packedRecords0
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._updateUMax))), 		&disp[19] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::Datatype );
            MPI_Type_commit( &StatePacked::Datatype );
            
         }
         {
            StatePacked dummyStatePacked[2];
            
            const int Attributes = 20;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //updateUMax
               MPI_DOUBLE,		 //updateUH
               MPI_DOUBLE,		 //uMax
               MPI_DOUBLE,		 //uH
               MPI_INT,		 //timeStep
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //time
               MPI_DOUBLE,		 //numberOfStencilUpdates
               MPI_INT,		 //globalPlotCounter
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //isTraversalInverted
               MPI_SHORT,		 //_packedRecords0
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //updateUMax
               1,		 //updateUH
               1,		 //uMax
               1,		 //uH
               1,		 //timeStep
               1,		 //timeStepSize
               1,		 //time
               1,		 //numberOfStencilUpdates
               1,		 //globalPlotCounter
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //maxLevel
               1,		 //isTraversalInverted
               1,		 //_packedRecords0
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUMax))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._updateUH))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uMax))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._uH))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStep))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._time))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfStencilUpdates))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._globalPlotCounter))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._updateUMax))), 		&disp[19] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::FullDatatype );
            MPI_Type_commit( &StatePacked::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::shutdownDatatype() {
         MPI_Type_free( &StatePacked::Datatype );
         MPI_Type_free( &StatePacked::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::StatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         _senderDestinationRank = destination;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::StatePacked "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::StatePacked "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
      
      
      void rotatingheatsource::expliciteuler::records::StatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::StatePacked from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::StatePacked failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::StatePacked",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         _senderDestinationRank = status.MPI_SOURCE;
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
      
      
      bool rotatingheatsource::expliciteuler::records::StatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Status status;
         int  flag        = 0;
         MPI_Iprobe(
            MPI_ANY_SOURCE, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
         );
         if (flag) {
            int  messageCounter;
            if (exchangeOnlyAttributesMarkedWithParallelise) {
               MPI_Get_count(&status, Datatype, &messageCounter);
            }
            else {
               MPI_Get_count(&status, FullDatatype, &messageCounter);
            }
            return messageCounter > 0;
         }
         else return false;
         
      }
      
      int rotatingheatsource::expliciteuler::records::StatePacked::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   

#endif


