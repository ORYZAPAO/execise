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

  // std::bind(func, func()に渡す最初1個目のパラメータ, 〜に渡す2個目のパラメータ, 〜に渡す3個目のパラメータ ...); 
  //
  // 1) 説明
  //   要するに、"指定した関数をラッパーする"関数オブジェクトを作る
  //   
  //   std::bind(func,...)で指定した、関数funcから、
  //     指定したパラメータ並び、 func(_1, _2, _3, ...) を呼び出すような、関数オブジェクト(std::function型)を作る
  //   
  // 2) 例
  //    // func(１個目の引数, ２個目の引数, 100)関数呼出しをする、関数オブジェクトを作る
  //    auto NewFunc = std::bind(func, std::placeholders::_1, std::placeholders::_2, 100); 
  //   
  //       --->生成される 関数オブジェクト NewFunc のイメージ
  //
  //                  NewFunc(1,2){  // .......(*1)
  //                    return func(1,2,100);
  //                  }
  //
  //           (*1) std::function<int(int,int)> NewFunc;
  //                                  |   |
  //              std::placeholders::_1   std::placeholders::_2 
  //           func()へ渡す１個目の引数    ２個目の引数
  //
  //}

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
