// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EXPLICITEULER_CELL_H_ 
#define _ROTATINGHEATSOURCE_EXPLICITEULER_CELL_H_


#include "rotatingheatsource/expliciteuler/records/Cell.h"
#include "peano/grid/Cell.h"


namespace rotatingheatsource { 
  namespace expliciteuler { 
      class Cell; 
}
}


/**
 * Blueprint for cell.
 * 
 * This file has originally been created by the PDT and may be manually extended to 
 * the needs of your application. We do not recommend to remove anything!
 */
class rotatingheatsource::expliciteuler::Cell: public peano::grid::Cell< rotatingheatsource::expliciteuler::records::Cell > { 
  private: 
    typedef class peano::grid::Cell< rotatingheatsource::expliciteuler::records::Cell >  Base;

  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    Cell();

    /**
     * This constructor should not set any attributes. It is used by the 
     * traversal algorithm whenever it allocates an array whose elements 
     * will be overwritten later anyway.  
     */
    Cell(const Base::DoNotCallStandardConstructor&);

    /**
     * Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it. It is kind of a copy constructor that converts an object which 
     * comprises solely persistent attributes into a full attribute. This very 
     * functionality is implemented within the super type, i.e. this constructor 
     * has to invoke the correponsing super type's constructor and not the super 
     * type standard constructor.
     */
    Cell(const Base::PersistentCell& argument);
    void setCellHeapId(const int heapId);
    const int getCellHeapId() const;
};


#endif
