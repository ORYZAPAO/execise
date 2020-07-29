//#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <sstream>
#include<boost/format.hpp>
#include "gengine.h"

namespace paoengine{

  class Sprite{
  private:
    SDL_Surface *spriteSurface;
    Vect2        point;

  public:
    // Constructor
    Sprite(){
    }
    Sprite(const std::string &img_path){
      load_img( img_path.c_str() );
    }
    Sprite(const char* img_path_cstr){
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
    
    void draw(Rect src, Rect dst){
      SDL_Rect sdl_src={src.x, src.y, src.w, src.h};
      SDL_Rect sdl_dst={dst.x, dst.y, dst.w, dst.h};
      
      //SDL_BlitSurface( gCurrentSurface, NULL, core.gScreenSurface, NULL );        
    }
    
    // [Debug] ostream 
    friend std::ostream& operator << (std::ostream& os, const Sprite& sp);
  };

  std::ostream& operator << (std::ostream& os, const Sprite& sp){
    os << boost::format("(x(%d) ,y(%d))") % sp.point.x % sp.point.y;
    return os;
  }
  

}
