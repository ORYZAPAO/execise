#include<iostream>
#include<boost/format.hpp>
#include<string.h>
#include <sys/mman.h>
#include <unistd.h>

double pi(){
  std::cout << "[pi()]" << std::endl;
  return 3.14159f;
}


void alloc_execution(void *pi_pt){
  std::cout << "[alloc_execution()]" << std::endl;
  std::cout << boost::format("pi_pt Address: %p") % pi_pt << std::endl;
  
  //long pagesize = (int)sysconf(_SC_PAGESIZE);
  size_t  pagesize = getpagesize();

  void  *p = (void*)((long long)pi_pt & ~(pagesize - 1LL));
  std::cout << "Pagesize : " << pagesize << std::endl;
  std::cout << "p        : " << p  << std::endl;
  
  mprotect(p, pagesize*50L, PROT_READ|PROT_WRITE|PROT_EXEC);
  
  //  std::cout << boost::format("%f") %
  //  reinterpret_cast<double (*)()>(pi_pt)() << std::endl;
}

int main(){
  std::cout << "[main()]" << std::endl;

  void *pi_pt = new char[1000];
  memcpy(pi_pt, reinterpret_cast<const void*>(&pi), 1000);

  alloc_execution(&pi_pt);

  delete &pi_pt;
}
