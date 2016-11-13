#include<iostream>
#include<vector>
#include<boost/format.hpp>

using namespace std;


int main(){
  vector<int> data ={0,1,2,3,4,5,6,7,8,9};

  /// 範囲つきfor
  for( int x : data){
    cout << boost::format("data = %d") % x << endl;
  }
}
