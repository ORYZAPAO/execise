#include <iostream>
#include <vector>
#include <boost/format.hpp>

using namespace std;

int main(){
  const int NUM=10;
  vector<int> dat(NUM);

  /// 
  int ct=100;

  ///
  /// for(auto i=dat.begin(); i!=dat.end(); i++) {
  ///    *i = ct++;
  ///  } 
  ///  ...以下と等価
  for_each( dat.begin(), dat.end(), [&ct](int &i){  i = ct++; } );

  cout << ct <<endl;

  /// 
  /// for(auto i=dat.begin(); i!=dat.end(); i++) {
  ///    cout << boost::format("%d") % *i << endl;
  /// }
  ///  ...以下と等価
  for_each(dat.begin(), dat.end(), [](int &i){ cout << boost::format("%d") % i << endl; } );
}
