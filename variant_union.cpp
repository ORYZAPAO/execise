// ----------------------------------------
// variant_union.cpp (c++17)
//
// クラステンプレート std::variant は型安全な union を表します。
// std::variant のインスタンスは任意の時点でその型の選択肢のいずれかの値を保持します。
// また、エラーが発生した場合は値を保持しないこともあります (この状態を得るのは簡単ではありません。 valueless_by_exception を参照してください)。
//
// variant は参照、配列、および void 型を保持することはできません。
// 空の variant もまた ill-formed です (代わりに std::variant<std::monostate> を使ってください)。
//
// 実行例
//   12
//   3.14
// ----------------------------------------
#include <variant>
#include <string>

#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 


// ------------------------------------------------------------
int main(){
  // union の代わりになるものだが、
  // 色々制限がある模様.
  
  //std::variant<int, int, int>   v, w;   // 同じ型は駄目みたい
  //std::variant<int, float, int> v, w;   // これもNG
  std::variant<int, float> v,w;

  // <int> で代入
  v = 12; // v は int を格納
  int i = std::get<int>(v);
  w = std::get<int>(v);
  w = std::get<0>(v); // 前行と同じ効果。
  w = v;              // 前行と同じ効果。

  cout <<  std::get<int>(w) << endl;;

  // <float で代入
  v = 3.14f; // v は float を格納
  w = v;
  cout <<  std::get<float>(w) << endl;;
}
