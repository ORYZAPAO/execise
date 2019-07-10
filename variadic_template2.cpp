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

// ------------------------------------------------------------
// 可変長テンプレート引数の展開（関数）
// ------------------------------------------------------------
template<class T>
void  func(T a) { }

template<class T, class ...Args>
void func(T t,Args... args){
  std::cout << t << "," << endl;
  func(args...) ;
}

template <int N, class T, class ...Args>
void func2(T t, Args ...aa){}

// ------------------------------------------------------------
// 可変長テンプレート引数の展開（クラス）
// ------------------------------------------------------------
template<class T, class ...Args>
struct XX;

template<class T>
struct XX<T>{
public:
  XX(){ std::cout << "END" << std::endl;  }
};

template<class T, class... Args>
struct XX : public XX<Args...> {
public:
  XX(){ std::cout << "HAPPY, "; }
};

// ----------------------------------------
// ----------------------------------------
int main(){
  // "犬(3) 猫(2) 3(1) とり(0) ...End"  
  func("犬", "猫", 3, "とり"); 

  // "END"
  XX<int> a0;     
  std::cout << std::endl;
  
  // "END
  //  HAPPY,"
  XX<int,int> a1;
  std::cout << std::endl;

  // "END
  //  HAPPY, HAPPY,"
  XX<int,int,int> a2;      
  std::cout << std::endl;

  // "END
  //  HAPPY, HAPPY, HAPPY,"
  XX<int,int,int,int> a3;
  std::cout << std::endl;

}
