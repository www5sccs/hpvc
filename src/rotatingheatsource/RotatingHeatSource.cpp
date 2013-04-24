#include <fstream>

#include "rotatingheatsource/RotatingHeatSource.h"
#include "peano/utils/Loop.h"

#include "tarch/la/Vector.h"
#include "tarch/parallel/Node.h"

#include "rotatingheatsource/SinTrajectory.h"

tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getDefaultDomainSize() {
	return tarch::la::Vector<DIMENSIONS,double>(1.0);
}


tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getDefaultDomainOffset() {
	return tarch::la::Vector<DIMENSIONS,double>(0.0);
}


rotatingheatsource::RotatingHeatSource::RotatingHeatSource(
		double                                       thermalDiffusivity,
		double                                       thermalDiffusivityInEmbeddedMaterial,
		double                                       stimulusSphereRadius,
		const tarch::la::Vector<DIMENSIONS,double>&  minimalMeshWidth,
		const tarch::la::Vector<DIMENSIONS,double>&  maximalMeshWidth,
		const std::string&                           outputFileName
):
										  _thermalDiffusivity(thermalDiffusivity),
										  _thermalDiffusivityInEmbeddedMaterial(thermalDiffusivityInEmbeddedMaterial),
										  _minimalMeshWidth(minimalMeshWidth),
										  _maximalMeshWidth(maximalMeshWidth),
										  _centerOfEmbeddedMaterial(0.0),
										  _embeddedMaterialRadius(0.4),
										  _stimulusCenter(0.5),
										  _stimulusRadius(stimulusSphereRadius),
										  _outputFileName(outputFileName) {
	setTime(0.0);
	_time=-1;
	tarch::la::Vector<DIMENSIONS,double> centerOfEmbeddedMaterial(0.3);

	_centerOfEmbeddedMaterial(0) = 0.1;
	_centerOfEmbeddedMaterial(1) = 0.2;

	for (int d=0; d<DIMENSIONS; d++) {
		assertion( _minimalMeshWidth(d)<=_maximalMeshWidth(d) );
	}

#ifdef VASCO
	buildingInfrastructure = new BuildingInfrastructure(getDefaultDomainSize(), getDefaultDomainOffset());
#endif
}


bool rotatingheatsource::RotatingHeatSource::domainHasChanged( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) {
	return false;
}


void rotatingheatsource::RotatingHeatSource::setTime( double t ) {
	tarch::la::Vector<DIMENSIONS,double> position(0.5);

#ifdef VASCO
    #ifdef SINTRAJECTORY
        double xOffset = 0.5;
        tarch::la::Vector<2,double> yRange(0.2, 0.6);
        tarch::la::Vector<2,double> zRange(0.433, 0.568);
        int numwaves = 1;
        double velocity = 1000;

        SinTrajectory2D trajectory(xOffset, yRange, zRange, numwaves, velocity);
        tarch::la::Vector<3,double> pos = trajectory.getPosition(t);

        if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
            std::cout << "[HEATSOURCE_POS] " << pos << std::endl;
        }

        _stimulusCenter(0) = pos(0);
        _stimulusCenter(1) = pos(1);
        _stimulusCenter(2) = pos(2);

    #else
        _stimulusCenter(0) = 0.5 + 0.8 * std::sin( 2.0 * t * tarch::la::PI );
        _stimulusCenter(1) = 0.5 + 0.8 * std::cos( 2.0 * t * tarch::la::PI );
    #endif
#else
	_stimulusCenter(0) = 0.5 + 0.3 * std::sin( 2.0 * t * tarch::la::PI );
	_stimulusCenter(1) = 0.5 + 0.3 * std::cos( 2.0 * t * tarch::la::PI );
#endif
	_time++;
}

const int rotatingheatsource::RotatingHeatSource::getTime() const{
	return _time;
}

tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getDomainSize() const {
	return getDefaultDomainSize();
}


tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getComputationalDomainOffset() const {
	return getDefaultDomainOffset();
}


tarch::la::Vector<DIMENSIONS,double>  rotatingheatsource::RotatingHeatSource::getMinimalMeshSize() const {
	return _minimalMeshWidth;
}


tarch::la::Vector<DIMENSIONS,double>  rotatingheatsource::RotatingHeatSource::getMaximalMeshSize() const {
	return _maximalMeshWidth;
}


double rotatingheatsource::RotatingHeatSource::getRhs(const tarch::la::Vector<1,double>& x) {
#ifdef Dim2
	tarch::la::Vector<2,double> y;
	y(0) = x(0);
	y(1) = 0.5;

	const double distanceSquared = (y(0)-_stimulusCenter(0)) * (y(0)-_stimulusCenter(0)) + (y(1)-_stimulusCenter(1)) * (y(1)-_stimulusCenter(1));
	if ( distanceSquared > _stimulusRadius * _stimulusRadius ) {
		return 0.0;
	}
	else {
		return 1.0;
	}
#else
	assertion(false);
	return 0.0;
#endif
}


