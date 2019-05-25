// ----------------------------------------
// basic.cpp
//
// クラステンプレート std::variant は型安全な union を表します。
// std::variant のインスタンスは任意の時点でその型の選択肢のいずれかの値を保持します。
// また、エラーが発生した場合は値を保持しないこともあります (この状態を得るのは簡単ではありません。 valueless_by_exception を参照してください)。
//
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
  std::variant<int, float> aa;

  std::variant<int, float> v, w;
  v = 12; // v は int を格納します。
  int i = std::get<int>(v);
  w = std::get<int>(v);
  w = std::get<0>(v); // 前行と同じ効果。
  w = v; // 前行と同じ効果。
  
  //cout << boost::format("Hello") << std::get(w) << endl;
  cout <<  std::get(w) << endl;


}
