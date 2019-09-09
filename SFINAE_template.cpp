// ------------------------------------------------------------
// SFINAE.cpp
//
// SFINAE(Substitution Failure Is Not An Error)
// 置き換え失敗はえらーではない。
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>
#include<vector>
#include<string>

using namespace std;

// ------------------------------------------------------------
// TEST 1
// ------------------------------------------------------------
// 判定対象のクラス
struct AAA{
  typedef int data_type;
};

struct BBB{
  typedef int value_type;
};

// ----------------------------------------
// data_type型の判定関数(SFINAE)
template<typename T>
bool has_data_impl(typename T::data_type *){
  std::cout << "data_type型を、持つ" << std::endl;
  return true;
}

template<typename T>
bool has_data_impl(...){
  std::cout << "data_type型は、持たない" << std::endl; 
  return false;
}

// (ラッパー) 
template<typename U>
bool has_data(){
  return has_data_impl<U>(nullptr);
}

// ------------------------------------------------------------
// TEST 2
// ------------------------------------------------------------
// iterator 所持の判定(SFINAE)
template<class T>
bool has_iterator_impl(typename T::iterator*){
  return true;
}

template<class T>
bool has_iterator_impl(...){
  return false;
}

// (ラッパー)
template<class U>
bool has_iterator(){
  return has_iterator_impl<U>(nullptr);
}


// ------------------------------------------------------------
// TEST 3
// ------------------------------------------------------------
// void型の型判定
template<class T>
bool my_is_void(...){
  return false;
}

template<>
bool my_is_void<void>(...){
  return true;
}


// // void型の型判定 (SFINAE)
// template<class T>
// bool my_is_void2_impl(void*){
//   return true;
// }
// 
// template<class T>
// bool my_is_void2_impl(...){
//   return false;
// }
// 
// // (ラッパー)
// template<class U>
// bool my_is_void2(){
//   return my_is_void2_impl<U>(nullptr);
// }


// ------------------------------------------------------------
int main(){
  AAA aa;
  BBB bb;

  // ---------------------------------------- 
  std::cout << "TEST 1" << std::endl;
  // data_type型の判定関数(SFINAE)
  // ---------------------------------------- 
  
  has_data<AAA>(); // "data_type型を、持つ"
                   //   bool has_data(typename T::data_type *)がマッチする

  has_data<BBB>(); // "data_type型は、持たない"
                   //   bool has_data(...)がマッチする
  std::cout << std::endl;


  // ---------------------------------------- 
  std::cout << "TEST 2" << std::endl;
  // iterator 所持の判定
  // ---------------------------------------- 
  // "int  is void? 0"
  // "long is void? 0"
  // "void is void? 1"
  std::cout << "int  is void? " << my_is_void<int>()  << std::endl;
  std::cout << "long is void? " << my_is_void<long>() << std::endl;
  std::cout << "void is void? " << my_is_void<void>() << std::endl;
  std::cout << std::endl;

  // std::cout << "int  is void? " << my_is_void2<int>()  << std::endl;
  // std::cout << "long is void? " << my_is_void2<long>() << std::endl;
  // std::cout << "void is void? " << my_is_void2<void>() << std::endl;
  // std::cout << std::endl;


  // ---------------------------------------- 
  std::cout << "TEST 3" << std::endl;
  // void型の型判定
  // ---------------------------------------- 
  std::vector<int> dat={0,1,2,3,4,5};

  // "std::vector<int> has Iterartor? 1"
  // "dat[] has Iterartor?            1"
  // "char has Iterartor?             0"
  // "int has Iterartor?              0"  
  std::cout << "std::vector<int> has Iterartor? " << has_iterator<std::vector<int>>() << std::endl;
  std::cout << "dat[] has Iterartor?            " << has_iterator<decltype(dat)>() << std::endl;
  
  std::cout << "char has Iterartor?             " << has_iterator<char>() << std::endl;
  std::cout << "int has Iterartor?              " << has_iterator<int>()  << std::endl;

}
