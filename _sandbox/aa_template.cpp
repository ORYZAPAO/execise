// ------------------------------------------------------------
// basic.cpp
//
// 名前つきパラメータのテスト
//
// ------------------------------------------------------------
#include<iostream>
#include<boost/format.hpp>

#include<type_traits>

using namespace std;

struct i0{};
struct i1{};
struct i2{};

struct i0_tag{ bool a=true; };
struct i1_tag{ bool b=true; };
struct i2_tag{ bool c=true; };

// ------------------------------------------------------------
// 
struct not_found{};

template< template<class>class Pred, class Head, class... Tail >
struct find_if_impl{
  typedef typename std::conditional< Pred<Head>::value,
                                    Head,
                                    typename find_if_impl<Pred, Tail...>::type>::type
    type;

};

// 特殊化
template< template<class>class Pred, class Head>
struct find_if_impl<Pred, Head>{
  typedef typename std::conditional< Pred<Head>::value,
                                    Head,
                                    not_found>::type
    type;

};



// ------------------------------------------------------------
int main(){
  cout << boost::format("Hello") << endl;
}
