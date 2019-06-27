// optional.cpp
//
// std::optional<T> 
//
//  あらゆる型に対して、「共通の無効値状態」を表現できる型
//
#include<iostream>
#include<optional>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// val値が奇数であれば、その値を返す
//
std::optional<int> isOdd(int val){
  if( (val % 2) == 1 ){
    return val; 
  }

  return std::nullopt;
}


// val値が偶数であれば、その値を返す
//
std::optional<int> isEven(int val){
  if( (val % 2) == 0 ) {
    return val;
  }

  return std::nullopt;
}

// ------------------------------------------------------------
int main(){
  std::optional<int> rslt;
  
  // 100 は 奇数か？
  rslt = isOdd(100); 
  if( rslt ){ // 結果を取得
    // NO!! ... 100は奇数ではない。実行されない ---
    cout << boost::format("奇数 %d") % rslt.value() <<  endl; 
  }

  // 100 は 偶数か？
  rslt = isEven(100);
  if( rslt ){ // 結果を取得
    // YES!! 100 は 偶数
    //                                 値は、value()で取得
    cout << boost::format("偶数 %d") % rslt.value() <<  endl;   // "偶数 100" と表示
  }
}
