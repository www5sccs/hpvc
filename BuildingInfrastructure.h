// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _BuildingInfrastructure_H_
#define _BuildingInfrastructure_H_

#include "peano/geometry/Geometry.h"
#include <iostream>
#include <fstream>

namespace rotatingheatsource {
  class BuildingInfrastructure;
}


class rotatingheatsource::BuildingInfrastructure{

public:
	BuildingInfrastructure(tarch::la::Vector<DIMENSIONS,double> domainSize, tarch::la::Vector<DIMENSIONS,double> domainOffset);
	~BuildingInfrastructure();

	bool isOutsideClosedDomain( const tarch::la::Vector<DIMENSIONS,double>& x );
	bool isCompletelyInside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution );
	bool isCompletelyOutside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution );

private: 
	bool geometryInverted;
	tarch::la::Vector<DIMENSIONS,double> domainsize;
	tarch::la::Vector<DIMENSIONS,double> domainoffset;
	char* _data;
	int size_x, size_y, size_z;
	bool checkValue(const tarch::la::Vector<DIMENSIONS,double>& x, tarch::la::Vector<DIMENSIONS,double> resolution, char type);

};


#endif
