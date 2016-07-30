#include<iostream>
#include<boost/format.hpp>
#include<vector>

#include<algorithm>

using namespace std;

int main(){
  cout << boost::format("") << endl; 
  
  vector<int> dat={1,2,3,4,5,6,7,8,9,10};

  /// Listup
  /// 1 2 3 4 5 6 7 8 9 10
  ///
  cout << "Listup" << endl;
  for_each( dat.begin(), dat.end(), [=](int i){ cout << i << " "; } );
  cout << endl;


  ///
  /// 偶数だけ取り出して、 vector<int> buf へ格納（コピー）
  /// 
  vector<int> buf( dat.size(),-1 ); /// -1 で初期化
  auto itr_buf = buf.begin();

  copy_if( dat.begin(), 
           dat.end(),  
           itr_buf, 
           [](int i){ return((i%2)==0); } ); 


  /// Listup
  /// 2 4 6 8 10 -1 -1 -1 -1 -1
  ///
  cout << "Listup" << endl;
  for_each( buf.begin(), buf.end(), [=](int i){ cout << i << " "; } );
  cout << endl;
}

