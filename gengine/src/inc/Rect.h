#pragma once

namespace paoengine{
  struct Rect{
    int x;
    int y;
    int w;
    int h;
    
    Rect():x(0),y(0),w(0),h(0){}
    Rect(int x_, int y_, int w_, int h_ ):x(x_),y(y_),w(w_),h(h_){
    }    
    Rect(const Rect &my) :           // Copy Constructor
      x(my.x), y(my.y), w(my.w), h(my.h){
    }    
    Rect& operator=(const Rect &my){ // Copy Constructor
      x=my.x; y=my.y; w=my.w; h=my.h;
      return(*this);
    }   
  };


  struct Size{
    int width;
    int height;

    Size():width(0),height(0){}
    Size(int width_, int height_):width(width_),height(height_){}    
    Size(const Size &my) :           // Copheight Constructor
      width(my.width), height(my.height){} 
    Size& operator=(const Size &my){ // Copy Constructor
      width = my.width; height = my.height;
      return(*this);
    }   
  };



} //namespace paoengine{
