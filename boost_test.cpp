// ----------------------------------------
// 検証対象のコード
// ----------------------------------------
#include<string>
using namespace std;

int calc(int d){
  return d*d;
}

std::string  mes(){
  return "hello";
}


// ----------------------------------------
// -- Boost.Test
// ----------------------------------------
// 実行例
// --
// Running 4 test cases...
// boost_test.cpp(37): error: in "sampletest/fuga": check calc(5)+1 == 24 has failed [26 != 24]
// 
// *** 1 failure is detected in the test module "Master Test Suite"
//
// ----------------------------------------
#define BOOST_TEST_MAIN    // main関数定義
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(sampletest)
 
BOOST_AUTO_TEST_CASE(hoge)
{
  BOOST_CHECK_EQUAL(9*9, 81);       /// PASS
}
 
BOOST_AUTO_TEST_CASE(fuga)
{
  BOOST_CHECK_EQUAL(calc(5)+1, 24); /// Detect Error 
}
 
BOOST_AUTO_TEST_CASE(fuga2)
{
  BOOST_CHECK_EQUAL(calc(5), 25);   /// PASS
}


BOOST_AUTO_TEST_CASE(fuga3)
{
  BOOST_CHECK_EQUAL(mes(), string("hello")); /// PASS
}

BOOST_AUTO_TEST_SUITE_END()

