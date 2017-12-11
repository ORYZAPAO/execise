#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ----------------------------------------
// 可変個引数テンプレート
// ----------------------------------------
void f(){}

template<typename T, typename... Tail>
void f(T head, Tail... tail){
  cout << head << " ";

  f(tail...);  // 再帰的に呼び出す。
}


// ----------------------------------------
// ----------------------------------------
int main(){
  // "犬 猫 3 とり"  
  f("犬", "猫", 3, "とり");
  cout << endl;

}
