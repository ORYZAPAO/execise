
//
// clang++ -std=c++1y string_view.cpp
//

#include<iostream>

#include <iostream>
#include <experimental/string_view>

using namespace std;

int main(){
  const char s[] = "01234567890";

  // string_view
  //   char文字列などに対して、
  //   高級な文字列クラス(string)の機能を使える
  //
  //   string("klkl") 経由で使うのと比べて、コピーをしないので効率が良い
  std::experimental::string_view view =  std::experimental::string_view(s);
   
  //
  cout << s << endl;                  // "01234567890"
  cout << view.at(2) << endl;         // "2"
  cout << view.substr(4,5) << endl;   // "45678"

}
