//
// std::bindは
// 指定した関数をラップした、std::functionを作る
//

#include<iostream>
#include<functional>
#include<boost/format.hpp>

using namespace std;
//
int func(int a, int b, int c){
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  return (a+b+c);
}

//
int main(){
  using namespace std::placeholders; 

  // 1) 説明
  //   std::bindは、bind(func,...)で指定した関数funcから、
  //   同じく指定した引数の並びbind(func,_1,_2,...)のfunction オブジェクトを作る
  //
  //   例）std::bind(func, std::placeholders::_1, std::placeholders::_2, 100); 
  //        func(１個目の引数, ２個目の引数, 100)呼出しをラップした、function オブジェクトを作る
  //   
  //       --->std::bindで、生成される function オブジェクトの形式
  //
  //                 std::function<int(int,int)> 
  //                                    |   |
  //                std::placeholders::_1    std::placeholders::_2 
  //             func()へ渡す１個目の引数    ２個目の引数
  //

  std::function<int(int,int)> ff = std::bind(func, std::placeholders::_1, 100, std::placeholders::_2);
  //std::function<int(int,int)> ff = std::bind(func, _1,  100, _2);
  //auto ff = std::bind(func, _1, 100, _2);

  // "1"
  // "2"
  // "3"
  // "func(1,2,3) = 6"
  cout << boost::format("func(1,2,3) = %d") % func(1,2,3) << endl;

  // "1"
  // "100"
  // "2"
  // "ff(1,2)      =103"
  // "   ※func(1,100,2)の呼出をラップした ff()"
  cout << boost::format("ff(1,2)      =%d") % ff(1,2)     << endl;
  cout << boost::format("   ※func(1,100,2)の呼出をラップした ff()") << endl;
  
}
