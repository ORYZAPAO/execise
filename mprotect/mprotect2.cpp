/*
 * ヒープ領域上のコードを実行する(C++にしたらうまく動かない)
 */

#include<iostream>
#include<boost/format.hpp>
#include<string.h>
#include <sys/mman.h>
#include <unistd.h>

// コピー対象のコード
extern "C" double pi(){
  //std::cout << "[alloc_execution()]" << std::endl;
  //return 0xABC;
  return 3.14159f;
}


void alloc_execution(void *pi_pt){
  std::cout << "[alloc_execution()]" << std::endl;
  
  // ページサイズ単位
  size_t pagesize = sysconf(_SC_PAGESIZE);
  // size_t  pagesize = getpagesize();

  void  *p = (void*)((long long)pi_pt & ~(pagesize - 1)); // ページ境界に揃える
  std::cout << "  Page Start: " << p  << std::endl;
  std::cout << "       Size : " << pagesize << std::endl;
  
  // mprotect() で、ヒープ領域にRead,Write,Execute属性を指定
  if( mprotect(p, pagesize*2L, PROT_READ | PROT_WRITE | PROT_EXEC) != 0 ){
    std::cout << "  mprotect() Failed" << std::endl;
  }
}

int main(){
  const size_t fsize = 4096;
  std::cout << "[main()]" << std::endl;
  
  // ヒープ領域を確保して、コード(pi()) をヒープへコピー
  char  *pi_pt = new char[fsize];
  memcpy(pi_pt, reinterpret_cast<const void*>(pi), fsize);
  //std::cout << boost::format("  pi()    Address : %x") % reinterpret_cast<const void*>(pi) << std::endl;
  //std::cout << boost::format("  pi_pt() Address : %x") % reinterpret_cast<const void*>(pi_pt) << std::endl;
  printf("  pi()    Address: %p\n", pi);  // *** boost::format() を使うと、なぜかなぜかpi_pt()の呼び出しに失敗する。****
  printf("  pi_pt() Address: %p\n", pi_pt);
  
  // ヒープ領域に実行権を与える
  alloc_execution(reinterpret_cast<void *>(pi_pt));

  // ヒープ領域のコードを実行
  std::cout << "Answer ==> pi_pt() = " <<  std::fixed  <<
    reinterpret_cast<double (*)()>(pi_pt)() << std::endl;

  std::cout << "Answer ==> pi() = " <<  std::fixed  <<
    pi() << std::endl;

  delete [] pi_pt;



}
