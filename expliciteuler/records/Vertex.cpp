#include "rotatingheatsource/expliciteuler/records/Vertex.h"

#if defined(Parallel) && defined(Asserts)
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _rhs(rhs),
   _u(u),
   _stencil(stencil),
   _linearSurplus(linearSurplus),
   _isHangingNode(isHangingNode),
   _refinementControl(refinementControl),
   _adjacentCellsHeight(adjacentCellsHeight),
   _insideOutsideDomain(insideOutsideDomain),
   _x(x),
   _level(level),
   _adjacentRanks(adjacentRanks) {
      
   }
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._x, persistentRecords._level, persistentRecords._adjacentRanks) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks),_residual(residual),
   _adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
   _numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
      
   }
   
   rotatingheatsource::expliciteuler::records::Vertex::~Vertex() { }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const InsideOutsideDomain& param) {
      switch (param) {
         case Inside: return "Inside";
         case Boundary: return "Boundary";
         case Outside: return "Outside";
      }
      return "undefined";
   }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping() {
      return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
   }
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const RefinementControl& param) {
      switch (param) {
         case Unrefined: return "Unrefined";
         case Refined: return "Refined";
         case RefinementTriggered: return "RefinementTriggered";
         case Refining: return "Refining";
         case EraseTriggered: return "EraseTriggered";
         case Erasing: return "Erasing";
         case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
      }
      return "undefined";
   }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping() {
      return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
   }
   
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::Vertex::toString (std::ostream& out) const {
      out << "("; 
      out << "rhs:" << getRhs();
      out << ",";
      out << "u:" << getU();
      out << ",";
      out << "residual:" << getResidual();
      out << ",";
      out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
      out << ",";
      out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
      out << ",";
      out << "isHangingNode:" << getIsHangingNode();
      out << ",";
      out << "refinementControl:" << toString(getRefinementControl());
      out << ",";
      out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
      out << ",";
      out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
      out << ",";
      out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
      out << ",";
      out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
      out << ",";
      out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
      out << ",";
      out << "level:" << getLevel();
      out << ",";
      out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords rotatingheatsource::expliciteuler::records::Vertex::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked rotatingheatsource::expliciteuler::records::Vertex::convert() const{
      return VertexPacked(
         getRhs(),
         getU(),
         getResidual(),
         getStencil(),
         getLinearSurplus(),
         getIsHangingNode(),
         getRefinementControl(),
         getAdjacentCellsHeight(),
         getAdjacentCellsHeightOfPreviousIteration(),
         getNumberOfAdjacentRefinedCells(),
         getInsideOutsideDomain(),
         getX(),
         getLevel(),
         getAdjacentRanks()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::Vertex::_log( "rotatingheatsource::expliciteuler::records::Vertex" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::initDatatype() {
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 12;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //linearSurplus
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_INT,		 //insideOutsideDomain
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               DIMENSIONS,		 //linearSurplus
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //insideOutsideDomain
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //residual
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[11] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
            MPI_Type_commit( &Vertex::Datatype );
            
         }
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 15;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //stencil
               MPI_DOUBLE,		 //linearSurplus
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_INT,		 //adjacentCellsHeight
               MPI_INT,		 //insideOutsideDomain
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               THREE_POWER_D,		 //stencil
               DIMENSIONS,		 //linearSurplus
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //adjacentCellsHeight
               1,		 //insideOutsideDomain
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //residual
               1,		 //adjacentCellsHeightOfPreviousIteration
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._stencil[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[14] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
            MPI_Type_commit( &Vertex::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::shutdownDatatype() {
         MPI_Type_free( &Vertex::Datatype );
         MPI_Type_free( &Vertex::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::Vertex "
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
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::Vertex "
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
               "rotatingheatsource::expliciteuler::records::Vertex",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::Vertex",
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
      
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::Vertex from node "
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
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::Vertex failed: "
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
               "rotatingheatsource::expliciteuler::records::Vertex",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::Vertex",
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
      
      
      
      bool rotatingheatsource::expliciteuler::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      
      int rotatingheatsource::expliciteuler::records::Vertex::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _rhs(rhs),
   _u(u),
   _stencil(stencil),
   _linearSurplus(linearSurplus),
   _adjacentCellsHeight(adjacentCellsHeight),
   _x(x),
   _level(level),
   _adjacentRanks(adjacentRanks) {
      setIsHangingNode(isHangingNode);
      setRefinementControl(refinementControl);
      setInsideOutsideDomain(insideOutsideDomain);
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._x, persistentRecords._level, persistentRecords._adjacentRanks) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks),_residual(residual),
   _adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
   _numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked::~VertexPacked() { }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const InsideOutsideDomain& param) {
      return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::getInsideOutsideDomainMapping() {
      return rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping();
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const RefinementControl& param) {
      return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::getRefinementControlMapping() {
      return rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping();
   }
   
   
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::toString (std::ostream& out) const {
      out << "("; 
      out << "rhs:" << getRhs();
      out << ",";
      out << "u:" << getU();
      out << ",";
      out << "residual:" << getResidual();
      out << ",";
      out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
      out << ",";
      out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
      out << ",";
      out << "isHangingNode:" << getIsHangingNode();
      out << ",";
      out << "refinementControl:" << toString(getRefinementControl());
      out << ",";
      out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
      out << ",";
      out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
      out << ",";
      out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
      out << ",";
      out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
      out << ",";
      out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
      out << ",";
      out << "level:" << getLevel();
      out << ",";
      out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords rotatingheatsource::expliciteuler::records::VertexPacked::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::Vertex rotatingheatsource::expliciteuler::records::VertexPacked::convert() const{
      return Vertex(
         getRhs(),
         getU(),
         getResidual(),
         getStencil(),
         getLinearSurplus(),
         getIsHangingNode(),
         getRefinementControl(),
         getAdjacentCellsHeight(),
         getAdjacentCellsHeightOfPreviousIteration(),
         getNumberOfAdjacentRefinedCells(),
         getInsideOutsideDomain(),
         getX(),
         getLevel(),
         getAdjacentRanks()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::VertexPacked::_log( "rotatingheatsource::expliciteuler::records::VertexPacked" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::initDatatype() {
         {
            VertexPacked dummyVertexPacked[2];
            
            const int Attributes = 10;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //linearSurplus
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_SHORT,		 //_packedRecords0
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               DIMENSIONS,		 //linearSurplus
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //_packedRecords0
               1,		 //residual
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[9] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
            MPI_Type_commit( &VertexPacked::Datatype );
            
         }
         {
            VertexPacked dummyVertexPacked[2];
            
            const int Attributes = 13;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //stencil
               MPI_DOUBLE,		 //linearSurplus
               MPI_INT,		 //adjacentCellsHeight
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_SHORT,		 //_packedRecords0
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               THREE_POWER_D,		 //stencil
               DIMENSIONS,		 //linearSurplus
               1,		 //adjacentCellsHeight
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //_packedRecords0
               1,		 //residual
               1,		 //adjacentCellsHeightOfPreviousIteration
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._stencil[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[12] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
            MPI_Type_commit( &VertexPacked::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::shutdownDatatype() {
         MPI_Type_free( &VertexPacked::Datatype );
         MPI_Type_free( &VertexPacked::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::VertexPacked "
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
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::VertexPacked "
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
               "rotatingheatsource::expliciteuler::records::VertexPacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::VertexPacked",
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
      
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::VertexPacked from node "
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
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::VertexPacked failed: "
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
               "rotatingheatsource::expliciteuler::records::VertexPacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::VertexPacked",
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
      
      
      
      bool rotatingheatsource::expliciteuler::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      
      int rotatingheatsource::expliciteuler::records::VertexPacked::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   
#elif !defined(Parallel) && !defined(Asserts)
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
   _rhs(rhs),
   _u(u),
   _stencil(stencil),
   _linearSurplus(linearSurplus),
   _isHangingNode(isHangingNode),
   _refinementControl(refinementControl),
   _adjacentCellsHeight(adjacentCellsHeight),
   _insideOutsideDomain(insideOutsideDomain) {
      
   }
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex() {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain) {
      
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain),_residual(residual),
   _adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
   _numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
      
   }
   
   rotatingheatsource::expliciteuler::records::Vertex::~Vertex() { }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const InsideOutsideDomain& param) {
      switch (param) {
         case Inside: return "Inside";
         case Boundary: return "Boundary";
         case Outside: return "Outside";
      }
      return "undefined";
   }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping() {
      return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
   }
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const RefinementControl& param) {
      switch (param) {
         case Unrefined: return "Unrefined";
         case Refined: return "Refined";
         case RefinementTriggered: return "RefinementTriggered";
         case Refining: return "Refining";
         case EraseTriggered: return "EraseTriggered";
         case Erasing: return "Erasing";
         case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
      }
      return "undefined";
   }
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping() {
      return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
   }
   
   
   std::string rotatingheatsource::expliciteuler::records::Vertex::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::Vertex::toString (std::ostream& out) const {
      out << "("; 
      out << "rhs:" << getRhs();
      out << ",";
      out << "u:" << getU();
      out << ",";
      out << "residual:" << getResidual();
      out << ",";
      out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
      out << ",";
      out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
      out << ",";
      out << "isHangingNode:" << getIsHangingNode();
      out << ",";
      out << "refinementControl:" << toString(getRefinementControl());
      out << ",";
      out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
      out << ",";
      out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
      out << ",";
      out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
      out << ",";
      out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords rotatingheatsource::expliciteuler::records::Vertex::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked rotatingheatsource::expliciteuler::records::Vertex::convert() const{
      return VertexPacked(
         getRhs(),
         getU(),
         getResidual(),
         getStencil(),
         getLinearSurplus(),
         getIsHangingNode(),
         getRefinementControl(),
         getAdjacentCellsHeight(),
         getAdjacentCellsHeightOfPreviousIteration(),
         getNumberOfAdjacentRefinedCells(),
         getInsideOutsideDomain()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::Vertex::_log( "rotatingheatsource::expliciteuler::records::Vertex" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::initDatatype() {
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 6;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //linearSurplus
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               DIMENSIONS,		 //linearSurplus
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //residual
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertex[1]._persistentRecords._linearSurplus[0])), 		&disp[5] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
            MPI_Type_commit( &Vertex::Datatype );
            
         }
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 12;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //stencil
               MPI_DOUBLE,		 //linearSurplus
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_INT,		 //adjacentCellsHeight
               MPI_INT,		 //insideOutsideDomain
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               THREE_POWER_D,		 //stencil
               DIMENSIONS,		 //linearSurplus
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //adjacentCellsHeight
               1,		 //insideOutsideDomain
               1,		 //residual
               1,		 //adjacentCellsHeightOfPreviousIteration
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._stencil[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[11] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
            MPI_Type_commit( &Vertex::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::shutdownDatatype() {
         MPI_Type_free( &Vertex::Datatype );
         MPI_Type_free( &Vertex::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::Vertex "
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
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::Vertex "
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
               "rotatingheatsource::expliciteuler::records::Vertex",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::Vertex",
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
      
      
      
      void rotatingheatsource::expliciteuler::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::Vertex from node "
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
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::Vertex failed: "
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
               "rotatingheatsource::expliciteuler::records::Vertex",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::Vertex",
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
      
      
      
      bool rotatingheatsource::expliciteuler::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      
      int rotatingheatsource::expliciteuler::records::Vertex::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
   _rhs(rhs),
   _u(u),
   _stencil(stencil),
   _linearSurplus(linearSurplus),
   _adjacentCellsHeight(adjacentCellsHeight) {
      setIsHangingNode(isHangingNode);
      setRefinementControl(refinementControl);
      setInsideOutsideDomain(insideOutsideDomain);
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked() {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain()) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain):
   _persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain),_residual(residual),
   _adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
   _numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
      assertion((6 < (8 * sizeof(short int))));
      
   }
   
   rotatingheatsource::expliciteuler::records::VertexPacked::~VertexPacked() { }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const InsideOutsideDomain& param) {
      return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::getInsideOutsideDomainMapping() {
      return rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping();
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const RefinementControl& param) {
      return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
   }
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::getRefinementControlMapping() {
      return rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping();
   }
   
   
   
   std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::toString (std::ostream& out) const {
      out << "("; 
      out << "rhs:" << getRhs();
      out << ",";
      out << "u:" << getU();
      out << ",";
      out << "residual:" << getResidual();
      out << ",";
      out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
      out << ",";
      out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
      out << ",";
      out << "isHangingNode:" << getIsHangingNode();
      out << ",";
      out << "refinementControl:" << toString(getRefinementControl());
      out << ",";
      out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
      out << ",";
      out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
      out << ",";
      out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
      out << ",";
      out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
      out <<  ")";
   }
   
   
   rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords rotatingheatsource::expliciteuler::records::VertexPacked::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   rotatingheatsource::expliciteuler::records::Vertex rotatingheatsource::expliciteuler::records::VertexPacked::convert() const{
      return Vertex(
         getRhs(),
         getU(),
         getResidual(),
         getStencil(),
         getLinearSurplus(),
         getIsHangingNode(),
         getRefinementControl(),
         getAdjacentCellsHeight(),
         getAdjacentCellsHeightOfPreviousIteration(),
         getNumberOfAdjacentRefinedCells(),
         getInsideOutsideDomain()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log rotatingheatsource::expliciteuler::records::VertexPacked::_log( "rotatingheatsource::expliciteuler::records::VertexPacked" );
      
      MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::Datatype = 0;
      MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::FullDatatype = 0;
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::initDatatype() {
         {
            VertexPacked dummyVertexPacked[2];
            
            const int Attributes = 5;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //linearSurplus
               MPI_SHORT,		 //_packedRecords0
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               DIMENSIONS,		 //linearSurplus
               1,		 //_packedRecords0
               1,		 //residual
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertexPacked[1]._persistentRecords._linearSurplus[0])), 		&disp[4] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
            MPI_Type_commit( &VertexPacked::Datatype );
            
         }
         {
            VertexPacked dummyVertexPacked[2];
            
            const int Attributes = 10;
            MPI_Datatype subtypes[Attributes] = {
               MPI_DOUBLE,		 //rhs
               MPI_DOUBLE,		 //u
               MPI_DOUBLE,		 //stencil
               MPI_DOUBLE,		 //linearSurplus
               MPI_INT,		 //adjacentCellsHeight
               MPI_SHORT,		 //_packedRecords0
               MPI_DOUBLE,		 //residual
               MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //rhs
               1,		 //u
               THREE_POWER_D,		 //stencil
               DIMENSIONS,		 //linearSurplus
               1,		 //adjacentCellsHeight
               1,		 //_packedRecords0
               1,		 //residual
               1,		 //adjacentCellsHeightOfPreviousIteration
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._stencil[0]))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[9] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
            MPI_Type_commit( &VertexPacked::FullDatatype );
            
         }
         
      }
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::shutdownDatatype() {
         MPI_Type_free( &VertexPacked::Datatype );
         MPI_Type_free( &VertexPacked::FullDatatype );
         
      }
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "was not able to send message rotatingheatsource::expliciteuler::records::VertexPacked "
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
               msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::VertexPacked "
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
               "rotatingheatsource::expliciteuler::records::VertexPacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::VertexPacked",
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
      
      
      
      void rotatingheatsource::expliciteuler::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
            msg << "failed to start to receive rotatingheatsource::expliciteuler::records::VertexPacked from node "
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
               msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::VertexPacked failed: "
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
               "rotatingheatsource::expliciteuler::records::VertexPacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "rotatingheatsource::expliciteuler::records::VertexPacked",
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
      
      
      
      bool rotatingheatsource::expliciteuler::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      
      int rotatingheatsource::expliciteuler::records::VertexPacked::getSenderRank() const {
         assertion( _senderDestinationRank!=-1 );
         return _senderDestinationRank;
         
      }
   #endif
   
   
   

#elif !defined(Parallel) && defined(Asserts)
rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords() {
   
}


rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_rhs(rhs),
_u(u),
_stencil(stencil),
_linearSurplus(linearSurplus),
_isHangingNode(isHangingNode),
_refinementControl(refinementControl),
_adjacentCellsHeight(adjacentCellsHeight),
_insideOutsideDomain(insideOutsideDomain),
_x(x),
_level(level) {
   
}

rotatingheatsource::expliciteuler::records::Vertex::Vertex() {
   
}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._x, persistentRecords._level) {
   
}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level) {
   
}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level),_residual(residual),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
   
}

rotatingheatsource::expliciteuler::records::Vertex::~Vertex() { }

std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const InsideOutsideDomain& param) {
   switch (param) {
      case Inside: return "Inside";
      case Boundary: return "Boundary";
      case Outside: return "Outside";
   }
   return "undefined";
}

std::string rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping() {
   return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
}
std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const RefinementControl& param) {
   switch (param) {
      case Unrefined: return "Unrefined";
      case Refined: return "Refined";
      case RefinementTriggered: return "RefinementTriggered";
      case Refining: return "Refining";
      case EraseTriggered: return "EraseTriggered";
      case Erasing: return "Erasing";
      case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
   }
   return "undefined";
}

std::string rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping() {
   return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
}


std::string rotatingheatsource::expliciteuler::records::Vertex::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::Vertex::toString (std::ostream& out) const {
   out << "("; 
   out << "rhs:" << getRhs();
   out << ",";
   out << "u:" << getU();
   out << ",";
   out << "residual:" << getResidual();
   out << ",";
   out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
   out << ",";
   out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
   out << ",";
   out << "isHangingNode:" << getIsHangingNode();
   out << ",";
   out << "refinementControl:" << toString(getRefinementControl());
   out << ",";
   out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
   out << ",";
   out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
   out << ",";
   out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
   out << ",";
   out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
   out << ",";
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "level:" << getLevel();
   out <<  ")";
}


rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords rotatingheatsource::expliciteuler::records::Vertex::getPersistentRecords() const {
   return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::VertexPacked rotatingheatsource::expliciteuler::records::Vertex::convert() const{
   return VertexPacked(
      getRhs(),
      getU(),
      getResidual(),
      getStencil(),
      getLinearSurplus(),
      getIsHangingNode(),
      getRefinementControl(),
      getAdjacentCellsHeight(),
      getAdjacentCellsHeightOfPreviousIteration(),
      getNumberOfAdjacentRefinedCells(),
      getInsideOutsideDomain(),
      getX(),
      getLevel()
   );
}

#ifdef Parallel
   tarch::logging::Log rotatingheatsource::expliciteuler::records::Vertex::_log( "rotatingheatsource::expliciteuler::records::Vertex" );
   
   MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::Datatype = 0;
   MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::FullDatatype = 0;
   
   
   void rotatingheatsource::expliciteuler::records::Vertex::initDatatype() {
      {
         Vertex dummyVertex[2];
         
         const int Attributes = 11;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //rhs
            MPI_DOUBLE,		 //u
            MPI_DOUBLE,		 //linearSurplus
            MPI_CHAR,		 //isHangingNode
            MPI_INT,		 //refinementControl
            MPI_INT,		 //insideOutsideDomain
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_DOUBLE,		 //residual
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //rhs
            1,		 //u
            DIMENSIONS,		 //linearSurplus
            1,		 //isHangingNode
            1,		 //refinementControl
            1,		 //insideOutsideDomain
            DIMENSIONS,		 //x
            1,		 //level
            1,		 //residual
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[10] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
         MPI_Type_commit( &Vertex::Datatype );
         
      }
      {
         Vertex dummyVertex[2];
         
         const int Attributes = 14;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //rhs
            MPI_DOUBLE,		 //u
            MPI_DOUBLE,		 //stencil
            MPI_DOUBLE,		 //linearSurplus
            MPI_CHAR,		 //isHangingNode
            MPI_INT,		 //refinementControl
            MPI_INT,		 //adjacentCellsHeight
            MPI_INT,		 //insideOutsideDomain
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_DOUBLE,		 //residual
            MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //rhs
            1,		 //u
            THREE_POWER_D,		 //stencil
            DIMENSIONS,		 //linearSurplus
            1,		 //isHangingNode
            1,		 //refinementControl
            1,		 //adjacentCellsHeight
            1,		 //insideOutsideDomain
            DIMENSIONS,		 //x
            1,		 //level
            1,		 //residual
            1,		 //adjacentCellsHeightOfPreviousIteration
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._stencil[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[10] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[11] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[12] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[13] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
         MPI_Type_commit( &Vertex::FullDatatype );
         
      }
      
   }
   
   
   void rotatingheatsource::expliciteuler::records::Vertex::shutdownDatatype() {
      MPI_Type_free( &Vertex::Datatype );
      MPI_Type_free( &Vertex::FullDatatype );
      
   }
   
   void rotatingheatsource::expliciteuler::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "was not able to send message rotatingheatsource::expliciteuler::records::Vertex "
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
            msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::Vertex "
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
            "rotatingheatsource::expliciteuler::records::Vertex",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::Vertex",
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
   
   
   
   void rotatingheatsource::expliciteuler::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "failed to start to receive rotatingheatsource::expliciteuler::records::Vertex from node "
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
            msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::Vertex failed: "
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
            "rotatingheatsource::expliciteuler::records::Vertex",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::Vertex",
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
   
   
   
   bool rotatingheatsource::expliciteuler::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   int rotatingheatsource::expliciteuler::records::Vertex::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords() {
   assertion((6 < (8 * sizeof(short int))));
   
}


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_rhs(rhs),
_u(u),
_stencil(stencil),
_linearSurplus(linearSurplus),
_adjacentCellsHeight(adjacentCellsHeight),
_x(x),
_level(level) {
   setIsHangingNode(isHangingNode);
   setRefinementControl(refinementControl);
   setInsideOutsideDomain(insideOutsideDomain);
   assertion((6 < (8 * sizeof(short int))));
   
}

rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked() {
   assertion((6 < (8 * sizeof(short int))));
   
}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._x, persistentRecords._level) {
   assertion((6 < (8 * sizeof(short int))));
   
}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level) {
   assertion((6 < (8 * sizeof(short int))));
   
}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level),_residual(residual),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
   assertion((6 < (8 * sizeof(short int))));
   
}

rotatingheatsource::expliciteuler::records::VertexPacked::~VertexPacked() { }

std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const InsideOutsideDomain& param) {
   return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::getInsideOutsideDomainMapping() {
   return rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping();
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const RefinementControl& param) {
   return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::getRefinementControlMapping() {
   return rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping();
}



std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::VertexPacked::toString (std::ostream& out) const {
   out << "("; 
   out << "rhs:" << getRhs();
   out << ",";
   out << "u:" << getU();
   out << ",";
   out << "residual:" << getResidual();
   out << ",";
   out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
   out << ",";
   out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
   out << ",";
   out << "isHangingNode:" << getIsHangingNode();
   out << ",";
   out << "refinementControl:" << toString(getRefinementControl());
   out << ",";
   out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
   out << ",";
   out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
   out << ",";
   out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
   out << ",";
   out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
   out << ",";
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "level:" << getLevel();
   out <<  ")";
}


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords rotatingheatsource::expliciteuler::records::VertexPacked::getPersistentRecords() const {
   return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::Vertex rotatingheatsource::expliciteuler::records::VertexPacked::convert() const{
   return Vertex(
      getRhs(),
      getU(),
      getResidual(),
      getStencil(),
      getLinearSurplus(),
      getIsHangingNode(),
      getRefinementControl(),
      getAdjacentCellsHeight(),
      getAdjacentCellsHeightOfPreviousIteration(),
      getNumberOfAdjacentRefinedCells(),
      getInsideOutsideDomain(),
      getX(),
      getLevel()
   );
}

#ifdef Parallel
   tarch::logging::Log rotatingheatsource::expliciteuler::records::VertexPacked::_log( "rotatingheatsource::expliciteuler::records::VertexPacked" );
   
   MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::Datatype = 0;
   MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::FullDatatype = 0;
   
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::initDatatype() {
      {
         VertexPacked dummyVertexPacked[2];
         
         const int Attributes = 9;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //rhs
            MPI_DOUBLE,		 //u
            MPI_DOUBLE,		 //linearSurplus
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_SHORT,		 //_packedRecords0
            MPI_DOUBLE,		 //residual
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //rhs
            1,		 //u
            DIMENSIONS,		 //linearSurplus
            DIMENSIONS,		 //x
            1,		 //level
            1,		 //_packedRecords0
            1,		 //residual
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[8] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
         MPI_Type_commit( &VertexPacked::Datatype );
         
      }
      {
         VertexPacked dummyVertexPacked[2];
         
         const int Attributes = 12;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //rhs
            MPI_DOUBLE,		 //u
            MPI_DOUBLE,		 //stencil
            MPI_DOUBLE,		 //linearSurplus
            MPI_INT,		 //adjacentCellsHeight
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_SHORT,		 //_packedRecords0
            MPI_DOUBLE,		 //residual
            MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //rhs
            1,		 //u
            THREE_POWER_D,		 //stencil
            DIMENSIONS,		 //linearSurplus
            1,		 //adjacentCellsHeight
            DIMENSIONS,		 //x
            1,		 //level
            1,		 //_packedRecords0
            1,		 //residual
            1,		 //adjacentCellsHeightOfPreviousIteration
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._stencil[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[10] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[11] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
         MPI_Type_commit( &VertexPacked::FullDatatype );
         
      }
      
   }
   
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::shutdownDatatype() {
      MPI_Type_free( &VertexPacked::Datatype );
      MPI_Type_free( &VertexPacked::FullDatatype );
      
   }
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "was not able to send message rotatingheatsource::expliciteuler::records::VertexPacked "
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
            msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::VertexPacked "
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
            "rotatingheatsource::expliciteuler::records::VertexPacked",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::VertexPacked",
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
   
   
   
   void rotatingheatsource::expliciteuler::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
         msg << "failed to start to receive rotatingheatsource::expliciteuler::records::VertexPacked from node "
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
            msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::VertexPacked failed: "
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
            "rotatingheatsource::expliciteuler::records::VertexPacked",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "rotatingheatsource::expliciteuler::records::VertexPacked",
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
   
   
   
   bool rotatingheatsource::expliciteuler::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   int rotatingheatsource::expliciteuler::records::VertexPacked::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif




#elif defined(Parallel) && !defined(Asserts)
rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords() {

}


rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_rhs(rhs),
_u(u),
_stencil(stencil),
_linearSurplus(linearSurplus),
_isHangingNode(isHangingNode),
_refinementControl(refinementControl),
_adjacentCellsHeight(adjacentCellsHeight),
_insideOutsideDomain(insideOutsideDomain),
_adjacentRanks(adjacentRanks) {

}

rotatingheatsource::expliciteuler::records::Vertex::Vertex() {

}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._adjacentRanks) {

}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks) {

}


rotatingheatsource::expliciteuler::records::Vertex::Vertex(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks),_residual(residual),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {

}

rotatingheatsource::expliciteuler::records::Vertex::~Vertex() { }

std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const InsideOutsideDomain& param) {
switch (param) {
   case Inside: return "Inside";
   case Boundary: return "Boundary";
   case Outside: return "Outside";
}
return "undefined";
}

std::string rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping() {
return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
}
std::string rotatingheatsource::expliciteuler::records::Vertex::toString(const RefinementControl& param) {
switch (param) {
   case Unrefined: return "Unrefined";
   case Refined: return "Refined";
   case RefinementTriggered: return "RefinementTriggered";
   case Refining: return "Refining";
   case EraseTriggered: return "EraseTriggered";
   case Erasing: return "Erasing";
   case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
}
return "undefined";
}

std::string rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping() {
return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
}


std::string rotatingheatsource::expliciteuler::records::Vertex::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::Vertex::toString (std::ostream& out) const {
out << "("; 
out << "rhs:" << getRhs();
out << ",";
out << "u:" << getU();
out << ",";
out << "residual:" << getResidual();
out << ",";
out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
out << ",";
out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
out <<  ")";
}


rotatingheatsource::expliciteuler::records::Vertex::PersistentRecords rotatingheatsource::expliciteuler::records::Vertex::getPersistentRecords() const {
return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::VertexPacked rotatingheatsource::expliciteuler::records::Vertex::convert() const{
return VertexPacked(
   getRhs(),
   getU(),
   getResidual(),
   getStencil(),
   getLinearSurplus(),
   getIsHangingNode(),
   getRefinementControl(),
   getAdjacentCellsHeight(),
   getAdjacentCellsHeightOfPreviousIteration(),
   getNumberOfAdjacentRefinedCells(),
   getInsideOutsideDomain(),
   getAdjacentRanks()
);
}

#ifdef Parallel
tarch::logging::Log rotatingheatsource::expliciteuler::records::Vertex::_log( "rotatingheatsource::expliciteuler::records::Vertex" );

MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::Datatype = 0;
MPI_Datatype rotatingheatsource::expliciteuler::records::Vertex::FullDatatype = 0;


void rotatingheatsource::expliciteuler::records::Vertex::initDatatype() {
   {
      Vertex dummyVertex[2];
      
      const int Attributes = 7;
      MPI_Datatype subtypes[Attributes] = {
         MPI_DOUBLE,		 //linearSurplus
         MPI_CHAR,		 //isHangingNode
         MPI_INT,		 //refinementControl
         MPI_INT,		 //adjacentRanks
         MPI_DOUBLE,		 //residual
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         DIMENSIONS,		 //linearSurplus
         1,		 //isHangingNode
         1,		 //refinementControl
         TWO_POWER_D,		 //adjacentRanks
         1,		 //residual
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertex[1]._persistentRecords._linearSurplus[0])), 		&disp[6] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
      MPI_Type_commit( &Vertex::Datatype );
      
   }
   {
      Vertex dummyVertex[2];
      
      const int Attributes = 13;
      MPI_Datatype subtypes[Attributes] = {
         MPI_DOUBLE,		 //rhs
         MPI_DOUBLE,		 //u
         MPI_DOUBLE,		 //stencil
         MPI_DOUBLE,		 //linearSurplus
         MPI_CHAR,		 //isHangingNode
         MPI_INT,		 //refinementControl
         MPI_INT,		 //adjacentCellsHeight
         MPI_INT,		 //insideOutsideDomain
         MPI_INT,		 //adjacentRanks
         MPI_DOUBLE,		 //residual
         MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //rhs
         1,		 //u
         THREE_POWER_D,		 //stencil
         DIMENSIONS,		 //linearSurplus
         1,		 //isHangingNode
         1,		 //refinementControl
         1,		 //adjacentCellsHeight
         1,		 //insideOutsideDomain
         TWO_POWER_D,		 //adjacentRanks
         1,		 //residual
         1,		 //adjacentCellsHeightOfPreviousIteration
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._rhs))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._u))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._stencil[0]))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[6] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[7] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[8] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._residual))), 		&disp[9] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[10] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[11] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._rhs))), 		&disp[12] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
      MPI_Type_commit( &Vertex::FullDatatype );
      
   }
   
}


