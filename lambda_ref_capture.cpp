
#include<iostream>

using namespace std;

int main(){
  // 参照元
  int val=5;

  // val を参照キャプチャ
  auto func  = [&val](int m) -> int { return val*m; } ;

  cout << "val= " << func(10) << endl; // 50
  cout << "val= " << func(5) << endl;  // 25
  val =2;
  cout << "val= " << func(5) << endl;  // 10

}
