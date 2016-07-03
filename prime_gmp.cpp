// prime.cpp の GMP版
//
//  #include <gmpxx.h> 
//
//  g++ prime_gmp.cpp -lgmpxx -lgmp
//
#include <iostream>
//include <boost/format.hpp>
#include<stdio.h>
#include <gmpxx.h>

using namespace std;

// Prime 素数を判定
//
bool isPrime(mpz_class &val){
  mpz_class  half_val(val >> 1); /// val / 2 
  bool ret_code = false;

  mpz_class i(half_val);
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
  for(mpz_class j(1); j<1000000; j++) {    
    result = isPrime(j);
    if( result ) cout << j << " ";
  }

}
