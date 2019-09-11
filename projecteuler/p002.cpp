#include<iostream>

int main(){
  int pre0=1;
  int pre1=1;
  int fib=0;
  int sum=0;
  
  std::cout << pre0 << " ";
  std::cout << pre1 << " ";
  while(fib < 4000000 ){
    if( (fib%2) == 0 ) sum+=fib;
    fib = pre0 + pre1;      
    std::cout << fib << " ";    
    pre0 = pre1;
    pre1 = fib;        
  }
  std::cout << std::endl;

  std::cout << "Result " << sum << std::endl;
  
}
