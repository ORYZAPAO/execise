#pragma once

namespace paoengine{

struct Vect2{
  int x;
  int y;
  Vect2():x(0),y(0){}

  Vect2(const Vect2 &my) :           // Copy Constructor
    x(my.x), y(my.y){} 
  Vect2& operator=(const Vect2 &my){ // Copy Constructor
    x = my.x; y = my.y;
    return(*this);
  }   
};

struct Vect3{
  int x;
  int y;
  int z;
  Vect3():x(0),y(0),z(0){}

  Vect3(const Vect3 &my) :           // Copy Constructor
    x(my.x), y(my.y), z(my.z){} 
  Vect3& operator=(const Vect3 &my){ // Copy Constructor
    x=my.x; y=my.y; z=my.z;
    return(*this);
  }   
};

} //namespace paoengine{