double rotatingheatsource::RotatingHeatSource::getRhs(const tarch::la::Vector<2,double>& x) {
#ifdef Dim3
	tarch::la::Vector<3,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = 0.5;
	const double distanceSquared = (y(0)-_stimulusCenter(0)) * (y(0)-_stimulusCenter(0))
											+ (y(1)-_stimulusCenter(1)) * (y(1)-_stimulusCenter(1))
											+ (y(2)-_stimulusCenter(2)) * (y(2)-_stimulusCenter(2));
	if (distanceSquared > _stimulusRadius * _stimulusRadius) {
		return 0.0;
	}
	else {
		return 1.0;
	}
#elif Dim2
	const double distanceSquared = (x(0)-_stimulusCenter(0)) * (x(0)-_stimulusCenter(0)) + (x(1)-_stimulusCenter(1)) * (x(1)-_stimulusCenter(1));
	if (distanceSquared > _stimulusRadius * _stimulusRadius) {
		return 0.0;
	}
	else {
		return 1.0;
	}
#else
	assertion(false);
	return 0.0;
#endif
}


double rotatingheatsource::RotatingHeatSource::getRhs(const tarch::la::Vector<3,double>& x) {
#ifdef Dim4
	tarch::la::Vector<4,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = x(2);
	y(3) = 0.5;
	const double distanceSquared = (y(0)-_stimulusCenter(0)) * (y(0)-_stimulusCenter(0))
												+ (y(1)-_stimulusCenter(1)) * (y(1)-_stimulusCenter(1))
												+ (y(2)-_stimulusCenter(2)) * (y(2)-_stimulusCenter(2))
												+ (y(3)-_stimulusCenter(3)) * (y(3)-_stimulusCenter(3));
	if (distanceSquared > _stimulusRadius * _stimulusRadius) {
		return 0.0;
	}
	else {
		return 1.0;
	}
#elif Dim3
	tarch::la::Vector<3,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = x(2);
	const double distanceSquared = (y(0)-_stimulusCenter(0)) * (y(0)-_stimulusCenter(0))
													+ (y(1)-_stimulusCenter(1)) * (y(1)-_stimulusCenter(1))
													+ (y(2)-_stimulusCenter(2)) * (y(2)-_stimulusCenter(2));
	if (distanceSquared > _stimulusRadius * _stimulusRadius) {
		return 0.0;
	}
	else {
		return 1.0;
	}
#else
	assertion(false);
	return 0.0;
#endif
}


double rotatingheatsource::RotatingHeatSource::getMaximalSamplingWidth() const {
	return _stimulusRadius/2.0;
}


double rotatingheatsource::RotatingHeatSource::getInitialValue(const tarch::la::Vector<1,double>& x) const {
	return 0.0;
}


double rotatingheatsource::RotatingHeatSource::getInitialValue(const tarch::la::Vector<2,double>& x) const {
	return 0.0;
}


double rotatingheatsource::RotatingHeatSource::getInitialValue(const tarch::la::Vector<3,double>& x) const {
	return 0.0;
}


rotatingheatsource::RotatingHeatSource::BoundaryType rotatingheatsource::RotatingHeatSource::getBoundaryType(const tarch::la::Vector<1,double>& x) const {
	return DIRICHLET;
}


rotatingheatsource::RotatingHeatSource::BoundaryType rotatingheatsource::RotatingHeatSource::getBoundaryType(const tarch::la::Vector<2,double>& x) const {
	return DIRICHLET;
}


rotatingheatsource::RotatingHeatSource::BoundaryType rotatingheatsource::RotatingHeatSource::getBoundaryType(const tarch::la::Vector<3,double>& x) const {
	return DIRICHLET;
}


double rotatingheatsource::RotatingHeatSource::getThermalDiffusivity(const tarch::la::Vector<1,double>& x) {
#ifdef Dim2
	tarch::la::Vector<2,double> y;
	y(0) = x(0);
	y(1) = 0.5;

	const double distanceSquared = (y(0)-_centerOfEmbeddedMaterial(0)) * (y(0)-_centerOfEmbeddedMaterial(0)) + (y(1)-_centerOfEmbeddedMaterial(1)) * (y(1)-_centerOfEmbeddedMaterial(1));

	if (distanceSquared< _embeddedMaterialRadius*_embeddedMaterialRadius) {
		return _thermalDiffusivityInEmbeddedMaterial;
	}
	else {
		return _thermalDiffusivity;
	}
#else
	assertion(false);
	return 0.0;
#endif
}


