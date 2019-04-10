/* 
 * Google Test Sample
 *
 * [Hp] https://github.com/google/googletest
 *
 * [Install]
 *  ArchLinux: sudo pacman -S gtest
 *
 * [Run]
 *  make -k SRC=google_test.cpp LINKOPT=-lgtest
 *
 *  g++ -std=c++1y -isystem -pthread google_test.cpp -I../googletest/googletest/include -L../googletest/lib -lgtest
 *
 */
#include <gtest/gtest.h>
///#pragma comment(linker, "-lgtest" )
// 
//

// ----------------------------------------
// 検証対象のコード
// ----------------------------------------
class MyDUT{
public:
  bool IsOdd(int x){ // 奇数判定
    return ((x % 2) != 0) ? true : false;
  }

  bool IsEven(int x){ // 偶数判定
    return ((x % 2) == 0) ? true : false;
  }
};



// ----------------------------------------
// -- Test
// --
// -- 実行例
//
//  [==========] Running 2 tests from 1 test case.
//  [----------] Global test environment set-up.
//  [----------] 2 tests from MyTest
//  [ RUN      ] MyTest.TEST_IsOdd
//  google_test.cpp:72: Failure
//        Expected: false
//  To be equal to: mi3.IsOdd(11)
//        Which is: true
//  [  FAILED  ] MyTest.TEST_IsOdd (0 ms)
//  [ RUN      ] MyTest.TEST_IsEven
//  [       OK ] MyTest.TEST_IsEven (0 ms)
//  [----------] 2 tests from MyTest (0 ms total)
//  
//  [----------] Global test environment tear-down
//  [==========] 2 tests from 1 test case ran. (1 ms total)
//  [  PASSED  ] 1 test.
//  [  FAILED  ] 1 test, listed below:
//  [  FAILED  ] MyTest.TEST_IsOdd
//  
//   1 FAILED TEST
//
// ----------------------------------------
class MyTest : public ::testing::Test{};

TEST_F(MyTest, TEST_IsOdd)
{
  MyDUT mi1 /*= MyDUT()*/;
  EXPECT_EQ(false, mi1.IsOdd(10)); // Pass

  MyDUT mi2 /*= MyDUT()*/;
  EXPECT_EQ(true, mi2.IsOdd(3));   // Pass

  MyDUT mi3 /*= MyDUT()*/;
  EXPECT_EQ(false, mi3.IsOdd(11)); // !!! Fail !!!
}


TEST_F(MyTest, TEST_IsEven)
{
  MyDUT mi1 /*= MyDUT()*/;
  EXPECT_EQ(true, mi1.IsEven(10)); // Pass

  MyDUT mi2 /*= MyDUT()*/;
  EXPECT_EQ(false, mi2.IsEven(3)); // Pass
}




// ----------------------------------------
// ----------------------------------------
int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}
