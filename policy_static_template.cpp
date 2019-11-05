// ------------------------------------------------------------
// policy_static_template.cpp
//
//  ポリシーとポリシークラス(static)
//
//  ポリシークラスが「内部状態を持たない」場合に使うとよい
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 静的メンバー関数による
// ポリシーを定義
//
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
//
template<class Policy>
struct hoge{
  static void foo(){
    Policy::func();
  }
};


// ------------------------------------------------------------
int main(){
  cout << boost::format("policy_static_template.cpp\n");

  // 
  hoge<Policy_A>::foo(); // "Call Policy_A::func()";
  hoge<Policy_B>::foo(); // "Call Policy_B::func()";
}
