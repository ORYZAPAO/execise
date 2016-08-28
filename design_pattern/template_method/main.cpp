#include <iostream>
#include <boost/format.hpp>

using namespace std;

#include"abstract.h"
#include"concrete.h"


int main(){

  AbstractClass *c = new ConcreteClass();

  c->display(); /// <<AAAAAAAAAA>>

  delete c;
  
}
