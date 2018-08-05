// return_reference.cpp
//
// 参照型 を 返す関数 を、通常の型と、参照型で受ける
//
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 

class CC{
private:
  int _dat;
public :
  CC():_dat(999){}

  // (通常の)値を返す
  int   get()   { cout<<"[Call get()] return reference value"     << endl; return(_dat); }

  // "参照型で" 値を返す
  int &get_ref(){ cout<<"[Call get_ref()] return NOT reference value" << endl; return(_dat); }
};


// ------------------------------------------------------------
int main(){
  CC cc;
  cout << boost::format("Hello") << endl;



  //
  // "int型"を返す関数値を、   "int型"変数 d0 で受ける
  //
  // その後、d0 <--111 に更新しても、cc._datメンバ変数は更新されない(初期値999）
  //
  int d0 = cc.get();
  cout << boost::format("int d0=%d") % d0 << endl;
  cout << boost::format("SET 111 to d0") << endl;
  // d0 <--111 に更新
  d0 = 111;
  cout << boost::format("cc._dat=%d") % cc.get() << endl;  // "cc._dat=999"
  cout << endl;

  //
  // "int参照型"を返す関数値を、"int型"変数 d1 で受ける
  //
  // その後、d1 <--111 に更新しても、cc._datメンバ変数は更新されない(初期値999）
  //
  int d1 = cc.get_ref();
  cout << boost::format("int d1=%d") % d1 << endl;
  cout << boost::format("SET 111 to d1") << endl;
  // d1 <--111 に更新
  d1 = 111;
  cout << boost::format("cc._dat=%d") % cc.get() << endl;  // "cc._dat=999"
  cout << endl;

  // "int参照型"を返す関数値を、"int参照型"変数 &dr で受ける
  //
  // dr <--111 に更新すると、参照型で受けているので、cc._datメンバ変数=111になる
  //  
  int &dr = cc.get_ref();
  cout << boost::format("int dr=%d") % dr << endl;
  cout << boost::format("SET 111 to dr") << endl;
  // dr <--111 に更新
  dr = 111;                                               
  cout << boost::format("cc._dat=%d") % cc.get() << endl;   // "cc._dat=111"
  cout << endl;

}
