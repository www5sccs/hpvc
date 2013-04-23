#include "rotatingheatsource/UserInterface.h"


rotatingheatsource::UserInterface::UserInterface(
  const std::string& experimentTitle,
  double             timeStepSize,
  int                numberOfSpacesPerColumn
):
   _numberOfSpacesPerColumn(numberOfSpacesPerColumn),
  _globalStencilUpdates(0.0),
  _maxOfUEverMeasuredInHNorm(0.0),
  _maxOfUEverMeasuredInMaxNorm(0.0) {
  writeHeader();
  logInfo(
    "UserInterface(...)",
    "|| "     << format(numberOfSpacesPerColumn ,experimentTitle) <<
    "|| dt="  << format(numberOfSpacesPerColumn-3, timeStepSize)
   );
  logInfo(
    "UserInterface(...)",
    "| " << format(numberOfSpacesPerColumn, "t" ) <<
    " | " << format(numberOfSpacesPerColumn, "dt" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u|_max" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u_global|_max" ) <<
    " | " << format(numberOfSpacesPerColumn, "|du|_max" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u_global|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "|du|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "mem [m]=MB") <<
    " | " << format(numberOfSpacesPerColumn, "#stencil" ) <<
    " | " << format(numberOfSpacesPerColumn, "#stencil_global") <<
    " | " << format(numberOfSpacesPerColumn, "#it") <<
    " | " << format(numberOfSpacesPerColumn, "comment") <<
    " | "
  );
}



rotatingheatsource::UserInterface::UserInterface(
  const std::string& experimentTitle,
  double             simulationTime,
  double             timeStepSize,
  double             relaxationFactor,
  double             stencilEvaluationsDoneSoFar,
  int                numberOfSpacesPerColumn
):
  _numberOfSpacesPerColumn(numberOfSpacesPerColumn),
  _globalStencilUpdates(stencilEvaluationsDoneSoFar) {
  logInfo(
    "UserInterface(...)",
    "|| "     << format(numberOfSpacesPerColumn ,experimentTitle) <<
    "|| t="   << format(numberOfSpacesPerColumn-2, simulationTime) <<
    "|| dt="  << format(numberOfSpacesPerColumn-3, timeStepSize) <<
    "|| omega=" << format(numberOfSpacesPerColumn-4, relaxationFactor)
   );
  logInfo(
    "UserInterface(...)",
    "| " << format(numberOfSpacesPerColumn, "|u|_max" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u_global|_max" ) <<
    " | " << format(numberOfSpacesPerColumn-2, "|du|_max" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "|u_global|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "|du|_h" ) <<
    " | " << format(numberOfSpacesPerColumn, "mem [m]=MB") <<
    " | " << format(numberOfSpacesPerColumn, "#stencil" ) <<
    " | " << format(numberOfSpacesPerColumn, "#stencil_global") <<
    " | " << format(numberOfSpacesPerColumn, "#it") <<
    " | " << format(numberOfSpacesPerColumn, "comment") <<
    " | "
  );
}


void rotatingheatsource::UserInterface::printIterationInfo(
    double t,
    double dt,
    double solutionInMaximumNorm,
    double solutionUpdateInMaxNorm,
    double solutionInHNorm,
    double solutionUpdateInHNorm,
    double numberOfStencilUpdates,
    int    iterations,
    const std::string& comment
) {
  _globalStencilUpdates        += numberOfStencilUpdates;
  _maxOfUEverMeasuredInHNorm    = _maxOfUEverMeasuredInHNorm>solutionInHNorm         ? _maxOfUEverMeasuredInHNorm : solutionInHNorm;
  _maxOfUEverMeasuredInMaxNorm  = _maxOfUEverMeasuredInMaxNorm>solutionInMaximumNorm ? _maxOfUEverMeasuredInMaxNorm : solutionInMaximumNorm;

  logInfo(
    "printIterationInfo(...)",
    "| " << format(_numberOfSpacesPerColumn, t) <<
    " | " << format(_numberOfSpacesPerColumn, dt) <<
    " | " << format(_numberOfSpacesPerColumn, solutionInMaximumNorm) <<
    " | " << format(_numberOfSpacesPerColumn, _maxOfUEverMeasuredInMaxNorm) <<
    " | " << format(_numberOfSpacesPerColumn, solutionUpdateInMaxNorm) <<
    " | " << format(_numberOfSpacesPerColumn, solutionInHNorm) <<
    " | " << format(_numberOfSpacesPerColumn, _maxOfUEverMeasuredInHNorm) <<
    " | " << format(_numberOfSpacesPerColumn, solutionUpdateInHNorm) <<
    " | " << format(_numberOfSpacesPerColumn, getMemoryUsageMB() ) <<
    " | " << format(_numberOfSpacesPerColumn, numberOfStencilUpdates) <<
    " | " << format(_numberOfSpacesPerColumn, _globalStencilUpdates ) <<
    " | " << format(_numberOfSpacesPerColumn, iterations ) <<
    " | " << format(_numberOfSpacesPerColumn, comment ) <<
    " | "
  );
}


double rotatingheatsource::UserInterface::getInverseOfBiggestUEverMeasuredInHNorm() const {
  return _maxOfUEverMeasuredInHNorm;
}


double rotatingheatsource::UserInterface::getInverseOfBiggestUEverMeasuredInMaxNorm() const {
  return _maxOfUEverMeasuredInMaxNorm;
}


double rotatingheatsource::UserInterface::getTotalStencilEvaluations() const {
  return _globalStencilUpdates;
}
