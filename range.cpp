#include<iostream>
#include<vector>
#include<boost/format.hpp>

using namespace std;

// ----------------------------------------
// Range Sample
//
// 実行例
//  Step.1) c array and Rabge
//    Scope For
//   0 1 2 3 4 5 6 7
//  
//  Step.2) c++ vector<> and Range
//   * Scope For
//   0 1 2 3 4 5 6 7
//   * begin()-end() Roop
//   0 1 2 3 4 5 6 7
// ----------------------------------------
int main(){

  //------------------------------
  // C言語由来の配列 と Range
  //------------------------------
  cout << "Step.1) c array and Rabge" << endl;
  int  ll[] = {0,1,2,3,4,5,6,7}; // 従来のC形式の配列

  
  cout << "  Scope For" << endl;
  for(auto &d : ll){   // 範囲for文が、使用可
    cout << " " <<  d;
  }
  cout << endl << endl;

  
  //------------------------------
  // C++ の vector<> と Range
  //------------------------------
  cout << "Step.2) c++ vector<> and Range" << endl;
  vector<int> vec ={0,1,2,3,4,5,6,7}; // 従来のC形式の配列

  cout << " * Scope For" << endl;
  for(auto &d : vec){   // 範囲for文
    cout << " " << d;
  }
  cout << endl;

  
  cout << " * begin()-end() Roop" << endl;
  for(auto i=vec.begin(); i<vec.end(); i++){   // begin() - end() でループ
    cout << " " << *i;
  }
  cout << endl;
  
}
