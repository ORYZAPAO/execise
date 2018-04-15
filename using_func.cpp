// basic.cpp
//
// 
//
#include<iostream>
#include<boost/format.hpp>

using namespace std;


//////////////////////////////////////////////////
// 別の名前空間で、同じ名前func()関数を定義
// 
namespace N1{
  void func(){
    cout << "Call N1::func()" << endl;
  }
}


namespace N2{
  void func(){
    cout << "Call N2::func()" << endl;
  }
}


//////////////////////////////////////////////////
int main(){

  using N1::func;
  func();    // "Call N1::func()" 

  { //                    同一スコープ内部で、
    //                    ２重に using指定 はできない模様
    using N2::func;  
    func();  // "Call N2::func()"
  }
}




