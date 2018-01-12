/* ======================================================================
 * == クラステンプレート定義と
 * == そのメンバ関数 ＆ メンバテンプレート関数の定義例
 * ==================================================================== */
#include<iostream>
#include<string>
#include<boost/format.hpp>
#include <typeinfo>

using namespace std;

//////////////////////////////////////////////////
// MyClassクラステンプレートの定義
//
template<typename T0>
class MyClass{
private:
  T0 dat;

public:  
  // --------------------------------------------------
  // MyClassクラステンプレートの,
  // メンバテンプレート関数（コンストラクタ）の宣言＋定義
  template<typename T1=int> 
  MyClass():dat(nullptr){
    cout << "[Constructor] dat(" << dat << ")" << endl;
  };

  template<typename T1=int> 
  MyClass(T0 d, T1 *ptr=nullptr):dat(d){
    //cout << "[" << typeid(d).name() << "]  " 
    cout << "[Constructor] dat(" << dat << "), "
                       << "ptr(" << ptr << ")" << endl;
  };

  // --------------------------------------------------
  // MyClassクラステンプレートの, メンバ関数の宣言
  void func();
  
  // --------------------------------------------------
  // MyClassクラステンプレートの, メンバテンプレート関数の宣言
  template<typename T1> void func_template();

};

// MyClassクラステンプレートの,　メンバ関数の定義（クラス定義の外で、定義）
template<typename T0>
void MyClass<T0>::func(){
  cout << "[func] dat(" << dat << ")" << endl;
}

// MyClassクラステンプレートの,　メンバテンプレート関数の定義（クラス定義の外で、定義）
template<typename T0>
template<typename T1>
void MyClass<T0>::func_template(){
  cout << "[func_template] dat(" << dat << ")" << endl;
}


//////////////////////////////////////////////////
int main(){

  // MyClass<string>(string d, float *d2=f0)
  //
  //   MyClass<T0=string>型のコンストラクタ
  //     MyClass<T0=string>(<T0=string d>, <T1=float> *) を呼び出す
  //
  string  s0("MacOS");
  float   f0(100.0f);
  MyClass<string> a(s0, &f0);  // "[Constructor] dat(MacOS), ptr(0x7fff5a69b5c4)"
  a.func();                    // "[func] dat(MacOS)"
  a.func_template<int>();      // "[func_template] dat(MacOS)"

  cout << endl;
  
  // MyClass<int>(int d, int *d2=nullptr)
  //
  //   MyClass<T0=int>型のコンストラクタ
  //     MyClass<T0=int>(<T0=int> d, <T1=float> *) を呼び出す
  //
  MyClass<int>    b(999);      // [Constructor] dat(999), ptr(0x0)
  b.func();                    // [func] dat(999)
  b.func_template<int>();      // [func_template] dat(999)

  cout << endl;

  return 0;
}
