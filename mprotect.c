#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/mman.h>
#include <unistd.h>

double pi(void){
  return 3.14159f;
}


void alloc_execution(void *pi_pt){
  puts("[alloc_execution()]\n");;
  printf("pi_pt Address: %p\n", pi_pt);
  
  size_t pagesize = sysconf(_SC_PAGESIZE);
  // size_t  pagesize = getpagesize();

  void  *p = (void*)((long long)pi_pt & ~(pagesize - 1)); // ページ境界に揃える
  printf("  Page Size : %u\n" , pagesize);
  printf("  p         : %x\n", p);
  
  if( mprotect(p, pagesize*10L, PROT_READ | PROT_WRITE | PROT_EXEC) != 0 ){
    printf("  mprotect() Failed\n");
  }
  
}

int main(){
  const size_t fsize = 4096;
  printf("[main()]\n");
  
  void  *pi_pt = malloc(fsize);
  memcpy(pi_pt, pi, fsize);
  alloc_execution((void *)pi_pt);

  printf("Answer ==> %f\n", ((double (*)(void))pi_pt)() );

  free(pi_pt);
}
