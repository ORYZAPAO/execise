// exception.cpp
//  自作の例外クラス 例
// 
#include<iostream>
#include<boost/format.hpp>

#include<exception>
#include<stdexcept> // 標準の例外クラス定義

using namespace std;

// --------------------------------------------------------------------------------
// #include<stdexcept> で定義されている、例外クラス（std::exception がベース）
// --------------------------------------------------------------------------------
//   logic_error 	プログラムの実行前に検出可能なエラー（論理エラー）を示す 	
//   domain_error 	定義域エラーを示す 	
//   invalid_argument 	不正な引数を示す 	
//   length_error 	長すぎるオブジェクトを作ろうとしたことを示す 	
//   out_of_range 	引数が許容範囲外であることを示す 	
//   runtime_error 	プログラム実行時にのみ検出可能なエラー（実行時エラー）を示す 	
//   range_error 	内部計算によって、値が範囲外になったことを示す（値域エラー） 	
//   overflow_error 	数値計算の結果がオーバーフローしたことを示す 	
//   underflow_error 	数値計算の結果がアンダーフローしたことを示す
// --------------------------------------------------------------------------------

// 自作の例外クラス 例
//
//     std::exception{ すべての例外クラスの基本クラス
//    };
class myexcept : public std::logic_error{
  using logic_error::logic_error; // Memo) 基本クラスlogic_errorの、コンストラクタを使用
};


int main(){

  // "例外を発生"
  // "...[Detect Exception]何か起きた！！"
  try{

    cout << "例外を発生"  << endl;
    myexcept e("何か起きた！！");
    throw e ; // 例外送出（スルー）
    // Memo) C++文法的には、throw に渡す型は、なんでも良さそうだが、
    //       実際は、catch し易いように、std::exceptionの派生クラス型を使う

  }catch(std::exception &e){
    cerr << "...[Detect Exception]" << e.what() << endl; 
  }

}
