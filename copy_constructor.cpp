#include<iostream>
#include<boost/format.hpp>

using namespace std;


class ABC{
public:
  int m_dat;

  /// 
  /// コピー/代入禁止
  ///
  ABC(ABC &)=delete;               /// コピーコンストラクタを削除で、コピー不可にする
  ABC & operator = (ABC &)=delete; /// 代入演算子　の削除で、代入不可にする

  ///
  ABC(int abc=0):m_dat(abc){}
  
  void  print(){
    cout << m_dat << endl;
  }

};



int main(){
  ABC abc(100);
  
  abc.print(); /// 100

  /// コンパイルエラー(コピー禁止)
  ///
  /// "ABC tmp(abc);"  <--- /// Compile Error
  ///
  /// const_class.cpp:33:7: error: call to deleted constructor of 'ABC'
  /// ABC tmp(abc);
  ///     ^   ~~~
  /// const_class.cpp:14:3: note: 'ABC' has been explicitly marked deleted here
  ///  ABC(ABC &)=delete;
  ///  ^
  ///
  ABC tmp;
  /// ABC tmp(abc);  <--- /// Compile Error
  tmp.print(); /// 0  != 500 


  /// コンパイルエラー(代入禁止)
  ///
  /// "tmp2 = abc;" <--- /// Compile Error
  //
  /// const_class.cpp:46:8: error: overload resolution selected deleted operator '='
  ///   tmp2 = abc;
  ///   ~~~~ ^ ~~~
  /// const_class.cpp:15:9: note: candidate function has been explicitly deleted
  ///   ABC & operator = (ABC &)=delete;
  ///         ^
  /// const_class.cpp:49:3: error: use of undeclared identifier 'tmp'; did you mean 'tmp2'?
  ///   tmp.print();
  ///   ^~~
  ABC tmp2;
  /// tmp2 = abc; <--- /// Compile Error
  tmp.print(); /// 0  != 500

}
