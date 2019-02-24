#include <string>
#include <iostream>
#include <boost/format.hpp>

using namespace std;

struct Base1 {
  Base1() {}
  Base1(int d) {
    cout << boost::format("Base1 %d") % d << endl;
  }
};

struct Base2 {
  Base2() {}
  Base2(const std::string&s) {
    cout << boost::format("Base2 %s") % s << endl;
  }
};

struct Derived : Base1, Base2 {
  // Base1とBase2のコンストラクタを、Derivedで暗黙的に宣言する
  using Base1::Base1;
  using Base2::Base2;

  // Derived(), Derived(int), Derived(const std::string&)が暗黙宣言される
};

int main()
{
  Derived d1(3);       // OK
  Derived d2("hello"); // OK
}
