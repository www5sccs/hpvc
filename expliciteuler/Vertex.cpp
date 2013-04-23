#include "rotatingheatsource/expliciteuler/Vertex.h"
#include "peano/utils/Loop.h"
#include "peano/grid/Checkpoint.h"
#include "matrixfree/stencil/StencilFactory.h"


rotatingheatsource::expliciteuler::Vertex::Vertex():
  Base() { 
  _vertexData.setU(0.0);
  _vertexData.setRhs(0.0);
}


rotatingheatsource::expliciteuler::Vertex::Vertex(const Base::DoNotCallStandardConstructor& value):
  Base(value) { 
}


rotatingheatsource::expliciteuler::Vertex::Vertex(const Base::PersistentVertex& argument):
  Base(argument) {
}


 tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::expliciteuler::Vertex::readRhs(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices) { tarch::la::Vector<TWO_POWER_D,double> result; dfor2(x) result(xScalar) = vertices[ enumerator(x) ]._vertexData.getRhs(); enddforx return result; }
 tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::expliciteuler::Vertex::readU(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices) { tarch::la::Vector<TWO_POWER_D,double> result; dfor2(x) result(xScalar) = vertices[ enumerator(x) ]._vertexData.getU(); enddforx return result; }
 tarch::la::Vector<TWO_POWER_D,double> rotatingheatsource::expliciteuler::Vertex::readResidual(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices) { tarch::la::Vector<TWO_POWER_D,double> result; dfor2(x) result(xScalar) = vertices[ enumerator(x) ]._vertexData.getResidual(); enddforx return result; }


 tarch::la::Vector<TWO_POWER_D_TIMES_D,double>  rotatingheatsource::expliciteuler::Vertex::readLinearSurplus(const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices)  { tarch::la::Vector<TWO_POWER_D_TIMES_D,double> result; dfor2(x) tarch::la::slice(result,vertices[ enumerator(x) ]._vertexData.getLinearSurplus(),xScalar*DIMENSIONS); enddforx return result; }




tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double>  rotatingheatsource::expliciteuler::Vertex::readStencil(
  const peano::grid::VertexEnumerator& enumerator, const Vertex* const vertices
) {
  tarch::la::Vector<TWO_POWER_D_TIMES_THREE_POWER_D,double> result;
  dfor2(x)
    tarch::la::slice(result,vertices[ enumerator(x) ]._vertexData.getStencil(),xScalar*THREE_POWER_D);
  enddforx
  return result;
}


 void rotatingheatsource::expliciteuler::Vertex::writeResidual(const peano::grid::VertexEnumerator& enumerator, Vertex* const vertices, const tarch::la::Vector<TWO_POWER_D,double>& values ) { dfor2(x) vertices[ enumerator(x) ]._vertexData.setResidual( values(xScalar) ); enddforx }


void rotatingheatsource::expliciteuler::Vertex::writeLinearSurplus(
  const peano::grid::VertexEnumerator& enumerator,
  Vertex* const vertices, const tarch::la::Vector<TWO_POWER_D_TIMES_D,double>& values
) {
  dfor2(x)
    tarch::la::Vector<DIMENSIONS,double> temp = tarch::la::slice<DIMENSIONS>(values,xScalar*DIMENSIONS);
    vertices[ enumerator(x) ]._vertexData.setLinearSurplus( temp );
  enddforx
}



 void rotatingheatsource::expliciteuler::Vertex::initialiseInnerVertex(
   double thermalDiffusivity,
   double temperature,
   double rhs,
   const tarch::la::Vector<DIMENSIONS,double>& h
 ) {
   _vertexData.setResidual(0.0);
   _vertexData.setU(temperature);
   _vertexData.setRhs(rhs);

   matrixfree::stencil::Stencil stencil;
   #if defined(Dim2)
   stencil =
     thermalDiffusivity * // could be dth entry if it were an anisotropic operator
       matrixfree::stencil::StencilFactory::stencilProduct(
         matrixfree::stencil::StencilFactory::get1DLaplaceStencil(h(0)),
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(1))
       )
     + thermalDiffusivity * // could be dth entry if it were an anisotropic operator
       matrixfree::stencil::StencilFactory::stencilProduct(
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(0)),
         matrixfree::stencil::StencilFactory::get1DLaplaceStencil(h(1))
       );
   #elif defined(Dim3)
   stencil =
     thermalDiffusivity * // could be dth entry if it were an anisotropic operator
       matrixfree::stencil::StencilFactory::stencilProduct(
         matrixfree::stencil::StencilFactory::get1DLaplaceStencil(h(0)),
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(1)),
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(2))
       )
     + thermalDiffusivity * // could be dth entry if it were an anisotropic operator
       matrixfree::stencil::StencilFactory::stencilProduct(
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(0)),
         matrixfree::stencil::StencilFactory::get1DLaplaceStencil(h(1)),
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(2))
       );
     + thermalDiffusivity * // could be dth entry if it were an anisotropic operator
       matrixfree::stencil::StencilFactory::stencilProduct(
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(0)),
         matrixfree::stencil::StencilFactory::get1DMassStencil(h(2)),
         matrixfree::stencil::StencilFactory::get1DLaplaceStencil(h(2))
       );
   #endif
  _vertexData.setStencil(stencil);
}


void rotatingheatsource::expliciteuler::Vertex::initialiseBoundaryVertex( double temperature ) {
  _vertexData.setResidual(0.0);
  _vertexData.setU(temperature);
  _vertexData.setRhs(0.0);
  _vertexData.setStencil(0.0);
}


void rotatingheatsource::expliciteuler::Vertex::initialiseHangingVertex(double interpolatedTemperature, double interpolatedRhs) {
  _vertexData.setResidual(0.0);
  _vertexData.setU(interpolatedTemperature);
  _vertexData.setRhs(interpolatedRhs);
  _vertexData.setStencil(0.0);
}


double rotatingheatsource::expliciteuler::Vertex::getTemperature() const {
  return _vertexData.getU();
}


double rotatingheatsource::expliciteuler::Vertex::getRhs() const {
  return _vertexData.getRhs();
}


matrixfree::stencil::Stencil rotatingheatsource::expliciteuler::Vertex::getStencil() const {
  return _vertexData.getStencil();
}


double rotatingheatsource::expliciteuler::Vertex::getResidual() const {
  return _vertexData.getResidual();
}

#ifdef Parallel
void rotatingheatsource::expliciteuler::Vertex::scaleResidual(double scaling) {
  _vertexData.setResidual( _vertexData.getResidual() * scaling );
}
#endif


void rotatingheatsource::expliciteuler::Vertex::clearResidual() {
  _vertexData.setResidual(0.0);
}


void rotatingheatsource::expliciteuler::Vertex::setNewRhs( double rhs ) {
  _vertexData.setRhs( rhs );
}


void rotatingheatsource::expliciteuler::Vertex::setTemperature( double value ) {
  _vertexData.setU( value );
}


void rotatingheatsource::expliciteuler::Vertex::clearSurplusMeasurements() {
  _vertexData.setLinearSurplus(0.0);
}


tarch::la::Vector<DIMENSIONS,double> rotatingheatsource::expliciteuler::Vertex::getLinearSurplus() const {
  return _vertexData.getLinearSurplus();
}


void rotatingheatsource::expliciteuler::Vertex::copyUFromFinerGrid( const Vertex& vertex ) {
  _vertexData.setU( vertex._vertexData.getU() );
}
