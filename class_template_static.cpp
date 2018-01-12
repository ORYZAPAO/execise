/* ======================================================================
 * == クラステンプレート定義と
 * ==   そのメンバ関数の定義例(静的メンバ変数と関数)
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
  T0         dat;

public:  

  // --------------------------------------------------
  MyClass():dat(nullptr){
    cout << "[Constructor] dat(" << dat << ")" << endl;
  };

  MyClass(T0 d):dat(d){
    cout << "[Constructor] dat(" << dat << ")" << endl;
  };

  void func(){
    cout << "[func] dat(" << dat << ")" << endl;
  }

  // --------------------------------------------------
  // クラステンプレートの
  //   静的メンバ変数と、静的メンバ関数
  // --------------------------------------------------
  static T0  dat2t0_st; //  T0 型の "静的変数" dat2t0_st  の宣言
  static int dat3int_st; // int型の "静的変数" dat3int_st の宣言

  // MyClassクラステンプレートの, "静的メンバ関数" の宣言＋定義
  static void set_static(T0 &d) { // "左-参照"版
    cout << "[set & (Left-Reference)] dat2t0_st <-- d(" << d << ")" << endl;
    dat2t0_st=d;
  }
  static void set_static(T0 &&d){ // "右-参照"版
    cout << "[set && (Right-Reference)] dat2t0_st <-- d(" << d << ")" << endl;
    dat2t0_st=d;
  }

  // "静的メンバ関数" の宣言
  static void print_static();
};

// MyClassクラステンプレートの,
//   T0  型の"静的変数" dat2t0_st の定義
template<typename T0>
T0  MyClass<T0>::dat2t0_st;

//   int 型の"静的変数" dat3int_st の定義
template<typename T0>
int MyClass<T0>::dat3int_st = 0; // 初期値

//   "静的メンバ関数" の定義
template<typename T0>
void MyClass<T0>::print_static(){
  cout << "[func_static] dat2t0_st(" << dat2t0_st << ")" << endl;
}


//////////////////////////////////////////////////
int main(){

  // MyClass<string>(string d)
  //
  string  s0("MacOS");
  MyClass<string> a(s0);           // "[Constructor] dat(MacOS), ptr(0x7fff5a69b5c4)"
  a.func();                        // "[func] dat(MacOS)"

  //  静的メンバをCall
  string  s1("static WINDOWS");
  MyClass<string>::set_static(s1); // "[set & (Left-Reference)] dat2t0_st <-- d(static WINDOWS)"
  MyClass<string>::print_static(); // "[func_static] dat2t0_st(static WINDOWS)" ...(*A)
  
  cout << endl;
  
  // MyClass<int>(int d)
  //
  MyClass<int>    b(999);          // [Constructor] dat(999), ptr(0x0)
  b.func();                        // [func] dat(999)

  //   静的メンバをCall
  MyClass<int>::set_static(100);   // "[set && (Right-Reference)] dat2t0_st <-- d(100)"
  MyClass<int>::print_static();    // "[func_static] dat2t0_st(100)"
  
  cout << endl;

  // 再度、MyClass<string>
  // 
  MyClass<string>::print_static(); // "[func_static] dat2t0_st(static WINDOWS)" ...(*A)と同じ値になるはず
  cout << endl;

  
  return 0;
}
