// ------------------------------------------------------------
// タグディスパッチ
//
// "タグ"を割り当て、それを対応した処理を振り分ける
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

using namespace std;

// ------------------------------------------------------------
// 識別に使うタグ
struct TagA{};
struct TagB{};
struct TagC{};

// ------------------------------------------------------------
// ("タグ" の振り分けで使用)
struct ClassA{
  using tag = TagA;
};
struct ClassB{
  using tag = TagB;
};
struct ClassC{
  using tag = TagC;
};
struct ClassAAA{
  using tag = TagA;
};


// ------------------------------------------------------------
// "タグ" 別の処理
//
template<class T> void sub_func(T &t, std::string &str, TagA){
  std::cout << "TagA=" << str << std::endl;
}
template<class T> void sub_func(T &t,std::string &str, TagB){
  std::cout << "TagB=" << str << std::endl;
}
template<class T> void sub_func(T &t,std::string &str, TagC){
  std::cout << "TagC=" << str << std::endl;
}


// ------------------------------------------------------------
// "タグ" の振り分け
template<class T> void func(T &&t, std::string &str){
  sub_func<T>(t, str, typename T::tag());
}

// ------------------------------------------------------------
int main(){
  cout << boost::format("Hello") << endl;

  std::string msg("怪人二十面相");

  func(ClassA(), msg);   // "TagA=怪人二十面相"
  func(ClassB(), msg);   // "TagB=怪人二十面相"
  func(ClassC(), msg);   // "TagC=怪人二十面相"
  func(ClassAAA(), msg); // "TagD=怪人二十面相"
}
