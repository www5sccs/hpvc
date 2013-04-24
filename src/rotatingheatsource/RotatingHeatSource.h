// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_ROTATING_HEAT_SOURCE_H_
#define _ROTATINGHEATSOURCE_ROTATING_HEAT_SOURCE_H_


#include "rotatingheatsource/DiffusionEquationScenario.h"
#ifdef VASCO
	#include "rotatingheatsource/BuildingInfrastructure.h"
#endif



namespace rotatingheatsource {
  class RotatingHeatSource;
}


class rotatingheatsource::RotatingHeatSource: public rotatingheatsource::DiffusionEquationScenario {
  private:
    double                                 _thermalDiffusivity;
    double                                 _thermalDiffusivityInEmbeddedMaterial;

    tarch::la::Vector<DIMENSIONS,double>   _minimalMeshWidth;
    tarch::la::Vector<DIMENSIONS,double>   _maximalMeshWidth;
    tarch::la::Vector<DIMENSIONS,double>   _centerOfEmbeddedMaterial;
    const double                           _embeddedMaterialRadius;
    tarch::la::Vector<DIMENSIONS,double>   _stimulusCenter;
    const double                           _stimulusRadius;

    std::string                            _outputFileName;
    int _time;
#ifdef VASCO
    BuildingInfrastructure* buildingInfrastructure;
#else
    bool isInsideClosedHexahedron( const tarch::la::Vector<DIMENSIONS,double>& x ) const;
#endif




  public:
    static tarch::la::Vector<DIMENSIONS,double> getDefaultDomainSize();
    static tarch::la::Vector<DIMENSIONS,double> getDefaultDomainOffset();

    RotatingHeatSource(
      double                                       thermalDiffusivity,
      double                                       thermalDiffusivityInEmbeddedMaterial,
      double                                       stimulusSphereRadius,
      const tarch::la::Vector<DIMENSIONS,double>&  minimalMeshWidth,
      const tarch::la::Vector<DIMENSIONS,double>&  maximalMeshWidth,
      const std::string&                           outputFileName
    );

    virtual void setTime( double t );
    const int getTime() const;
    virtual tarch::la::Vector<DIMENSIONS,double>   getDomainSize() const;
    virtual tarch::la::Vector<DIMENSIONS,double>   getComputationalDomainOffset() const;
    virtual tarch::la::Vector<DIMENSIONS,double>   getMinimalMeshSize() const;
    virtual tarch::la::Vector<DIMENSIONS,double>   getMaximalMeshSize() const;
    virtual bool                                   refinedStartGridAt(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& h, bool isBoundary);

    virtual double       getRhs(const tarch::la::Vector<1,double>& x);
    virtual double       getInitialValue(const tarch::la::Vector<1,double>& x) const;
    virtual BoundaryType getBoundaryType(const tarch::la::Vector<1,double>& x) const;
    virtual double       getThermalDiffusivity(const tarch::la::Vector<1,double>& x);

    virtual double       getRhs(const tarch::la::Vector<2,double>& x);
    virtual double       getInitialValue(const tarch::la::Vector<2,double>& x) const;
    virtual BoundaryType getBoundaryType(const tarch::la::Vector<2,double>& x) const;
    virtual double       getThermalDiffusivity(const tarch::la::Vector<2,double>& x);

    virtual double       getRhs(const tarch::la::Vector<3,double>& x);
    virtual double       getInitialValue(const tarch::la::Vector<3,double>& x) const;
    virtual BoundaryType getBoundaryType(const tarch::la::Vector<3,double>& x) const;
    virtual double       getThermalDiffusivity(const tarch::la::Vector<3,double>& x);

    virtual bool isCompletelyOutside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution );
    virtual bool isCompletelyInside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution );
    virtual bool isOutsideClosedDomain( const tarch::la::Vector<DIMENSIONS,double>& x );
    tarch::la::Vector<DIMENSIONS,double> getStimulusCenter() const;
    tarch::la::Vector<DIMENSIONS,double> getStimulusRadius() const;
    virtual double       getMaximalSamplingWidth() const;
    virtual void         plotInputDataToVTKFile(const std::string& data) const;
    virtual std::string  getOutputFileName() const;

    virtual bool domainHasChanged( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution );

    virtual bool refineOuterCellWithExclusivelyOuterVerticesAsItIntersectsDomain( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) const;

    std::string toString() const;
};


#endif
