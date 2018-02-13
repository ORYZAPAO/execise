#include<iostream>
#include<boost/format.hpp>
#include<vector>

using namespace  std;


//----------------------------------------
//----------------------------------------
class A{
public:
  int a;
  A():a(100){}
  A(int d):a(d){}

  virtual ~A(){}
};

class B : public A{
public:
  //
  using A::A; // <---- 基本クラス（派生元の）Aのコンストラクタを利用

  B(){}
  virtual ~B(){}
};


//----------------------------------------
//----------------------------------------
template<typename T>
class vec2 : public vector<T>{
public:

  //
  using vector<T>::vector; // <-- 基本クラス（派生元の）Aのvector<T>のコンストラクタを利用

  //------------------------------
  // 要素を返す。
  // もし範囲外の時には、例外を送出（std::out_of_rangex）
  //------------------------------
  T& operator[](int i){
    return vector<T>::at(i);   
  }

  const T& operator[](int i) const{  // const版
    return vector<T>::at(i); 
  }

  virtual ~vec2(){}
  
};



//----------------------------------------
//----------------------------------------
int main(){
  vec2<int> list={1,2,3,4,5,6,7};

  // "1,2,3,4,5,6,7,"
  for(auto &x : list){
    cout << x << ",";
  }
  cout << endl;

  // 例外なし
  // "7"
  cout << list[list.size()-1] << endl;;

  // 範囲外を指定したため、例外発生
  // "libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector"
  //cout << list[list.size()] << endl;;


  A aa;
  B bb(99);

  cout << aa.a << endl;
  cout << bb.a << endl;
  
}
