// ------------------------------------------------------------
// policy_static_template.cpp
//
//  ポリシーとポリシークラス(static)
//
//  ポリシークラスが「内部状態を持つ」場合に使うとよい
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 静的メンバー関数による
// ポリシーを定義
//
struct Policy_A{
  bool item0; // なんらかの状態を保存

  void func(){
    std::cout << "Call Policy_A::func()\n";
  }
};

struct Policy_B{
  bool item0; // なんらかの状態を保存
  bool item1; //

  void func(){
    std::cout << "Call Policy_B::func()\n";
  }
};


// ------------------------------------------------------------
// 呼出し
//
template<class Policy>
struct hoge{  
  Policy p;
  
  void foo(){
    p.func();
  }
};


// ------------------------------------------------------------
int main(){
  cout << boost::format("policy_nonstatic_template.cpp\n");

  //hoge<Policy_A>::foo(); // "Call Policy_A::func()";
  //hoge<Policy_B>::foo(); // "Call Policy_B::func()";

  hoge<Policy_A> a;
  hoge<Policy_B> b;
  a.foo(); // "Call Policy_A::func()"
  b.foo(); // "Call Policy_B::func()"
}
