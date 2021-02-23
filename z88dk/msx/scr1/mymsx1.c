#include<stdio.h>
#include<conio.h>
//#include<msx.h>

#include <stdlib.h>
#include <msx/gfx.h>
#include <lib3d.h>
#include <stdio.h>


  unsigned char p0 ;
  unsigned char p1 ;
  unsigned char p2 ;
  unsigned char p3 ;



#define MAX_STARS 16




int main(){

  unsigned char c;  
  p0 = *((unsigned char*)0x06);
  p1 = p0+1;
  p2 = p0+2;
  p3 = p0+3;
  
 #asm
  di;
 #endasm
  //printf("peek(0x06)=0x%d",*((unsigned char*)0x06));
  // TEXT1,   40x24
  /**
  outp(p1,0x00); // Data
  outp(p1,(0x80 | 0) ); // R#0
  outp(p1,0x70); // Data
  outp(p1,(0x80 | 1) ); // R#1
  **/
  
  // Read R#2
  //outp(p1,0x04); // Data
  //outp(p1,(0x80 | 15) ); // R#15
  //printf("%d=¥n",inp(p1));
  //return;

  #asm
  ; SCREEN4 へ切り替える
   ld a, 0
   call 0x005f
  #endasm

  // Bank
  outp(p1,0x00); // VRAM Select
  outp(p1,(0x80 | 45) );  // R#45   

  
  // Pattern Name Addr
  //outp(p1,0x60); // 0x1_8000
  //outp(p1,(0x80 | 2) ); // R#2
  
  // vram addr
  outp(p1,0x60 ); // 0x1_8000 
  outp(p1,(0x80 | 14) ); // R#14
  outp(p1,       0x00);  // 0x*_0000 
  outp(p1,(0x40 |0x00)); // 0x*_0000 
   
  // vram write
  unsigned int i;
  unsigned max = 960;
  for(i=0; i<max; i++){
    outp(p0,0x23);
  }
  
 #asm
    ei
 #endasm

  while (!get_trigger(0)) ;
  

  //printf("¥n");
  //printf("Hello   !!!!!");
}
