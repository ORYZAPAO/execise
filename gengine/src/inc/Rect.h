#pragma once

//namespace paoengine{

struct Rect{
  int x;
  int y;
  int w;
  int h;
  Rect():x(0),y(0),w(0),h(0){}

  Rect(const Rect &my) :           // Copy Constructor
    x(my.x), y(my.y), w(my.w), h(my.h){} 
  Rect& operator=(const Rect &my){ // Copy Constructor
    x=my.x; y=my.y; w=my.w; h=my.h;
    return(*this);
  }   
};

//} //namespace paoengine{
