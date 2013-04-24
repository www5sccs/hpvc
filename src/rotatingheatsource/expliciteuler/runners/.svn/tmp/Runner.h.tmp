// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _ROTATINGHEATSOURCE_EXPLICITEULER_RUNNERS_RUNNER_H_ 
#define _ROTATINGHEATSOURCE_EXPLICITEULER_RUNNERS_RUNNER_H_ 

#include "rotatingheatsource/OracleForOnePhaseBinaryPartitioning.h"

using namespace poissonwithjacobi_wittmanr;

namespace rotatingheatsource { 
  namespace expliciteuler {
    namespace runners {
      class Runner;
    }

    namespace repositories {
      class Repository;
    }
}
}



/**
 * Runner
 *
 */
class rotatingheatsource::expliciteuler::runners::Runner {
  private:
    int runAsMaster(rotatingheatsource::expliciteuler::repositories::Repository& repository);
    
    #ifdef Parallel
    int runAsWorker(rotatingheatsource::expliciteuler::repositories::Repository& repository);
    #endif

    static const double InitialTimeStepSize;
    static const double SnapshotDelta;
    static const double TerminalTotalTime;
    static const double MaxDifferenceFromTimeStepToTimeStepInMaxNorm;
    static const double MaxDifferenceFromTimeStepToTimeStepInHNorm;

    static const double ThermalDiffusivity;
    static const double ThermalDiffusivityInEmbeddedMaterial;
    static const double StimulusSphereRadius;
    static const double MinimalMeshWidth;
    static const double MaximalMeshWidth;

    OracleState _oracleState;
  public:
    Runner();
    virtual ~Runner();

    /**
     * Run
     */
    int run(); 
};

#endif
