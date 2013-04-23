#include "rotatingheatsource/expliciteuler/records/RepositoryState.h"

rotatingheatsource::expliciteuler::records::RepositoryState::PersistentRecords::PersistentRecords() {
   
}


rotatingheatsource::expliciteuler::records::RepositoryState::PersistentRecords::PersistentRecords(const Action& action, const bool& reduceState):
_action(action),
_reduceState(reduceState) {
   
}

rotatingheatsource::expliciteuler::records::RepositoryState::RepositoryState() {
   
}


rotatingheatsource::expliciteuler::records::RepositoryState::RepositoryState(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._action, persistentRecords._reduceState) {
   
}


rotatingheatsource::expliciteuler::records::RepositoryState::RepositoryState(const Action& action, const bool& reduceState):
_persistentRecords(action, reduceState) {
   
}


rotatingheatsource::expliciteuler::records::RepositoryState::~RepositoryState() { }

std::string rotatingheatsource::expliciteuler::records::RepositoryState::toString(const Action& param) {
   switch (param) {
      case WriteCheckpoint: return "WriteCheckpoint";
      case ReadCheckpoint: return "ReadCheckpoint";
      case Terminate: return "Terminate";
      case UseAdapterSetupExperiment: return "UseAdapterSetupExperiment";
      case UseAdapterPerformExplicitEulerTimeStep: return "UseAdapterPerformExplicitEulerTimeStep";
      case UseAdapterPerformExplicitEulerTimeStepAndPlot: return "UseAdapterPerformExplicitEulerTimeStepAndPlot";
      case UseAdapterPlot: return "UseAdapterPlot";
   }
   return "undefined";
}

std::string rotatingheatsource::expliciteuler::records::RepositoryState::getActionMapping() {
   return "Action(WriteCheckpoint=0,ReadCheckpoint=1,Terminate=2,UseAdapterSetupExperiment=3,UseAdapterPerformExplicitEulerTimeStep=4,UseAdapterPerformExplicitEulerTimeStepAndPlot=5,UseAdapterPlot=6)";
}


std::string rotatingheatsource::expliciteuler::records::RepositoryState::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::RepositoryState::toString (std::ostream& out) const {
   out << "("; 
   out << "action:" << toString(getAction());
   out << ",";
   out << "reduceState:" << getReduceState();
   out <<  ")";
}


rotatingheatsource::expliciteuler::records::RepositoryState::PersistentRecords rotatingheatsource::expliciteuler::records::RepositoryState::getPersistentRecords() const {
   return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::RepositoryStatePacked rotatingheatsource::expliciteuler::records::RepositoryState::convert() const{
   return RepositoryStatePacked(
      getAction(),
      getReduceState()
   );
}

#ifdef Parallel
   tarch::logging::Log rotatingheatsource::expliciteuler::records::RepositoryState::_log( "rotatingheatsource::expliciteuler::records::RepositoryState" );
   
   MPI_Datatype rotatingheatsource::expliciteuler::records::RepositoryState::Datatype = 0;
   MPI_Datatype rotatingheatsource::expliciteuler::records::RepositoryState::FullDatatype = 0;
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryState::initDatatype() {
      {
         RepositoryState dummyRepositoryState[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_CHAR,		 //reduceState
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1,		 //reduceState
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._reduceState))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[1]._persistentRecords._action))), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryState::Datatype );
         MPI_Type_commit( &RepositoryState::Datatype );
         
      }
      {
         RepositoryState dummyRepositoryState[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_CHAR,		 //reduceState
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1,		 //reduceState
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._reduceState))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[1]._persistentRecords._action))), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryState::FullDatatype );
         MPI_Type_commit( &RepositoryState::FullDatatype );
         
      }
      
   }
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryState::shutdownDatatype() {
      MPI_Type_free( &RepositoryState::Datatype );
      MPI_Type_free( &RepositoryState::FullDatatype );
      
   }
   
   void rotatingheatsource::expliciteuler::records::RepositoryState::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "was not able to send message rotatingheatsource::expliciteuler::records::RepositoryState "
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
            msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::RepositoryState "
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
            "rotatingheatsource::expliciteuler::records::RepositoryState",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::RepositoryState",
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
   
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryState::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "failed to start to receive rotatingheatsource::expliciteuler::records::RepositoryState from node "
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
            msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::RepositoryState failed: "
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
            "rotatingheatsource::expliciteuler::records::RepositoryState",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::RepositoryState",
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
   
   
   
   bool rotatingheatsource::expliciteuler::records::RepositoryState::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   int rotatingheatsource::expliciteuler::records::RepositoryState::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::PersistentRecords::PersistentRecords() {
   
}


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::PersistentRecords::PersistentRecords(const Action& action, const bool& reduceState):
_action(action),
_reduceState(reduceState) {
   
}