double rotatingheatsource::RotatingHeatSource::getThermalDiffusivity(const tarch::la::Vector<2,double>& x) {
#ifdef Dim2
	const double distanceSquared = (x(0)-_centerOfEmbeddedMaterial(0)) * (x(0)-_centerOfEmbeddedMaterial(0)) + (x(1)-_centerOfEmbeddedMaterial(1)) * (x(1)-_centerOfEmbeddedMaterial(1));

	if (distanceSquared< _embeddedMaterialRadius*_embeddedMaterialRadius) {
		return _thermalDiffusivityInEmbeddedMaterial;
	}
	else {
		return _thermalDiffusivity;
	}
#elif Dim3
	tarch::la::Vector<3,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = 0.5;
	const double distanceSquared = (y(0)-_centerOfEmbeddedMaterial(0)) * (y(0)-_centerOfEmbeddedMaterial(0)) +
			(y(1)-_centerOfEmbeddedMaterial(1)) * (y(1)-_centerOfEmbeddedMaterial(1))+
			(y(2)-_centerOfEmbeddedMaterial(2)) * (y(2)-_centerOfEmbeddedMaterial(2));

	if (distanceSquared< _embeddedMaterialRadius*_embeddedMaterialRadius) {
		return _thermalDiffusivityInEmbeddedMaterial;
	}
	else {
		return _thermalDiffusivity;
	}
#else
	assertion(false);
	return 0.0;

#endif
}


double rotatingheatsource::RotatingHeatSource::getThermalDiffusivity(const tarch::la::Vector<3,double>& x) {
#ifdef Dim4
	tarch::la::Vector<4,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = x(2);
	y(3) = 0.5;
	const double distanceSquared = (y(0)-_centerOfEmbeddedMaterial(0)) * (y(0)-_centerOfEmbeddedMaterial(0)) +
			(y(1)-_centerOfEmbeddedMaterial(1)) * (y(1)-_centerOfEmbeddedMaterial(1))+
			(y(2)-_centerOfEmbeddedMaterial(2)) * (y(2)-_centerOfEmbeddedMaterial(2))+
			(y(3)-_centerOfEmbeddedMaterial(3)) * (y(3)-_centerOfEmbeddedMaterial(3));

	if (distanceSquared< _embeddedMaterialRadius*_embeddedMaterialRadius) {
		return _thermalDiffusivityInEmbeddedMaterial;
	}
	else {
		return _thermalDiffusivity;
	}
#elif Dim3
	tarch::la::Vector<3,double> y;
	y(0) = x(0);
	y(1) = x(1);
	y(2) = x(2);
	const double distanceSquared = (y(0)-_centerOfEmbeddedMaterial(0)) * (y(0)-_centerOfEmbeddedMaterial(0)) +
			(y(1)-_centerOfEmbeddedMaterial(1)) * (y(1)-_centerOfEmbeddedMaterial(1))+
			(y(2)-_centerOfEmbeddedMaterial(2)) * (y(2)-_centerOfEmbeddedMaterial(2));

	if (distanceSquared< _embeddedMaterialRadius*_embeddedMaterialRadius) {
		return _thermalDiffusivityInEmbeddedMaterial;
	}
	else {
		return _thermalDiffusivity;
	}
#else
	assertion(false);
	return 0.0;
#endif
}


bool rotatingheatsource::RotatingHeatSource::isCompletelyOutside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) {
#ifdef VASCO
	return buildingInfrastructure->isCompletelyOutside(x, resolution);
#else
	bool result = false;
	for( int i = 0; i < DIMENSIONS; i++ ){
		bool dimResult = true;
		dimResult &= !(tarch::la::smaller(x(i) - resolution(i), 1.0) &&
				tarch::la::greater(x(i) - resolution(i), 0.0));
		dimResult &= !(tarch::la::smaller(x(i) + resolution(i), 1.0) &&
				tarch::la::greater(x(i) + resolution(i), 0.0));
		dimResult &= !(!tarch::la::greater(x(i) - resolution(i), 0.0) &&
				!tarch::la::smaller(x(i) + resolution(i), 1.0));
		result |= dimResult;
	}

	return result;
#endif
}

#ifndef VASCO
bool rotatingheatsource::RotatingHeatSource::isInsideClosedHexahedron( const tarch::la::Vector<DIMENSIONS,double>& x ) const {
	bool result = true;
	for (int d=0; d<DIMENSIONS; d++) {
		result &= !tarch::la::smaller(x(d),0.0);
		result &= !tarch::la::greater(x(d),1.0);
	}
	return result;
}
#endif


