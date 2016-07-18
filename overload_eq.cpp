#include<iostream>
#include<boost/format.hpp>

using namespace std;


class ABC{
public:
  int m_dat;

  ABC(int abc=0):m_dat(abc){}

  ///
  /// 代入演算子 "=" Overload 
  /// 
  ABC & operator=(ABC &abc){
    m_dat = abc.m_dat;
    return (*this); /// 自身への参照を返す
  }

  void  print(){
    cout << m_dat << endl;
  }

};



int main(){
  ABC abc(100);
  ABC tmp(500);

  abc.print(); /// 100

  abc = tmp;   /// abc <- tmp(500)

  abc.print(); /// 500 

}
