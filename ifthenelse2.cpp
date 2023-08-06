#include<iostream>
#include <typeinfo>

template<bool bl, class Tr, class Fl>
struct myIf;


template<class Tr, class Fl>
struct myIf<true,Tr,Fl>{
  using T=Tr;
};

  
template<class Tr, class Fl>
struct myIf<false,Tr,Fl>{
  using T=Fl;
};


int main(){
  std::cout << "Hello" << std::endl;


  /// true  を指定すると、 int型
  /// false を指定すると、 char型
  
  /// Type i
  ///
  myIf<true, int, char> my;
  std::cout << "Type " << typeid(decltype(my)::T).name() << std::endl;

  /// Type c
  myIf<false, int, char> my2;
  std::cout << "Type " << typeid(decltype(my2)::T).name()  << std::endl;
}