void rotatingheatsource::expliciteuler::records::Vertex::shutdownDatatype() {
   MPI_Type_free( &Vertex::Datatype );
   MPI_Type_free( &Vertex::FullDatatype );
   
}

void rotatingheatsource::expliciteuler::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      msg << "was not able to send message rotatingheatsource::expliciteuler::records::Vertex "
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
         msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::Vertex "
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
         "rotatingheatsource::expliciteuler::records::Vertex",
         "send(int)", destination,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "rotatingheatsource::expliciteuler::records::Vertex",
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



void rotatingheatsource::expliciteuler::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      msg << "failed to start to receive rotatingheatsource::expliciteuler::records::Vertex from node "
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
         msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::Vertex failed: "
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
         "rotatingheatsource::expliciteuler::records::Vertex",
         "receive(int)", source,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "rotatingheatsource::expliciteuler::records::Vertex",
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



bool rotatingheatsource::expliciteuler::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int rotatingheatsource::expliciteuler::records::Vertex::getSenderRank() const {
   assertion( _senderDestinationRank!=-1 );
   return _senderDestinationRank;
   
}
#endif


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords() {
assertion((6 < (8 * sizeof(short int))));

}


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords::PersistentRecords(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_rhs(rhs),
_u(u),
_stencil(stencil),
_linearSurplus(linearSurplus),
_adjacentCellsHeight(adjacentCellsHeight),
_adjacentRanks(adjacentRanks) {
setIsHangingNode(isHangingNode);
setRefinementControl(refinementControl);
setInsideOutsideDomain(insideOutsideDomain);
assertion((6 < (8 * sizeof(short int))));

}

rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked() {
assertion((6 < (8 * sizeof(short int))));

}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._rhs, persistentRecords._u, persistentRecords._stencil, persistentRecords._linearSurplus, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._adjacentRanks) {
assertion((6 < (8 * sizeof(short int))));

}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks) {
assertion((6 < (8 * sizeof(short int))));

}


