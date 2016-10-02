#include<iostream>
#include<boost/format.hpp>

using namespace std;

#include"builder.h"
#include"director.h"

//
// Directorクラス（操作する側）
//
void Director::SetBuilder(Builder &bld){    
  m_pbld = &bld;
}
  
bool Director::Build(){
  m_pbld->buildPart1();
  m_pbld->buildPart2();
  return m_pbld->getResult();
}

//
// 仮想クラスBuilderを継承して、
// クラスを実装（操作される側）
//
class ConcreteBuilder_A :  public Builder {
  virtual void buildPart1(){ cout << "Build Part_A1" << endl; return; }
  virtual void buildPart2(){ cout << "Build Part_A2" << endl; return;}
  virtual bool getResult() { return true;}  
};

class ConcreteBuilder_B :  public Builder {
  virtual void buildPart1(){ cout << "Build Part_B1" << endl; return; }
  virtual void buildPart2(){ cout << "Build Part_B2" << endl; return;}
  virtual bool getResult() { return true;}  
};


int main(){
  ConcreteBuilder_A build_a; // Builderクラス(A)
  ConcreteBuilder_B build_b; // Builderクラス(B)

  Director          drct;    // Builderクラスを制御する、Directorクラス

  cout << "Preset build_a"<< endl;
  drct.SetBuilder(build_a);  // Builderクラス(A)をセット
  drct.Build();              // Directorクラスが、Builderクラス(A)を呼び出す
                             //  "Build Part_A1"
                             //  "Build Part_A2"
  cout << endl;

  
  cout << "Preset build_b"<< endl;
  drct.SetBuilder(build_b); // Builderクラス(B)をセット
  drct.Build();             // Directorクラスが、Builderクラス(B)を呼び出す
                            //  "Build Part_B1"
                            //  "Build Part_B2"
  cout << endl;
  
}
