#include<iostream>
#include<boost/format.hpp>

using namespace std;

//////////////////////////////////////////////////
class MyClass{
private:
  int dat;

public:  

  // --------------------------------------------------
  MyClass():dat(0){ };
  MyClass(int d):dat(d){
    cout << boost::format("[Constructor] (%d)") % dat << endl;
  };

  // [Constructor] Copy コピーコンストラクタ
  MyClass(const MyClass &my):dat(my.dat){
    cout << boost::format("[Constructor] Copy (%d)") % dat << endl;
  }

  // [Assignment] Copy コピー代入
  MyClass& operator=(const MyClass &my){
    dat = my.dat;
    cout << boost::format("[Assignment] Copy (%d)") % dat << endl;
    return(*this); }

  // [Constructor] Move ムーブコンストラクタ  // ムーブでは、const は受け取らないが、一応、動く
  MyClass(const MyClass &&my):dat(my.dat){
    cout << boost::format("[Constructor] Move (%d)") % dat << endl;    
  }

  // [Assignment] Move ムーブ代入
  //MyClass& operator=(const MyClass &&my){　 // ムーブでは、const は受け取らないが、一応、動く
  MyClass& operator=(MyClass &&my){
    dat = my.dat;
    cout << boost::format("[Assignment] Move (%d)") % dat << endl;
    return(*this); }

  // デストラクタ
  virtual ~MyClass(){ // 親クラスとして使う場合は、デストラクタはvirtual
    cout << "Destroy!!" << endl; 
  }


  // --------------------------------------------------
  // cout 
  friend ostream& operator<<(ostream& os, MyClass& my){
    cout << boost::format("dat[%d]") % my.dat;
    return(os);
  }
    
};


//////////////////////////////////////////////////
int main(){
  cout << "hello" << endl;

  MyClass my0(999);
  MyClass my1(1);

  cout << my0 << endl;
  cout << my1 << endl;

  my1 = std::move(my0);        // Move Assignment 
  MyClass my2(std::move(my0)); // Move Constructor
  
  cout << my0 << endl;
  cout << my1 << endl;
  cout << my2 << endl;
}
