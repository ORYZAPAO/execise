#pragma once

#include <string>
#include <sstream>
#include <boost/format.hpp>

#include "inc/Vect.h"
#include "inc/Rect.h"

namespace paoengine{

  class Core;
  
  class SpriteTable{
  private:
    SDL_Surface *spriteSurface;
    Size        size;     // Sprite XY Size
    Size        tbl_size; // Sprite Table Size
    Vect2       select;   // Select Sprite
    
    Vect2       pos;      // Draw Sprite Position
    
    Core       *pCore;        

    
  public:
    // Constructor
    SpriteTable() = delete;
    SpriteTable(Core *p):
      pCore(p), size(48,48), tbl_size(7,5), select(1,0)
    {}
    SpriteTable(Core *p, const std::string &img_path):
      pCore(p), size(48,48), tbl_size(7,5), select(1,0)
    {
      load_img( img_path.c_str() );
    }
    SpriteTable(Core *p, const char *img_path_cstr):
      pCore(p), size(48,48), tbl_size(7,5), select(1,0)
    {
      load_img( img_path_cstr );
    }

    // Destructor
    ~SpriteTable(){
      SDL_FreeSurface( spriteSurface );
    }

    // Load Image Texture
    bool load_img(const char *img_path){
      spriteSurface = IMG_Load(img_path);
      if( spriteSurface == NULL ) return false;
      return true;
    }

    //
    void  setSize(int width, int height){
      size.width = width;  size.height = height;
    }
    void  setTableSize(int width, int height){
      tbl_size.width = width;   tbl_size.height = height; 
    }
    
    // Move
    void addx(int x){ pos.x += x; }
    void addy(int y){ pos.y += y; }

    // Sprite Position
    Vect2 getPos(){
      Vect2 vect = {pos.x, pos.y};
      return vect;
    }
    void  setPos(int x, int y){
      pos.x=x; pos.y=y;
    }
    void  setPos(Vect2 &vec){
      pos = vec;
    }

    //
    void draw(){
      static SDL_Rect src;
      static SDL_Rect dst;

      src.x = size.width * select.x;
      src.y = size.height * select.y;
      src.w = size.width;
      src.h = size.height;

      dst.x = pos.x;
      dst.y = pos.y;
      dst.w = size.width;
      dst.h = size.height;
      
      SDL_SetColorKey( spriteSurface, SDL_TRUE, SDL_MapRGB( spriteSurface->format, 0,0,0) );     

      SDL_BlitSurface( spriteSurface, &src, pCore->gScreenSurface, &dst);        
    }
    void draw(const Vect2 &sel_, const Vect2 &pos_){
      static SDL_Rect src;
      static SDL_Rect dst;

      src.x = size.width  * sel_.x;
      src.y = size.height * sel_.y;
      src.w = size.width;
      src.h = size.height;

      dst.x = pos_.x;
      dst.y = pos_.y;
      dst.w = size.width;
      dst.h = size.height;
      
      SDL_SetColorKey( spriteSurface, SDL_TRUE, SDL_MapRGB( spriteSurface->format, 0,0,0) );     

      SDL_BlitSurface( spriteSurface, &src, pCore->gScreenSurface, &dst);        
    }
    
    // [Debug] ostream 
    friend std::ostream& operator << (std::ostream& os, const SpriteTable& sp);
  };

  
  // [Debug]
  std::ostream& operator << (std::ostream& os, const SpriteTable &sp);

} // namespace paoengine{
