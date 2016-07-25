#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

int main(){
  vector<int> dat(10);

  int n=1;
  //
  // 出力の範囲へ関数の結果を書き込む。
  // 
  std::generate(dat.begin(), dat.end(), [&n](){ auto ret=n; n*=2; return ret; }); // 1 2 4 8 16 32 64 128 256 512

  std::for_each(dat.begin(), dat.end(), [](int x){ cout << x << " ";});
  cout << endl;

}