rotatingheatsource::expliciteuler::records::VertexPacked::VertexPacked(const double& rhs, const double& u, const double& residual, const tarch::la::Vector<THREE_POWER_D,double>& stencil, const tarch::la::Vector<DIMENSIONS,double>& linearSurplus, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks):
_persistentRecords(rhs, u, stencil, linearSurplus, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks),_residual(residual),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
assertion((6 < (8 * sizeof(short int))));

}

rotatingheatsource::expliciteuler::records::VertexPacked::~VertexPacked() { }

std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const InsideOutsideDomain& param) {
return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::getInsideOutsideDomainMapping() {
return rotatingheatsource::expliciteuler::records::Vertex::getInsideOutsideDomainMapping();
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString(const RefinementControl& param) {
return rotatingheatsource::expliciteuler::records::Vertex::toString(param);
}

std::string rotatingheatsource::expliciteuler::records::VertexPacked::getRefinementControlMapping() {
return rotatingheatsource::expliciteuler::records::Vertex::getRefinementControlMapping();
}



std::string rotatingheatsource::expliciteuler::records::VertexPacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void rotatingheatsource::expliciteuler::records::VertexPacked::toString (std::ostream& out) const {
out << "("; 
out << "rhs:" << getRhs();
out << ",";
out << "u:" << getU();
out << ",";
out << "residual:" << getResidual();
out << ",";
out << "stencil:[";
   for (int i = 0; i < THREE_POWER_D-1; i++) {
      out << getStencil(i) << ",";
   }
   out << getStencil(THREE_POWER_D-1) << "]";
out << ",";
out << "linearSurplus:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getLinearSurplus(i) << ",";
   }
   out << getLinearSurplus(DIMENSIONS-1) << "]";
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
out <<  ")";
}


rotatingheatsource::expliciteuler::records::VertexPacked::PersistentRecords rotatingheatsource::expliciteuler::records::VertexPacked::getPersistentRecords() const {
return _persistentRecords;
}

rotatingheatsource::expliciteuler::records::Vertex rotatingheatsource::expliciteuler::records::VertexPacked::convert() const{
return Vertex(
   getRhs(),
   getU(),
   getResidual(),
   getStencil(),
   getLinearSurplus(),
   getIsHangingNode(),
   getRefinementControl(),
   getAdjacentCellsHeight(),
   getAdjacentCellsHeightOfPreviousIteration(),
   getNumberOfAdjacentRefinedCells(),
   getInsideOutsideDomain(),
   getAdjacentRanks()
);
}

#ifdef Parallel
tarch::logging::Log rotatingheatsource::expliciteuler::records::VertexPacked::_log( "rotatingheatsource::expliciteuler::records::VertexPacked" );

MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::Datatype = 0;
MPI_Datatype rotatingheatsource::expliciteuler::records::VertexPacked::FullDatatype = 0;


void rotatingheatsource::expliciteuler::records::VertexPacked::initDatatype() {
   {
      VertexPacked dummyVertexPacked[2];
      
      const int Attributes = 6;
      MPI_Datatype subtypes[Attributes] = {
         MPI_DOUBLE,		 //linearSurplus
         MPI_INT,		 //adjacentRanks
         MPI_SHORT,		 //_packedRecords0
         MPI_DOUBLE,		 //residual
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         DIMENSIONS,		 //linearSurplus
         TWO_POWER_D,		 //adjacentRanks
         1,		 //_packedRecords0
         1,		 //residual
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertexPacked[1]._persistentRecords._linearSurplus[0])), 		&disp[5] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
      MPI_Type_commit( &VertexPacked::Datatype );
      
   }
   {
      VertexPacked dummyVertexPacked[2];
      
      const int Attributes = 11;
      MPI_Datatype subtypes[Attributes] = {
         MPI_DOUBLE,		 //rhs
         MPI_DOUBLE,		 //u
         MPI_DOUBLE,		 //stencil
         MPI_DOUBLE,		 //linearSurplus
         MPI_INT,		 //adjacentCellsHeight
         MPI_INT,		 //adjacentRanks
         MPI_SHORT,		 //_packedRecords0
         MPI_DOUBLE,		 //residual
         MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //rhs
         1,		 //u
         THREE_POWER_D,		 //stencil
         DIMENSIONS,		 //linearSurplus
         1,		 //adjacentCellsHeight
         TWO_POWER_D,		 //adjacentRanks
         1,		 //_packedRecords0
         1,		 //residual
         1,		 //adjacentCellsHeightOfPreviousIteration
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._rhs))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._u))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._stencil[0]))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._linearSurplus[0]))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[6] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._residual))), 		&disp[7] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[8] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[9] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._rhs))), 		&disp[10] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
      MPI_Type_commit( &VertexPacked::FullDatatype );
      
   }
   
}


