//
// std::function による、関数オブジェクト 
// 
// 

#include<iostream>
#include<string>
#include<functional>

#include<boost/format.hpp>

using namespace std;

//--------------------------------------------------
// 通常の関数
int func_1(int d){
  cout << "func_1(通常の関数)" << endl;
  return(d);
}

//--------------------------------------------------
// 関数オブジェクト(無名クラス)
class func_2{
public:
  int operator()(int d){
    cout << "func_2(関数オブジェクト)" << endl;
    return(d);
  }
};

//--------------------------------------------------
// ラムダ関数
auto func_3 = [](int d){
  cout << "func_3(ラムダ関数)" << endl;
  return(d);
};

//--------------------------------------------------
//--------------------------------------------------
int main()
{
  std::function<int(int)> f1 = func_1;   // 通常の関数
  std::function<int(int)> f2 = func_2(); // 関数オブジェクト(無名クラス)
  std::function<int(int)> f3 = func_3;   // ラムダ関数

  // func_1(通常の関数)
  // func_2(関数オブジェクト)
  // func_3(ラムダ関数)
  f1(10);
  f2(20);
  f3(30);
  
  return 0;
}
