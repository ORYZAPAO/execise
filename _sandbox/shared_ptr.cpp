#include<iostream>
#include <memory>
#include <utility>

using namespace std;

template <class T, class A1, class A2>
std::shared_ptr<T> factory(A1&& a1, A2&& a2) {
  return std::shared_ptr<T>(new T(std::forward<A1>(a1), std::forward<A2>(a2)));
}

struct A {
  A(int&, const double&) {}
};

int main()
{
//std::shared_ptr<A> sp1 = factory<A>(2, 1.414);  // error: 2 will not bind to int&

  int i = 2;
  int iiii = 3;
  std::shared_ptr<A> sp2 = factory<A>(i, 1.414);  // OK

  cout << endl;
}
