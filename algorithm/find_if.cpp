#include <iostream>
#include <boost/format.hpp>
#include <vector>

using namespace std;

int main(){
  vector<int> dat = {10,9,8,7,6,5,4,3,2,1,0};

  /// Listup
  /// 10 9 8 7 6 5 4 "3" 2 1 0 
  ///
  cout << "Listup" << endl;
  for_each( dat.begin(), dat.end(), [=](int i){ cout << i << " "; } );
  cout << endl;

  ///
  /// 値3 を探す
  ///
  int idx=0;
  auto result = find_if(dat.begin(), dat.end(), [&](int i){idx++;  return(i==3); } );

  /// position[8] = 3
  cout << boost::format("position[%d] = %d ") % idx % (*result)  << endl;
}