bool rotatingheatsource::RotatingHeatSource::isCompletelyInside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) {
#ifdef VASCO
	return buildingInfrastructure->isCompletelyInside(x, resolution );

#else
	bool result = isInsideClosedHexahedron(x);

	dfor2(i)
	tarch::la::Vector<DIMENSIONS,double> currentPoint0;
	tarch::la::Vector<DIMENSIONS,double> currentPoint1;
	for (int d=0; d<DIMENSIONS; d++) {
		currentPoint0(d) = (i(d)==0) ? x(d)-0.5*resolution(d) : x(d)+0.5*resolution(d);
		currentPoint1(d) = (i(d)==0) ? x(d)-1.0*resolution(d) : x(d)+1.0*resolution(d);
	}
	result &= isInsideClosedHexahedron(currentPoint0);
	result &= isInsideClosedHexahedron(currentPoint1);
	enddforx

	return result;
#endif
}


bool rotatingheatsource::RotatingHeatSource::isOutsideClosedDomain( const tarch::la::Vector<DIMENSIONS,double>& x ) {
#ifdef VASCO
	return buildingInfrastructure->isOutsideClosedDomain(x);
#else
	return !isInsideClosedHexahedron(x);
#endif
}


void rotatingheatsource::RotatingHeatSource::plotInputDataToVTKFile(const std::string& data) const {
	assertionMsg( false, "not implemented yet" );
}


std::string rotatingheatsource::RotatingHeatSource::getOutputFileName() const {
	std::ostringstream result;

	result << _outputFileName << "-" << _maximalMeshWidth(0);
	for (int d=1; d<DIMENSIONS; d++) {
		result << "x" << _maximalMeshWidth(d);
	}
	result << "-" << _minimalMeshWidth(0);
	for (int d=1; d<DIMENSIONS; d++) {
		result << "x" << _minimalMeshWidth(d);
	}
	result << "-m1=" << _thermalDiffusivity;
	result << "-m2=" << _thermalDiffusivityInEmbeddedMaterial;

	return result.str();
}


bool rotatingheatsource::RotatingHeatSource::refinedStartGridAt(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& h, bool isBoundary) {
	bool refine = false;
#ifdef Dim3
	const double distance      = std::sqrt( (x(0)-_stimulusCenter(0)) * (x(0)-_stimulusCenter(0)) +
			(x(1)-_stimulusCenter(1)) * (x(1)-_stimulusCenter(1)) +
			(x(2)-_stimulusCenter(2)) * (x(2)-_stimulusCenter(2)) );
	const double cellDiagonal  = std::sqrt( h(0)*h(0) + h(1)*h(1) + h(2)*h(2));
#else
	const double distance      = std::sqrt( (x(0)-_stimulusCenter(0)) * (x(0)-_stimulusCenter(0)) + (x(1)-_stimulusCenter(1)) * (x(1)-_stimulusCenter(1)) );
	const double cellDiagonal  = std::sqrt( h(0)*h(0) + h(1)*h(1) );
#endif
	bool useMinimalMeshSize    = isBoundary || distance < (_stimulusRadius + cellDiagonal);

	for (int d=0; d<DIMENSIONS; d++) {
		if (useMinimalMeshSize) {
			refine |= h(d)/3.0 > getMinimalMeshSize()(d);
		}
		else {
			refine |= h(d) > getMaximalMeshSize()(d);
		}
	}
	return refine;
}

tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getStimulusCenter() const{
	return _stimulusCenter;
}

tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::RotatingHeatSource::getStimulusRadius() const{
	tarch::la::Vector<DIMENSIONS,double>  rad;
	for(int i=0;i<DIMENSIONS;i++)
		rad[i]=_stimulusRadius;
	return rad;
}

bool rotatingheatsource::RotatingHeatSource::refineOuterCellWithExclusivelyOuterVerticesAsItIntersectsDomain( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) const {
	return tarch::la::oneGreater(resolution, tarch::la::Vector<DIMENSIONS,double>(1.0 / 2.0) );
}


std::string rotatingheatsource::RotatingHeatSource::toString() const {
	std::ostringstream msg;

	msg << "(kappa_outside=" << _thermalDiffusivity
			<< ",kappa_inside="  << _thermalDiffusivityInEmbeddedMaterial
			<< ",h_min="         << _minimalMeshWidth
			<< ",h_max="         << _maximalMeshWidth
			<< ",centre_inside=" << _centerOfEmbeddedMaterial
			<< ",r_inside="      << _embeddedMaterialRadius
			<< ",centre_laser="  << _stimulusCenter
			<< ",r_laser="       << _stimulusRadius
			<< ")";

	return msg.str();
}
