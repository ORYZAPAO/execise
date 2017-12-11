#include<iostream>
#include<boost/format.hpp>

#include<vector>

using namespace std;

// 数えるアルゴリズム count()
template<typename C, typename P>
int count(const C&c, P pred){ // predはカウント対象の判定する関数Object

  int cnt=0;
  for(const auto&x : c) if( pred(x) ) cnt++;   
  return cnt;
}


int main(){
  vector<int> list{1,2,3,4,-1,5,6,7,-10}; // 正数７個、負数２個

  //  Data ={ 1 2 3 4 -1 5 6 7 -10 }
  //
  cout << "Data ={ ";
  for(auto x : list) cout << x << " "; 
  cout << "}" << endl; 

  // vector<int>list中の、正数を数える
  //
  // count()アルゴリズムに、関数Objectを渡して(ラムダ関数形式で)、カウントさせる
  //
  // count = 2
  //
  cout << boost::format("count = %d") % count(list,
                                              [&](int d){ return 0<d;} // lambda expression 値比較用のλ関数を定義
                                              ) << endl;
  
}
