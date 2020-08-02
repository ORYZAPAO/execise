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
    SDL_Rect     region; 
    SDL_Rect     point; // Draw Point

    Core        *pCore;        

    
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

    //
    void  setRegion(int x, int y, int w, int h){
      region.x=x; region.y=y;   region.w=w;        region.h=h;
      /*point.x=0; point.y=0;*/ point.w =region.w; point.h=region.h;  
    }
    void  setRegion(Rect &rect){
      setRegion(rect.x, rect.y, rect.w, rect.h);
    }
    Rect  getRegion(){
      Rect rect = {region.x, region.y, region.w, region.h };
      return rect;
    }
    
    // Move
    void addx(int x){ point.x += x; }
    void addy(int y){ point.y += y; }

    // Sprite Position
    Vect2 getPoint(){
      Vect2 vect = {point.x, point.y};
      return vect;
    }
    void  setPoint(int x, int y){
      point.x=x; point.y=y; point.w=region.w; point.h= region.h;
    }
    void  setPoint(Vect2 &vec){
      point.x=vec.x; point.y=vec.y; point.w=region.w; point.h= region.h;
    }

    //
    void draw(){
      SDL_BlitSurface( spriteSurface, &region, pCore->gScreenSurface, &point);        
    }
    void draw(Vect2 &vect){
      point.x=vect.x; point.y=point.y;
      SDL_BlitSurface( spriteSurface, &region, pCore->gScreenSurface, &point);        
    }
    
    // [Debug] ostream 
    friend std::ostream& operator << (std::ostream& os, const Sprite& sp);
  };

  
  // [Debug]
  std::ostream& operator << (std::ostream& os, const Sprite &sp);

} // namespace paoengine{
