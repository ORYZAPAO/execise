// ------------------------------------------------------------
// policy_static_template.cpp
//
//  ポリシーとポリシークラス(static)
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// static メンバー関数による
// ポリシーを定義
struct Policy_A{
  static void func(){
    std::cout << "Call Policy_A::func()\n";
  }
};

struct Policy_B{
  static void func(){
    std::cout << "Call Policy_B::func()\n";
  }
};


// ------------------------------------------------------------
// 呼出し
template<class T>
struct hoge{
  static void foo(){
    T::func();
  }
};


// ------------------------------------------------------------
int main(){
  cout << boost::format("Hello\n");

  // 
  hoge<Policy_A>::foo(); // "Call Policy_A::func()";
  hoge<Policy_B>::foo(); // "Call Policy_B::func()";
}