void rotatingheatsource::expliciteuler::records::VertexPacked::shutdownDatatype() {
   MPI_Type_free( &VertexPacked::Datatype );
   MPI_Type_free( &VertexPacked::FullDatatype );
   
}

void rotatingheatsource::expliciteuler::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      msg << "was not able to send message rotatingheatsource::expliciteuler::records::VertexPacked "
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
         msg << "testing for finished send task for rotatingheatsource::expliciteuler::records::VertexPacked "
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
         "rotatingheatsource::expliciteuler::records::VertexPacked",
         "send(int)", destination,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "rotatingheatsource::expliciteuler::records::VertexPacked",
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



void rotatingheatsource::expliciteuler::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
      msg << "failed to start to receive rotatingheatsource::expliciteuler::records::VertexPacked from node "
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
         msg << "testing for finished receive task for rotatingheatsource::expliciteuler::records::VertexPacked failed: "
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
         "rotatingheatsource::expliciteuler::records::VertexPacked",
         "receive(int)", source,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "rotatingheatsource::expliciteuler::records::VertexPacked",
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



bool rotatingheatsource::expliciteuler::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int rotatingheatsource::expliciteuler::records::VertexPacked::getSenderRank() const {
   assertion( _senderDestinationRank!=-1 );
   return _senderDestinationRank;
   
}
#endif




#endif


