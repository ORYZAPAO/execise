#include <iostream>
//include <boost/format.hpp>
#include<stdio.h>
#include<array>
#include<memory>

///#include "make_unique.hpp" /// for c++11

using namespace std;


//const int MAX_INT = 1000000;
const int MAX_INT = 300000;

// Prime 素数を判定
//
bool isPrime(int val){
  int  half_val = (val >> 1); /// val / 2 
  bool ret_code = false;

  int i;
  for(i=half_val; i>1; i--){
    if( (val % i) == 0 ) break;
  }
  if(i == 1) ret_code=true;
  else       ret_code=false;

  return ret_code;
}


//
//
int main(){
  array<bool,MAX_INT> result;   // 素数判定結果を格納  

  // 素数判定
  printf("start\n");
  for(int j=1; j<MAX_INT; j++) {    
    result[j]  = isPrime(j);
  }
 
  // 結果を表示
  for(int j=1; j<MAX_INT; j++) {    
    if( result[j] ) printf("%d ",j);
  }


}
