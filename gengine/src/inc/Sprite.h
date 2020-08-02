#pragma once

#include <string>
#include <sstream>
#include <boost/format.hpp>

#include "inc/Vect.h"
#include "inc/Rect.h"

namespace paoengine{

  class Core;
  
  class Sprite{
  private:
    SDL_Surface *spriteSurface;
    Core        *pCore;    
    Vect2        point;

  public:
    // Constructor
    Sprite() = delete;
    Sprite(Core *p): pCore(p){      
    }
    Sprite(Core *p, const std::string &img_path): pCore(p){
      load_img( img_path.c_str() );
    }
    Sprite(Core *p, const char* img_path_cstr): pCore(p){
      load_img( img_path_cstr );
    }

    // Destructor
    ~Sprite(){
      SDL_FreeSurface( spriteSurface );
    }

    // Load Image Texture
    bool load_img(const char *img_path){
      spriteSurface = IMG_Load(img_path);
      if( spriteSurface == NULL ) return false;
      return true;
    }

    // Sprite Position
    Vect2 getPoint(){ return point; }
    void  setPoint(int x, int y){
      point.x=x; point.y=y;
    }
    void setPoint(Vect2 vec){
      point = vec;
    }
    
    void draw(Rect src){
      SDL_Rect sdl_src={src.x, src.y, src.w, src.h};
      //SDL_Rect sdl_dst={dst.x, dst.y, dst.w, dst.h};
      
      SDL_BlitSurface( spriteSurface, &sdl_src, pCore->gScreenSurface, NULL );        
    }
    
    // [Debug] ostream 
    friend std::ostream& operator << (std::ostream& os, const Sprite& sp);
  };

  
  // [Debug]
  std::ostream& operator << (std::ostream& os, const Sprite &sp);

} // namespace paoengine{
