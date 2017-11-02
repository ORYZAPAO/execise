#include<iostream>
#include<boost/format.hpp>
using namespace std;

int main(){
  int         Dat     = 1;
  const int   cDat    = 100;
  int  const *cpDat   = &Dat;
  int *const  ccpDat  = &Dat;

  //  *cpDat=200;   // Error
  cpDat = &Dat;
  //　　ccpDat = &Dat; // Error
  *ccpDat = 999;

  cout << boost::format("Dat=%d") % Dat  << endl;
  cout << boost::format("cDat=%d") % cDat  << endl;
  cout << boost::format("pDat=%d") % *cpDat  << endl;
  cout << boost::format("ccpDat=%d") % *ccpDat  << endl;
}
