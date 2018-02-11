//
// std::remove_reference 変数型情報から、参照を外す
//

#include<iostream>
#include<boost/format.hpp>
#include<string>

#include<algorithm>

using namespace std;

///#include"remove_reference_KARI_template.hpp"


int main(){
  string   s0 = "猫、犬、うさぎ"; // std::sting
  string &rs0 = s0;              // std::sting& (参照)

  // 参照を使ってみただけ。。。
  // 
  cout << boost::format("string   s0(%s)") %  s0 << endl;
  cout << boost::format("string &rs0(%s)") % rs0 << endl;
  cout << endl;
  
  // 指定した型情報(例:string&)から、参照を外して(例:string)、
  // その型(string)で、変数SSSを定義
  std::remove_reference<string&>::type  SSS("あかねいろ");
  cout << boost::format("remove_reference<string&>::type(string& --> string) SSS(%s)") % SSS << endl;

  return 0;
}
