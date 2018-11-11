// variadic_and_fold_template.cpp
//
//  可変引数テンプレート１(C++11) と fold式(畳み込み式,C++14)　
// 
//
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// [C++11] 可変引数テンプレート
//

template<typename T> 
//T old_sub(T x){  // c++11
auto old_sub(T x){
  cout << x << " = ";
  return( x ) ;
}

template<typename T, typename ... Types> 
//T old_sub(T x, Types ... args){ // c++11
auto old_sub(T x, Types ... args){
  cout << x << ",";
  return( old_sub(args...) - x );
}


// ------------------------------------------------------------
// [c++17] 可変引数テンプレート と　fold式(畳み込み式) 
//
template<typename ... Types>  // 左fold式
auto left_fold_sub(Types ... args){
  return( ... - args); // ()カッコが必須
}


template<typename ... Types>   // 右fold式
auto  right_fold_sub(Types ... args){
  return( args - ...); // ()カッコが必須
}

// ------------------------------------------------------------
int main(){
  cout << "[C++ version]  " <<  __cplusplus << endl << endl;

  // "(1) (2) (3) (4) (5) = -5"
  cout << "--> 1)[c++11] 可変引数テンプレート(c++11)" << endl;
  cout << "   ((((5 - 4) - 3) - 2) - 1)" << endl;
  cout << "  old_sub(1,2,3,4,5) = " << old_sub(1,2,3,4,5) << endl;
  cout << endl;
  
  cout << "--> 2)[c++14] 可変引数テンプレート と fold式(畳み込み式)" << endl;

  // "left_fold_sub(1,2,3,4,5) = -13"
  cout << "  Left Fold Expression  ((((1 - 2) - 3) - 4) - 5)" << endl;
  cout << boost::format("   left_fold_sub(1,2,3,4,5) = %d") % left_fold_sub(1,2,3,4,5) << endl << endl;

  // "right_fold_sub(1,2,3,4,5) = 3"
  cout << "  Right Fold Expression (1 - (2 - (3 - (4 - 5))))" << endl;
  cout << boost::format("   right_fold_sub(1,2,3,4,5) = %d") % right_fold_sub(1,2,3,4,5) << endl;
  
}
