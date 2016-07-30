// 
// std::count_if
//
// 条件に合う値の数をカウントして返す
//

#include<iostream>
#include<boost/format.hpp>
#include<vector>

#include <algorithm>

using namespace std;

int main(){
  vector<int> dat={1,2,3,4,1,2,3,2,3,4,2,4 }; /// 2 の個数＝全部４個

  /// Listup ={ 1 2 3 4 1 2 3 2 3 4 2 4 }
  /// 
  cout << "Listup ={ ";
  for_each(dat.begin(), dat.end(), [](int x){ cout << x << " "; } );
  cout << "}" << endl << endl;           


  /// vector 中の"2" の個数 = 4
  ///
  cout << 
    boost::format("vector 中の\"2\" の個数 = %d") 
    % std::count_if(dat.begin(), dat.end(), [](int x){ return(x==2); } ) 
       << endl; 
}
