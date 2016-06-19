#include<iostream>
using namespace std;

struct Functor{
  int operator()(){
    return 100;
  }
};

int main(){
  int      val;
  Functor  func;

  val = func();
  cout << "valueo=" << val << endl;
}
