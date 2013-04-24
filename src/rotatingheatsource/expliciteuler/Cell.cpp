#include "rotatingheatsource/expliciteuler/Cell.h"


rotatingheatsource::expliciteuler::Cell::Cell():
  Base() { 
  // @todo Insert your code here
}


rotatingheatsource::expliciteuler::Cell::Cell(const Base::DoNotCallStandardConstructor& value):
  Base(value) { 
  // Please do not insert anything here
}

rotatingheatsource::expliciteuler::Cell::Cell(const Base::PersistentCell& argument):
  Base(argument) {
  // @todo Insert your code here
}

void rotatingheatsource::expliciteuler::Cell::setCellHeapId(const int heapId){
	_cellData.setCellHeapId(heapId);
}

const int rotatingheatsource::expliciteuler::Cell::getCellHeapId() const{
	return _cellData.getCellHeapId();
}
