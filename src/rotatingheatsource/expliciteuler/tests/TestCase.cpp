#include "rotatingheatsource/expliciteuler/tests/TestCase.h"


#include "tarch/compiler/CompilerSpecificSettings.h"
#include "tarch/tests/TestCaseFactory.h"
registerTest(rotatingheatsource::expliciteuler::tests::TestCase)


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",off)
#endif

 
rotatingheatsource::expliciteuler::tests::TestCase::TestCase():
  tarch::tests::TestCase( "rotatingheatsource::expliciteuler::tests::TestCase" ) {
}


rotatingheatsource::expliciteuler::tests::TestCase::~TestCase() {
}


void rotatingheatsource::expliciteuler::tests::TestCase::run() {
  // @todo If you have further tests, add them here
  testMethod( test1 );
  testMethod( test2 );
  testMethod( test3 );
}


void rotatingheatsource::expliciteuler::tests::TestCase::test1() {
  // @todo Add your test here
  validateEquals(1,1);
}


void rotatingheatsource::expliciteuler::tests::TestCase::test2() {
  // @todo Add your test here
  validateEquals(2,2);
}


void rotatingheatsource::expliciteuler::tests::TestCase::test3() {
  // @todo Add your test here
  validateEquals(3,3);
}


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",on)
#endif
