#ifndef _ROTATINGHEATSOURCE_SINTRAJECTORY_H_
#define _ROTATINGHEATSOURCE_SINTRAJECTORY_H_

#include "tarch/la/Vector.h"

class SinTrajectory2D {
    
    public:
        SinTrajectory2D(double x, const tarch::la::Vector<2,double>& yRange, const tarch::la::Vector<2,double>& zRange,
                        int numwaves, double velocity);

        virtual ~SinTrajectory2D();

        tarch::la::Vector<3,double> getPosition(double t);

    private:
        double _xOffset;
        tarch::la::Vector<2,double> _yRange;
        tarch::la::Vector<2,double> _zRange;
        int _numwaves;
        double _velocity;

};

#endif // _ROTATINGHEATSOURCE_ROTATING_HEAT_SOURCE_H_

