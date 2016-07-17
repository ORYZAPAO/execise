//
// lamda式と、lamda式からの変数の参照（キャプチャ）
//

#include<iostream>

using namespace std;

int main(){
  // 参照元
  int val;

  ///
  /// val を参照キャプチャ
  ///
  cout << "Reference Capture" << endl;
  val=5;
  auto func_r  = [&val](int m) -> int { return val*m; } ;

  cout << "val= " << func_r(10) << endl; // 50
  cout << "val= " << func_r(5) << endl;  // 25
  val =2;
  cout << "val= " << func_r(5) << endl;  // 10
  cout << endl;

  ///
  /// val をコピーキャプチャ
  ///
  cout << "Copy Capture" << endl;
  val=5;
  auto func_c  = [val](int m) -> int { return val*m; } ;

  cout << "val= " << func_c(10) << endl; // 50
  cout << "val= " << func_c(5) << endl;  // 25
  val =2;
  cout << "val= " << func_c(5) << endl;  // 25 != 10(Referrence)
  cout << endl;

}
