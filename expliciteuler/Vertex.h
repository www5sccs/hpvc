// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EXPLICITEULER_VERTEX_H_ 
#define _ROTATINGHEATSOURCE_EXPLICITEULER_VERTEX_H_


#include "rotatingheatsource/expliciteuler/records/Vertex.h"
#include "peano/grid/Vertex.h"
#include "peano/grid/VertexEnumerator.h"
#include "peano/utils/Globals.h"
#include "matrixfree/stencil/Stencil.h"


namespace rotatingheatsource { 
  namespace expliciteuler { 
    class Vertex;
  }
}


/**
 * Blueprint for grid vertex.
 * 
 * This file has originally been created by the PDT and may be manually extended to 
 * the needs of your application. We do not recommend to remove anything!
 */
class rotatingheatsource::expliciteuler::Vertex: public peano::grid::Vertex< rotatingheatsource::expliciteuler::records::Vertex > { 
  private: 
    typedef class peano::grid::Vertex< rotatingheatsource::expliciteuler::records::Vertex >  Base;

  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    Vertex();
    
    /**
     * This constructor should not set any attributes. It is used by the 
     * traversal algorithm whenever it allocates an array whose elements 
     * will be overwritten later anyway.  
     */
    Vertex(const Base::DoNotCallStandardConstructor&);
    
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
    Vertex(const Base::PersistentVertex& argument);
    
    static tarch::la::Vector<TWO_POWER_D,double>  readRhs(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices);
    static tarch::la::Vector<TWO_POWER_D,double>  readU(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices);
    static tarch::la::Vector<TWO_POWER_D,double>  readResidual(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices);

    static tarch::la::Vector<TWO_POWER_D_TIMES_D,double> readLinearSurplus(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices);


    static tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double> readStencil(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices);

    static void writeResidual(const peano::grid::VertexEnumerator& enumerator, Vertex* const vertices, const tarch::la::Vector<TWO_POWER_D,double>& values );

    static void writeLinearSurplus(const peano::grid::VertexEnumerator& enumerator, Vertex* const vertices, const tarch::la::Vector<TWO_POWER_D_TIMES_D,double>& values);



    void initialiseInnerVertex( double thermalDiffusivity, double temperature, double rhs, const tarch::la::Vector<DIMENSIONS,double>& h );
    void initialiseBoundaryVertex( double temperature );
    void initialiseHangingVertex(double interpolatedTemperature, double interpolatedRhs);

    double getTemperature() const;
    double getRhs() const;
    double getResidual() const;
    matrixfree::stencil::Stencil getStencil() const;

    void setNewRhs( double rhs );
    void setTemperature( double value );

    void clearResidual();

    void clearSurplusMeasurements();
    tarch::la::Vector<DIMENSIONS,double> getLinearSurplus() const;

    #ifdef Parallel
    /**
     * Scaling for explicit Euler
     *
     * For the explicit Euler, the residual describes the update of the
     * unknown. At the domain boundarise, it thus only describes a fraction of
     * the update stemming from the local domain. To resolve this issue, we
     * update the vertices everywhere and send away the updates (=residuals) at
     * the end of the iteration. Before the next iteration starts, we take the
     * received residuals and update the (old) temperature value once more, i.e.
     * the overall update process due to the time stepping is split up into two
     * phases: A local update that takes into account influences from the local
     * cells (at the end of the time step), and an additional update taking
     * into account contributions from remote domains (before the next iteration
     * starts).
     *
     * One problem arises as the residual is not updated directly, but it is
     * scaled with the time step size before. The code is allowed to change the
     * time step size in each iteration, i.e. it might happen that a residual is
     * sent to the neighbours with a time step size @f$ \Delta t_1 @f$, but
     * when the residual is received, the time step size is already changed to
     * @f$ \Delta t_2 @f$. In such a case, the temperature update is performed
     * with @f$ \Delta t_2 @f$, but @f$ \Delta t_1 @f$ would have been the
     * correct scaling. We resolve this issue in mergeWithNeighbour() and
     * prepareSendToNeighbour():
     *
     * - In prepareSendToNeighbour(), we scale the residual with the current
     *   time step size. This is @f$ \Delta _1 @f$ in the example above.
     * - In mergeWithNeighbour(), we scale the residual with the inverse of the
     *   current time step size. This is @f$ \Delta _2 ^{-1} @f$ in the example
     *   above.
     *
     * Both scalings use this operation.
     */
    void scaleResidual(double scaling);
    #endif

    void copyUFromFinerGrid( const Vertex& vertex );
};


#endif
