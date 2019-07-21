// ------------------------------------------------------------
// 
//
// 
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>
#include <type_traits>
#include<typeinfo>

using namespace std;

// ------------------------------------------------------------
// ------------------------------------------------------------
template<int  N> struct int_{};
template<bool N> struct bool_{};

struct cont_ {};
struct end_ {};

// ----------------------------------------
template<bool Cond>
auto is_end(bool_<Cond>)
  -> typename std::conditional<Cond, end_, cont_>::type;

// ----------------------------------------
template<class T, int N>
auto add_pointers_impl(T, int_<N>,cont_)
  -> decltype(add_pointers_impl(std::declval<T*>,
                                int_<N - 1>(),
                                std::declval<decltype
                                  (
                                   is_end(bool_<N - 1 == 0>())
                                  )
                                >() )
              );

template<class T, int N>
auto add_pointers_impl(T, int_<N>,cont_)
  -> T;

// ----------------------------------------
template<class T, int N>
auto add_pointers(T, int_<N>)
  -> decltype(add_pointers_impl(
                                std::declval<T>(),
                                int_<N>(),
                                std::declval<decltype(
                                  is_end(bool_<N == 0>())
                                )>() ));

// ------------------------------------------------------------
// -- 定義例 // 
// ------------------------------------------------------------
typedef decltype(
                 add_pointers(std::declval<int>(), int_<3>())
                 ) result;

// ------------------------------------------------------------
int main(){
  cout << boost::format("Hello") << endl;

  auto a -> add_pointers(std::declval<int>(), int_<3>() );

  std::cout << typeid(a).name() << endl;
}

