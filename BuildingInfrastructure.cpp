#include "rotatingheatsource/BuildingInfrastructure.h"

#define FLAG_IS_INSIDE 0
#define FLAG_IS_OUTSIDE 1
using namespace std;

rotatingheatsource::BuildingInfrastructure::BuildingInfrastructure(tarch::la::Vector<DIMENSIONS,double> domainSize, tarch::la::Vector<DIMENSIONS,double> domainOffset){
	
	std::cout << "Lade Geometry " << std::endl;

	std::ifstream file("TUM_mesh1000x1000x1000_mesh_char.raw", std::ios::binary );
		
	size_x = 1000;
	size_y = 1000;
	size_z = 1000;
#ifdef INVERTED
	geometryInverted = true;
#else
	geometryInverted = false;
#endif

	int size= size_x * size_y * size_z;
	_data = new char[size];

	file.read(_data, size);
	file.close();

	domainoffset = domainOffset;
	domainsize = domainSize;

	cout << "***** Start *****" << endl;
	for (int d=0; d<DIMENSIONS; d++) {
		cout << "domainsize[" << d << "] = " << domainsize[d] << "; " << "domainoffset[" << d << "] = " << domainoffset[d] << endl;
	}
	cout << "***** Start *****" << endl;


}


rotatingheatsource::BuildingInfrastructure::~BuildingInfrastructure(){
	cout << "***** End  *****" << endl;
	delete _data;
}


bool rotatingheatsource::BuildingInfrastructure::isOutsideClosedDomain( const tarch::la::Vector<DIMENSIONS,double>& x ){

	return false;


	if (x[0] > domainsize[0] + domainoffset[0]){
		return true;
	}

	if (x[1]> domainsize[1] + domainoffset[1]){
		return true;
	}

	if (x[2] > domainsize[2] + domainoffset[2]){
		return true;
	}

	if (x[0] < domainoffset[0]){
		return true;
	}

	if (x[1] < domainoffset[1]){
		return true;
	}

	if (x[2] < domainoffset[2]){
		return true;
	}
	return false;
}

bool rotatingheatsource::BuildingInfrastructure::isCompletelyInside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) {
	
	return checkValue(x, resolution, geometryInverted ? FLAG_IS_INSIDE : FLAG_IS_OUTSIDE);

}
bool rotatingheatsource::BuildingInfrastructure::isCompletelyOutside( const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double> &resolution ) {

	return checkValue(x, resolution, geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE);
}



bool rotatingheatsource::BuildingInfrastructure::checkValue(const tarch::la::Vector<DIMENSIONS,double>& x, tarch::la::Vector<DIMENSIONS,double> resolution, char type){


	//std::cout << x << "; " << resolution << std::endl;

	if (x[0] > domainsize[0] + domainoffset[0]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	if (x[1]> domainsize[1] + domainoffset[1]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	if (x[2] > domainsize[2] + domainoffset[2]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	if (x[0]+resolution[0] < domainoffset[0]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	if (x[1]+resolution[1] < domainoffset[1]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	if (x[2]+resolution[2] < domainoffset[2]){
		return type== geometryInverted ? FLAG_IS_OUTSIDE : FLAG_IS_INSIDE;
	}

	int x_from = floor( ( x[0] - resolution[0] - domainoffset[0])/domainsize[0] * (double)size_x);
	int x_to   =  ceil( ( x[0] + resolution[0] - domainoffset[0])/domainsize[0] * (double)size_x);
	int y_from = floor( ( x[1] - resolution[1] - domainoffset[0])/domainsize[1] * (double)size_y);
	int y_to   =  ceil( ( x[1] + resolution[1] - domainoffset[0])/domainsize[1] * (double)size_y);
	int z_from = floor( ( x[2] - resolution[2] - domainoffset[0])/domainsize[2] * (double)size_z);
	int z_to   =  ceil( ( x[2] + resolution[2] - domainoffset[0])/domainsize[2] * (double)size_z);

	x_from = min( max( 0, x_from	), size_x-1);
	x_to	= min( max( 0, x_to		), size_x-1);
	y_from = min( max( 0, y_from	), size_y-1);
	y_to	= min( max( 0, y_to		), size_y-1);
	z_from = min( max( 0, z_from	), size_z-1);
	z_to	= min( max( 0, z_to		), size_z-1);

	bool debug= false;

	if (debug){
		std::cout.precision(5);
		std::cout << std::fixed;
		std::cout << "x= " << (float)x[0] << "+-" << (float)resolution[0] << " ==> [" << x_from << "; " << x_to << "]" << std::endl;
		std::cout << "y= " << (float)x[1] << "+-" << (float)resolution[1] << " ==> [" << y_from << "; " << y_to << "]" << std::endl;
		std::cout << "z= " << (float)x[2] << "+-" << (float)resolution[2] << " ==> [" << z_from << "; " << z_to << "]" << std::endl;
	}
		
	int idx=-1;
	for (int i=x_from; i <=x_to; i++){
		for (int j=y_from; j <=y_to; j++){
			for (int k=z_from; k <=z_to; k++){

				idx = k*size_x*size_y + j*size_x + i;
					
				
				if (type != _data[idx]){
					if (debug){
						cout << (int) type << " != _data[" << idx<< "==" << i << ";" << j << ";" << k << " ]= " << (int) _data[idx] << endl << endl;
					}
					return false;
				}
			}
		}
	}
	if (debug){
		cout << (int) type << " == _data[" << idx<< "]= " << (int) _data[idx] << endl << endl;
	}
	return true;
}
