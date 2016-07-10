#include <iostream>
//include <boost/format.hpp>
#include<stdio.h>

using namespace std;

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
  bool result;

  printf("start\n");
  for(int j=1; j<1000000; j++) {    
    result = isPrime(j);
    if( result ) printf("%d ",j);
  }

}
