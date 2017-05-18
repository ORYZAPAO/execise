#include<iostream>
#include<string>
#include<boost/format.hpp>

//#include<initializer_list>

using namespace std;


void func(initializer_list<string> lst){
  for(auto p = lst.begin(); p!= lst.end(); p++){
    cout << boost::format(" %s \n") % *p ;
  }
}

int main(){
  // func({"Hello","Ohayo!!",999,"elephant"}); /// ::Error:: "int" --> Syntax Errror
  func({"Hello","Ohayo!!","elephant"});        /// ::OK   ::"int"
}
