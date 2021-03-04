#include<stdio.h>
#include<conio.h>
#include<msx.h>

#include <stdlib.h>
#include <msx/gfx.h>
#include <lib3d.h>
#include <stdio.h>

//============================================================
//== Initialize, VRAM Access
//============================================================
unsigned char p0; // I/O Address ...VDP Port #0
unsigned char p1; //             ...VDP Port #1
unsigned char p2; //             ...VDP Port #2
unsigned char p3; //             ...VDP Port #3

//
//
void get_vdp_port(){
  // Get VDP I/O Port Address(for VDP)
  p0 = *((unsigned char*)0x06); // VDP Port #0
  p1 = p0+1;                    // VDP Port #1
  p2 = p0+2;                    // VDP Port #2
  p3 = p0+3;                    // VDP Port #3
}


#define  MAP_WIDTH 32
#define  MAP_HEIGHT 24


// set_mode 5
//
void set_vdpmode(int mode){
#asm
  ld    hl, 2
  add   hl, sp
  ld    d,(hl)

  ; SCREEN5(GRAPHIC4) へ切り替える
  ld    a, d
  call 0x005f
#endasm
}


// Change VRAM 
//
// 拡張RAM --> VRAM へ切り替え
void select_vram(){
  //outp(p1,0x00); // VRAM Select
  //outp(p1,(0x80 | 45) );  // R#45   
  set_vdp_reg(45,0x00);
}


// for Writing VRAM
//
void preset_vram_addr(unsigned int vaddr){
  // vram addr
  //set_vdp_reg(14, ((vaddr >> 14) & 0x07) );
  outp(p1,        (vaddr >> 14) & 0x7);     // bit 16-14
  outp(p1,(0x80 | 14) ); // R#14
  outp(p1,        (vaddr & 0xFF)) ;         // bit 7-0
  outp(p1,(0x40 | ((vaddr >> 8) & 0x3F)) ); // bit 13-8 
}

//============================================================
//== VRAM 
//============================================================
unsigned int SPRITE_PTRN_NAME_VADDR = 0x0000;

// Pattern Name Table (VRAM Map Address)
//
void preset_pat_name_addr(unsigned int vpat_name_addr){
  SPRITE_PTRN_NAME_VADDR = vpat_name_addr;
  // Pattern Name Addr
  //outp(p1,((vpat_name_addr>>11) & 0x3F));
  //outp(p1,(0x80 | 4) ); // R#4x  
  set_vdp_reg(4, ((vpat_name_addr>>11) & 0x3F) );
}


//============================================================
//== Sprite 
//============================================================
unsigned int SPRITE_COLOR_VADDR  = 0x7400;
unsigned int SPRITE_ATTR_VADDR   = 0x1B00;
unsigned int SPRITE_PATGEN_VADDR = 0x0000;

// Sprite Pattern Generator Table
//
void preset_sprite_patgen_addr(unsigned int vspr_ptrn_addr){
  SPRITE_PATGEN_VADDR = vspr_ptrn_addr;
  set_vdp_reg(6,  (vspr_ptrn_addr>>11) & 0x3F); // bit 16-15
}


// Regist Sprite 
//
// id  0 - 255
// pat[8]
void create_sprite8x8(int id, unsigned char *pat){
  preset_vram_addr(SPRITE_PATGEN_VADDR + 8*id);
  for(int i=0; i<8; i++) outp(p0, *pat++);    
}


// Sprite Attribute Table
//
void preset_sprite_attr_addr(unsigned int vspr_attr_addr){
  SPRITE_ATTR_VADDR   = vspr_attr_addr;
  SPRITE_COLOR_VADDR = vspr_attr_addr - 0x200;

  set_vdp_reg(5,  (vspr_attr_addr>> 7) & 0xFF); // bit 14-7
  set_vdp_reg(11, (vspr_attr_addr>>15) & 0x03); // bit 16-15
}


// Sprite Color Table
//
// id  0 - 255
// table[8]
void preset_sprite_color(unsigned char id, unsigned char *table){
  preset_vram_addr(SPRITE_COLOR_VADDR + 16*id);
  for(int i=0; i<16; i++) outp(p0, *table++);
}


//
// spr 0 - 31
// id  0 - 255
void draw_sprite(unsigned char spr,  unsigned char id, unsigned char x, unsigned char y){
  preset_vram_addr(SPRITE_ATTR_VADDR + 4*spr);
  outp(p0, y);  
  outp(p0, x);    
  outp(p0, id);    
  outp(p0, 0x08);    
}


//============================================================
//============================================================
void draw1(unsigned int line, unsigned int d){
  for(int i=0; i<line; i++){
    outp(p0, d);
  }

}

int main(){
  get_vdp_port();  

#asm
    di;
#endasm

  // Screen2
  set_vdpmode(2);   

  // set screen
  //set_color(15, 1, 1);
  //set_mangled_mode();  

 #asm
    ei
 #endasm

  // ------------------------------------------------------------
  // スプライト定義
  // ------------------------------------------------------------
  unsigned char  pat0[8] = {
    0b01000010,
    0b01000010,
    0b01111110,
    0b01011010,
    0b01111110,
    0b01011010,
    0b01000010,
    0b11111111}; 
  
  unsigned char  pat1[8] = {
    0b00000000,
    0b00000000,
    0b01111100,
    0b01000100,
    0b01000100,
    0b01111100,
    0b00000000,
    0b00000000}; 

  preset_sprite_patgen_addr(0x0000);
  create_sprite8x8(0, pat0);
  create_sprite8x8(1, pat1);

  unsigned char color[16] ={
    0x02, 0x03,
    0x04, 0x05,
    0x06, 0x07,
    0x08, 0x09,
    0x0A, 0x0B,
    0x0C, 0x0D,
    0x02, 0x08,
    0x02, 0x09
  };
  preset_sprite_color(0, color);  

  preset_sprite_attr_addr(0x1B00);


  // ------------------------------------------------------------
  // パターンネームテーブルの定義
  // ------------------------------------------------------------
  unsigned char map[MAP_WIDTH * MAP_HEIGHT];
  unsigned char water1[] = {0xAA, 0x55, 0xAA, 0x55, 0xFF, 0x55, 0x00, 0};
  unsigned char black1[] = {0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0};
  // set char shapes and colors
  for(int i=0; i<(MAP_WIDTH * MAP_HEIGHT); i++)  map[i] = 'A';
  map[0] = 'B';
  set_char('A', water1, NULL, 0x32, place_all);
  set_char('B', black1, NULL, 0x54, place_all);

  
  int px=160, py=160;
  int x=0,y=0;
  int d;
  while (!get_trigger(0)) {
    vwrite(map, 0x1800, (MAP_WIDTH * MAP_HEIGHT));    
    //vwrite(map, 0, (MAP_WIDTH * MAP_HEIGHT));    
    
    d = get_stick(0);
    switch (d) {
    case 0: x = 0;  y = 0;   break;
    case 1: x = 0;  y = -1; break;
    case 2: x = 1;  y = -1; break;
    case 3: x = 1;  y = 0;   break;
    case 4: x = 1;  y = 1;  break;
    case 5: x = 0;  y = 1;  break;
    case 6: x = -1; y = 1;  break;
    case 7: x = -1; y = 0;   break;
    case 8: x = -1; y = -1; break;
    default : x=0; y=0;       break;
    }

    px += x;
    py += y;
    draw_sprite(1, 1, px, py );
    draw_sprite(0, 0, 160, 160 );
    x=0; y=0;
    
  }

    //  set_vdp_reg(10,0xFF);

  //printf("¥n");
  //printf("Hello   !!!!!");
}
