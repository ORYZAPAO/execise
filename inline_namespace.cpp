//
// インライン名前空間
//
//   この機能は、以下の用途に使用できる：
//
//   using namespaceによる名前空間省略の階層を段階的に指定する
//   APIのバージョニング
//
#include<iostream>
#include<boost/format.hpp>

using namespace std;

//
namespace myspace{

  namespace ver1{ ////////// <-- 旧版の関数に対して，namespace指定
    void f(){
      cout << "  f() ver1版" << endl;
    }
  }

  inline namespace ver2{ /// <-- デフォルトの関数に対して，inline namespace指定する
    void f(){
      cout << "  f() ver2版" << endl;
    }
  }
           
}


int main(){
  cout << "Call Old function (ver1::f())" << endl;
  myspace::ver1::f(); // 旧版の     f()を呼出  // "  f() ver1版"

  cout << "Call Default func (ver2::f())" << endl;
  myspace::f();       // デフォルト f()を呼出  // "  f() ver2版"
}
