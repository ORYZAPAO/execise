// ------------------------------------------------------------
// パラメータ化継承w
// 
// テンプレート引数で、基本クラスを指定する方法
//
// 既存クラスへのメンバ追加、機能拡張ができる
//
// https://ja.wikibooks.org/wiki/More_C%2B%2B_Idioms/%E3%83%91%E3%83%A9%E3%83%A1%E3%83%BC%E3%82%BF%E5%8C%96%E3%81%95%E3%82%8C%E3%81%9F%E5%9F%BA%E6%9C%AC%E3%82%AF%E3%83%A9%E3%82%B9(Parameterized_Base_Class)
//  More C++ Idioms/パラメータ化された基本クラス(Parameterized Base Class)
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>
#include<string>

using namespace std;

// ------------------------------------------------------------
//  パラメータ化継承のクラスに渡す、クラス
// ------------------------------------------------------------
struct text{
  std::string _str;
  text(std::string &&str):_str(str){}
  text(std::string &str):_str(str){}
  text(char        *pstr):_str(pstr){}

  virtual void print(){
    std::cout << _str <<  endl;
  }
};

// ------------------------------------------------------------
//　パラメータ化継承のクラス
// ------------------------------------------------------------
template<class T>
struct bold : public T{
  using T::T;
  virtual void print(){
    std::cout << "<br>" << this->_str << "</br>" << endl;
  }
};

template<class T>
struct italic : public T{
  using T::T;
  virtual void print(){
    std::cout << "<i>" << this->_str << "</i>" << endl;
  }
};


// ------------------------------------------------------------
int main(){
  text         t("ロンドン");
  bold<text>   b("パリ");
  italic<text> i("東京");  
  t.print(); // "ロンドン"
  b.print(); // "パリ"
  i.print(); // "東京"
  cout << endl;
  

  cout << "仮装継承で実行" << endl;
  //
  text *ptxt0, *ptxt1, *ptxt2;
  ptxt0 = &t;
  ptxt1 = &b;
  ptxt2 = &i;
  ptxt0->print(); // "ロンドン"
  ptxt1->print(); // "パリ"
  ptxt2->print(); // "東京"

}
