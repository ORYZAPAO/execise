/*
 * ヒープ領域上のコードを実行する
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/mman.h>
#include <unistd.h>

// コピー対象のコード
double pi(void){
  return 3.14159f;
}


void alloc_execution(void *pi_pt){
  puts("[alloc_execution()]");;

  // ページサイズ単位
  size_t pagesize = sysconf(_SC_PAGESIZE);
  // size_t  pagesize = getpagesize();

  void  *p = (void*)((long long)pi_pt & ~(pagesize - 1)); // ページ境界に揃える
  printf("  Page Start: %x\n", p);
  printf("       Size : %u\n", pagesize);
  
  // mprotect() で、ヒープ領域にRead,Write,Execute属性を指定
  if( mprotect(p, pagesize*10L, PROT_READ | PROT_WRITE | PROT_EXEC) != 0 ){
    printf("  mprotect() Failed\n");
  }
  
}

int main(){
  const size_t fsize = 4096;
  printf("[main()]\n");

  // ヒープ領域を確保して、コード(pi()) をヒープへコピー
  void  *pi_pt = malloc(fsize);
  memcpy(pi_pt, (const void *)pi, fsize);
  printf("  pi()    Address: %p\n", pi);
  printf("  pi_pt() Address: %p\n", pi_pt);

  // ヒープ領域に実行権を与える
  alloc_execution((void *)pi_pt);

  // ヒープ領域のコードを実行
  printf("Answer ==> pi_pt() = %f\n", ((double (*)(void))pi_pt)() );

  free(pi_pt);
}
