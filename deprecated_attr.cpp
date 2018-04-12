#include<iostream>
using namespace std;

class [[deprecated]] ABD{  // クラスABD は、「非推奨」のクラスである。
 public:                   //  将来的に削除される可能性を示す
  ABD(){}
};


int main(){
  ABD abd;

                        /// コンパイル時に、「非推奨」のワーニングが出る(clang++)
  cout << "OK" << endl; ///   deprecated_attr.cpp:4:9: note: 'ABD' has been explicitly marked deprecated here
                        ///   class [[deprecated]] ABD{


}
