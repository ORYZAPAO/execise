#include<iostream>
#include<boost/format.hpp>

#include<algorithm>
#include<vector>

using namespace std;

int main(){
  vector<int> dat0 = {0,1,2,3,4,5,6,7,8,9};
  bool result;

  cout << "Hello" <<endl;

  cout << "dat0 = { ";
  for_each(dat0.begin(), dat0.end(), [](int x){ cout << x << " "; });
  cout << "} " << endl;

  /// "全ての"要素が，条件に合致しているか？(all_of)
  result =  all_of(dat0.begin(), dat0.end(), [](int x){ return x<100; });
  cout << boost::format("all_of(dat0, x<100 ) =  %i" ) % result  << endl;

  result =  all_of(dat0.begin(), dat0.end(), [](int x){ return x<5; });
  cout << boost::format("all_of(dat0, x<5   ) =  %i" ) % result  << endl;
  cout << endl;


  /// "いずれかの"要素が，条件に合致しているか？(any_of)
  result =  any_of(dat0.begin(), dat0.end(), [](int x){ return x>5; });
  cout << boost::format("any_of(dat0, x>5 ) =  %i" ) % result  << endl;

  result =  any_of(dat0.begin(), dat0.end(), [](int x){ return x>9; });
  cout << boost::format("any_of(dat0, x>9 ) =  %i" ) % result  << endl;
  cout << endl;

}
