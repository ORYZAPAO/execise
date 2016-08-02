#include <iostream>
#include <map>
#include<string>

//using namespace std;

int main(){
  //       Key, Value
  std::map<int, std::string> maplist;

  //
  maplist.insert(std::make_pair( 0 , "犬"));
  maplist.insert(std::make_pair( 1 , "猫"));
  maplist.insert(std::make_pair( 2 , "ライオン"));
  maplist.insert(std::make_pair( 3 , "イロワケイルカ"));

  std::cout << maplist.at(2) << std::endl;  // c++11 "ライオン"
  std::cout << maplist.at(3) << std::endl;  // c++11 "イロワケイルカ"
  std::cout << maplist.at(00) << std::endl; // c++11  "犬"??

  std::cout << maplist[1] << std::endl;      // c++03 "猫"


}