rotatingheatsource::expliciteuler::records::RepositoryStatePacked::RepositoryStatePacked() {
   
}


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::RepositoryStatePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._action, persistentRecords._reduceState) {
   
}


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::RepositoryStatePacked(const Action& action, const bool& reduceState):
_persistentRecords(action, reduceState) {
   
}


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::~RepositoryStatePacked() { }

std::string rotatingheatsource::expliciteuler::records::RepositoryStatePacked::toString(const Action& param) {
   return rotatingheatsource::expliciteuler::records::RepositoryState::toString(param);
}

std::string rotatingheatsource::expliciteuler::records::RepositoryStatePacked::getActionMapping() {
   return rotatingheatsource::expliciteuler::records::RepositoryState::getActionMapping();
}



std::string rotatingheatsource::expliciteuler::records::RepositoryStatePacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::RepositoryStatePacked::toString (std::ostream& out) const {
   out << "("; 
   out << "action:" << toString(getAction());
   out << ",";
   out << "reduceState:" << getReduceState();
   out <<  ")";
}


rotatingheatsource::expliciteuler::records::RepositoryStatePacked::PersistentRecords rotatingheatsource::expliciteuler::records::RepositoryStatePacked::getPersistentRecords() const {
   return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::RepositoryState rotatingheatsource::expliciteuler::records::RepositoryStatePacked::convert() const{
   return RepositoryState(
      getAction(),
      getReduceState()
   );
}

#ifdef Parallel
   tarch::logging::Log rotatingheatsource::expliciteuler::records::RepositoryStatePacked::_log( "rotatingheatsource::expliciteuler::records::RepositoryStatePacked" );
   
   MPI_Datatype rotatingheatsource::expliciteuler::records::RepositoryStatePacked::Datatype = 0;
   MPI_Datatype rotatingheatsource::expliciteuler::records::RepositoryStatePacked::FullDatatype = 0;
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryStatePacked::initDatatype() {
      {
         RepositoryStatePacked dummyRepositoryStatePacked[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_CHAR,		 //reduceState
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1,		 //reduceState
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._reduceState))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[1]._persistentRecords._action))), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryStatePacked::Datatype );
         MPI_Type_commit( &RepositoryStatePacked::Datatype );
         
      }
      {
         RepositoryStatePacked dummyRepositoryStatePacked[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_CHAR,		 //reduceState
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1,		 //reduceState
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._reduceState))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[1]._persistentRecords._action))), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryStatePacked::FullDatatype );
         MPI_Type_commit( &RepositoryStatePacked::FullDatatype );
         
      }
      
   }
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryStatePacked::shutdownDatatype() {
      MPI_Type_free( &RepositoryStatePacked::Datatype );
      MPI_Type_free( &RepositoryStatePacked::FullDatatype );
      
   }
   
   void rotatingheatsource::expliciteuler::records::RepositoryStatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "was not able to send message rotatingheatsource::expliciteuler::records::RepositoryStatePacked "
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
            msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::RepositoryStatePacked "
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
            "rotatingheatsource::expliciteuler::records::RepositoryStatePacked",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::RepositoryStatePacked",
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
   
   
   
   void rotatingheatsource::expliciteuler::records::RepositoryStatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "failed to start to receive rotatingheatsource::expliciteuler::records::RepositoryStatePacked from node "
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
            msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::RepositoryStatePacked failed: "
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
            "rotatingheatsource::expliciteuler::records::RepositoryStatePacked",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::RepositoryStatePacked",
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
   
   
   
   bool rotatingheatsource::expliciteuler::records::RepositoryStatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   int rotatingheatsource::expliciteuler::records::RepositoryStatePacked::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif



