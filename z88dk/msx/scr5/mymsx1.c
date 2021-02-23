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

void draw1(unsigned int line, unsigned int d){
  unsigned int i;
  
  for(i=0; i<line; i++){
    outp(p0, d);
  }

}



int main(){
  p0 = *((unsigned char*)0x06);
  p1 = p0+1;
  p2 = p0+2;
  p3 = p0+3;
  
 #asm
    di;
 #endasm
  //printf("peek(0x06)=0x%d",*((unsigned char*)0x06));
  // Graphic Mode 4, SCREEN 5  256x212
    /**
  outp(p1,0x06); // Data
  outp(p1,(0x80 | 0) ); // R#0
  outp(p1,0x60); // Data
  outp(p1,(0x80 | 1) ); // R#1
  **/

  // Read R#2
  //outp(p1,0x04); // Data
  //outp(p1,(0x80 | 15) ); // R#15
  //printf("%d=¥n",inp(p1));
  //return;

  #asm
    ; SCREEN5(GRAPHIC4) へ切り替える
      ld a, 5
      call 0x005f
  #endasm
     
 
  // Bank
  outp(p1,0x00); // VRAM Select
  outp(p1,(0x80 | 45) );  // R#45   

  // Pattern Name Addr
  outp(p1,0x00); // 0x0_0000
  //  //outp(p1,0x10); // 0x0_8000
  outp(p1,(0x80 | 4) ); // R#4x

  
  // vram addr
  outp(p1,0x00 ); // 0x0_0000 
  outp(p1,(0x80 | 14) ); // R#14
  outp(p1,       0x00);  // 0x*_0000 
  outp(p1,(0x40 |0x00)); // 0x*_0000 
  
  // Auto Incr
  //outp(p1,(0x00 | 0x00) ); // R#0へ書き込み、オートインクリ
  //outp(p1,(0x80 | 17) );   //
  
  // vram write
  unsigned int i;
  unsigned max = 0x6A00 / 2;
  for(i=0; i<0x6a00;){
    //for(i=0; i<0x5a00;){
    draw1(0x80, 0x81);
    i+=0x80;
    draw1(0x180, 0x12);
    i+=0x180;
  }
  
 #asm
    ei
 #endasm

  while (!get_trigger(0)) ;
  

  //printf("¥n");
  //printf("Hello   !!!!!");
}
