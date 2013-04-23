#include <valarray>

#include "rotatingheatsource/SinTrajectory.h"

SinTrajectory2D::SinTrajectory2D(double x, const tarch::la::Vector<2,double>& yRange, const tarch::la::Vector<2,double>& zRange,
                                 int numwaves, double velocity)
{
    _xOffset = x;
    _yRange = yRange;
    _zRange = zRange;
    _numwaves = numwaves;
    _velocity = velocity;
}
 
SinTrajectory2D::~SinTrajectory2D() {

}

tarch::la::Vector<3,double> SinTrajectory2D::getPosition(double t) {
    tarch::la::Vector<3,double> position;

    double yPos = 0.0;
    double zPos = 0.0;

    double yLength = (_yRange(1) - _yRange(0));
    double zLength = (_zRange(1) - _zRange(0));
  
    double zAmplitude = zLength * 0.5;
    double zCenter = _zRange(0) + zAmplitude;

    double totaldistance = _velocity * t;
    int directionchanged = (int)(totaldistance / yLength);

    double remainingdistance = totaldistance - directionchanged * yLength;
    double zCoefficient = _numwaves * (2 * tarch::la::PI) / yLength;

    // determine y and z position on plane
    if (directionchanged % 2 == 0) {
        // moving forward
        yPos = _yRange(0) + remainingdistance;

        double rad = zCoefficient * remainingdistance;
        zPos = zCenter + zAmplitude * std::sin(rad);
    } else {
        // moving backward and invert wave
        yPos = _yRange(1) - remainingdistance;

        double rad = zCoefficient * (yLength - remainingdistance);
        zPos = zCenter - zAmplitude * std::sin(rad);
    }

    position(0) = _xOffset;
    position(1) = yPos;
    position(2) = zPos;

    return position;
}
