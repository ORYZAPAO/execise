#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 可変個引数テンプレート
//
//  1) テンプレートパラメータパック(typename...〜パック名)
//      template<typename... Args>
//        または
//      template<classname... Args> 
// 
//  2) 関数パラメータパック(Args... 〜パック名)
//      void func(T head, Args... args){
//        :
//      }
//
//  3) sizeof...(tail)
//       sizeof...(関数パラメータパック名) で、可変個引数の個数を返す
//
// ------------------------------------------------------------

void f(){ /// 再帰的に呼び出し時の、終了条件... 
  cout << "...End" << endl;
}

template<typename T, typename... Tail> 
void f(T head, Tail... tail){
  cout << head << "(" << sizeof...(tail) << ") ";

  f(tail...);  // 再帰的に呼び出す。
}


// ----------------------------------------
// ----------------------------------------
int main(){  
  f("犬", "猫", 3, "とり"); // "犬(3) 猫(2) 3(1) とり(0) ...End"  
}
