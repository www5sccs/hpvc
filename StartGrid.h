// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_START_GRID_H_
#define _ROTATINGHEATSOURCE_START_GRID_H_


#include "tarch/la/Vector.h"
#include "peano/utils/Dimensions.h"


namespace rotatingheatsource {
  class StartGrid;
}


class rotatingheatsource::StartGrid {
  public:
    virtual ~StartGrid() {}

    virtual tarch::la::Vector<DIMENSIONS,double>   getDomainSize() const = 0;
    virtual tarch::la::Vector<DIMENSIONS,double>   getComputationalDomainOffset() const = 0;
    virtual tarch::la::Vector<DIMENSIONS,double>   getMinimalMeshSize() const = 0;
    virtual tarch::la::Vector<DIMENSIONS,double>   getMaximalMeshSize() const = 0;

    /**
     * Shall the grid be refined here?
     *
     * This operation is given a position in the computational domain together
     * with its surrounding box (specified by the tuple (x,h)). This method
     * tells Peano whether Peano should refine here further or not. The
     * operation only is called if the grid is not coarser than the maximum
     * mesh size and not finer than the minimum mesh size. In either case, this
     * information is meaningless.
     *
     * The isBoundary flag allows you to react to voxels that intersect the
     * domain's boundary. Sometimes, you implement a different refinement
     * strategy for those voxels.
     *
     * @param x           Centre of the test voxel
     * @param h           Size of the test voxel
     * @param isBoundary  Tells you whether the test voxel intersects the boundary
     */
    virtual bool refinedStartGridAt(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& h, bool isBoundary) = 0;
};


#endif
