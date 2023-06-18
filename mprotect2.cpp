#include<iostream>
#include<boost/format.hpp>
#include<string.h>
#include <sys/mman.h>
#include <unistd.h>

double pi(){
  return 3.14159f;
}

void alloc_execution(void *pi_pt){
  std::cout << "[alloc_execution()]" << std::endl;
  std::cout << boost::format("pi_pt Address: %p") % pi_pt << std::endl;
  
  size_t pagesize = sysconf(_SC_PAGESIZE);
  // size_t  pagesize = getpagesize();

  void  *p = (void*)((long long)pi_pt & ~(pagesize - 1)); // ページ境界に揃える
  std::cout << "  Page Size : " << pagesize << std::endl;
  std::cout << "  p         : " << p  << std::endl;
  
  if( mprotect(p, pagesize*10L, PROT_READ | PROT_WRITE | PROT_EXEC) != 0 ){
    std::cout << "  mprotect() Failed" << std::endl;
  }
  
}

int main(){
  const size_t fsize = 4096;
  std::cout << "[main()]" << std::endl;
  
  char  *pi_pt = new char[fsize];
  memcpy(pi_pt, reinterpret_cast<const void*>(pi), fsize);
  //memcpy(pi_pt, pi, fsize);
  alloc_execution((void *)pi_pt);

  //std::cout << "Anser ==> " << 
  //   reinterpret_cast<double (*)()>(pi_pt)() << std::endl;
  printf("Answer ==> %f\n", ((double (*)(void))pi_pt)() );
  printf("Answer ==> %p %p\n", &pi, pi_pt );

  delete [] pi_pt;
}
