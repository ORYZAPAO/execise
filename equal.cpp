#include<iostream>

#include<algorithm>

using namespace std;

int main(){
  vector<int> dat0 ={9,8,7,6,5,4,3,2,1,0};
  vector<int> dat1 ={9,8,7,6,5,4,3,2,1,0}; 

  vector<int> dat2 ={9,8,7,5,5,4,3,2,1,0}; ///  6!= 5
  //                       ^^^

  for_each(dat0.begin(), dat0.end(), [](int x){ cout << x << " ";} );
  cout << endl;

  /// ２つのコンテナの中身が，同一の有無を判定
  bool result;

  /// dat0 == dat1 
  result = equal(dat0.begin(), dat0.end(), dat1.begin()); /// "1"
  cout << result << endl;

  /// dat0 != dat2 
  result = equal(dat0.begin(), dat0.end(), dat2.begin()); /// "0"
  cout << result << endl;

}
