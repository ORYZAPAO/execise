// pimple_idiom.cpp
//
// Pimple イディオム のテクニック
//
// private宣言したメンバの実装を隠したい場合に使う．
//
//   class User{
//   private:
//     int func(){ return 100; } <-- private宣言をしているのに，
//                                   中身が丸見え
//   };
//

#include<iostream>
using namespace std;

// ------------------------------------------------------------
// 実装　
//
//  ここでは，まとめて記述しているが，
//  実際は，ヘッダファイルやcppファイル等に，別々に定義を書く
// ------------------------------------------------------------

/*
 *　Prv.h (本来は，別ファイルに記述)
 */
class Prv{
public :
  int func();
  int data;

  Prv() : data(99){}
  
};

/* 
 *　Prv.cpp　(本来は，別ファイルに記述、libraryとして提供)
 */
int Prv::func(){
  return 100;
}

// ------------------------------------------------------------
//  使う側
// ------------------------------------------------------------

// #include "Prv.h"　// ヘッダを読み込む

class User{
public:
  User() : ap(new Prv){}
  ~User(){}

  class Prv *ap;

  int func()   { return( ap->func() ); } // <-- 実装を隠す
  int getData(){ return( ap->data   ); } // <-- 実装を隠す

};


// ------------------------------------------------------------
// ------------------------------------------------------------
int main()
{
  User uu;

  int val = uu.func();

  cout << "uu.func()    = " << uu.func()    << endl;  // "uu.func()    = 100"
  cout << "uu.getData() = " << uu.getData() << endl;  // "uu.getData() = 99"
}
