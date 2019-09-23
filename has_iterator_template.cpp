// ------------------------------------------------------------
// basic.cpp
//
// 
//
// ------------------------------------------------------------
#include<iostream>
#include<vector>

using namespace std;


// ------------------------------------------------------------
// イテレータがあるか、<引数>で判断する
//
//
struct has_iterator_impl{
  // イテレータがあれば、こちらが展開され、std::true_type  
  // 
  //   --> "T::iterator が存在するかで判断
  template<class T>  
  static std::true_type check(typename T::iterator *);

  // 無ければ、こちらが展開される
  template<class T>
  static std::false_type check(...);
};

template<class T>
class has_iterator :
  public decltype(has_iterator_impl::check<T>(nullptr)) {};

// ------------------------------------------------------------
// イテレータがあるか判断する
//
//
struct has_iterator_impl2{
  template<class T>
  //static auto check() -> decltype(std::declval<T::iterator*>,
  static auto check() -> decltype(T::begin(),
                                  std::true_type());  
  //template<class T>
  //static auto check() -> decltype(std::false_type());  
};


template<class T>
class has_iterator2 :
  public decltype(has_iterator_impl2::check<T>()) {};
// ------------------------------------------------------------




int main(){
  std::cout << "Hello" << std::endl;
  
  std::cout << "-------------------" << std::endl;
  std::cout << has_iterator<std::vector<int>>::value << std::endl;
  std::cout << has_iterator<int>::value              << std::endl;

  std::cout << "-------------------" << std::endl;
  std::cout << has_iterator2<std::vector<int>>::value << std::endl;
  //std::cout << has_iterator2<int>::value              << std::endl;

}

