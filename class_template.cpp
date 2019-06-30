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
  //コンストラクタ宣言＋定義
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
  // メンバ関数の宣言
  void func();
  
  // --------------------------------------------------
  // メンバテンプレート関数の宣言
  template<typename T1> void func_template(T1 dat2);

};

// メンバ関数の定義（クラス定義の外で、定義）
template<typename T0> // <-- クラスのテンプレート
void MyClass<T0>::func(){
  cout << "[func] dat(" << dat << ")" << endl;
}

// メンバテンプレート関数の定義（クラス定義の外で、定義）
template<typename T0> // <-- クラスのテンプレート
template<typename T1> // <-- メンバ関数のテンプレート
void MyClass<T0>::func_template(T1 dat2){
  cout << "[func_template] dat(" << dat << "), "
                      << "dat2(" << dat2 << ")" << endl;
}


//////////////////////////////////////////////////
int main(){

  // MyClass<string>(string d, float *d2=f0)
  //
  //   MyClass<string>型のコンストラクタ
  //   func_template<>(<T1=int>) 
  //
  string  s0("MacOS");
  float   f0(100.0f);
  MyClass<string> a(s0, &f0);  // "[Constructor] dat(MacOS), ptr(0x7fff5a69b5c4)"
  a.func();                    // "[func] dat(MacOS)"
  a.func_template<int>(100);   // "[func_template] dat(MacOS)"
  cout << endl;
  
  // MyClass<int>(int d, int *d2=nullptr)
  //
  //   MyClass<int>型のコンストラクタ
  //   func_template<>(<T1=int>) 
  //
  MyClass<int>    b(111);      // [Constructor] dat(111), ptr(0)
  b.func();                    // [func] dat(111)
  b.func_template<int>(200);   // [func_template] dat(111), dat2(200)
  cout << endl;


  // MyClass<int>(int d, int *d2=nullptr)
  //
  //   MyClass<int>型のコンストラクタ
  //   func_template<>(<T1=string>) 
  //
  MyClass<int>    c(333);                             // [Constructor] dat(333), ptr(0)
  c.func();                                           // [func] dat(333)
  c.func_template<std::string>(std::string("jjjj"));  // [func_template] dat(333), dat2(jjjj)
  cout << endl;


  
  return 0;
}
