// ------------------------------------------------------------
// SFINAE.cpp
//
// SFINAE(Substitution Failure Is Not An Error)
// 置き換え失敗はえらーではない。
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------

// 判定対象のクラス
struct AAA{
  typedef int data_type;
};

struct BBB{
  typedef int value_type;
};

// ----------------------------------------
// data_type型の判定テンプレート
template<typename T>
bool has_data(typename T::data_type *){
  std::cout << "data_type型を、持つ" << std::endl;
  return true;
}

template<typename T>
bool has_data(...){
  std::cout << "data_type型は、持たない" << std::endl; 
  return false;
}


// ------------------------------------------------------------
int main(){
  AAA aa;
  BBB bb;

  has_data<AAA>(0); // "data_type型を、持つ"
                    //   bool has_data(typename T::data_type *)がマッチする

  has_data<BBB>(0); // "data_type型は、持たない"
                    //   bool has_data(...)がマッチする
}
