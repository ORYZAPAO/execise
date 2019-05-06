// idiom_BaseFromMember.cpp
//
// メンバによる基本クラスの初期化(Base-from-Member) 
//
//
// 派生クラスで、派生クラスやそのクラスのデータメンバによって、基本クラスを初期化することが必要になる場合がある。
//
// C++規格では、派生クラスのデータメンバのコンストラクタ(が存在するならばその)実行前に、基本クラスが初期化される
//
// このイディオムは、
//   (1) パラメータとなるデータメンバを private な基本クラスに押し込み、
//   (2) 基本クラスのリスト中でその private な基本クラスを、依存する基本クラスよりも前に置くというものである。
//
// C++規格では、常に、基本クラスのリスト中に宣言された順序で、基本クラスが初期化されることが定められている。
//
//
/***
 +--------------+        +--------------+
 |std::streambuf|        |std::streambuf|       
 +--------------+        +--------------+
        |                   |       |
        |                   |  +--------------+   +--------------+
 +--------------+           |  | Base       +-----| Base_phase   |
 |  fdostream   |           |  +--------------+   +--------------+
 +--------------+           |                         |(private)
                            |                         |
                         +---------------------------------+
                         |  fdostream                      |
                         +---------------------------------+
 ***/

#include<iostream>
#include <streambuf>  // std::streambuf 用
//#include <ostream>    // std::ostream 用
#include<boost/format.hpp>

using namespace std;


// ------------------------------------------------------------
// 
class Base
  : public std::streambuf
{
public:
  explicit Base( int fd );
  //...
};


struct Base_pbase
{
  Base m_Base;

  explicit Base_pbase( int fd )
    : m_Base( fd )
  {}
};


// ------------------------------------------------------------
// 派生クラス
// ------------------------------------------------------------ 
class fdostream
    : private Base_pbase
    , public  std::ostream   // <-- fdostreamクラスの後に、この基本クラスを初期化させたい 
{
  typedef Base_pbase    pbase_type; // 
  typedef std::ostream  base_type;  // 

public:
  explicit fdostream( int fd )
    : pbase_type( fd ), base_type( &m_Base )
  {}
  //...
};



// ------------------------------------------------------------
// ------------------------------------------------------------ 
int main(){

}
