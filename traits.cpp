//
// traits定義例
//

#include<iostream>
#include<boost/format.hpp>
#include<string>

using namespace std;

enum valuelst{
   p0=000
  ,p1=111
  ,p2=222
};

/***
template<typename T>
struct mytype{};

template<>
struct mytype<int>{
  mytype(){ cout << "Mytype<int>" << endl; }
  using type = int;
};

template<>
struct mytype<float>{
  mytype(){ cout << "Mytype<float>" << endl; }
  using type = float;
};
***/

// ------------------------------------------------------------
// valuelst値によって、
// 変数型の種類を変える(type)
// ------------------------------------------------------------
template<enum valuelst val>
struct myclass{
  myclass(){ cout << "MyClass<...>" << endl; }
  using type = int;
};

template<>
struct myclass<valuelst::p0>{
  myclass(){ cout << "MyClass<valuelst::p0>" << endl; }
  using type = float;
};

template<>
struct myclass<valuelst::p1>{
  myclass(){ cout << "MyClass<valuelst::p1>" << endl; }
  using type = string;
};



int main(){
  //cout << boost::format("Hello") << endl;

  // mytype<int>::type   id=10;
  //mytype<float>::type fd=0.1f;
  //cout << id <<endl;
  //cout << fd <<endl;

  //                                            // myclass<>::typeの型
  myclass<valuelst::p0>::type d0=0.1f;          //   p0 -->  float型
  myclass<valuelst::p1>::type d1=string("ちび"); //   p1 --> String型
  myclass<valuelst::p2>::type d2=100;           //   p0,p1以外 --> int型

  cout << d0 << endl; // "0.1"
  cout << d1 << endl; // "ちび"
  cout << d2 << endl; // "100"
}
