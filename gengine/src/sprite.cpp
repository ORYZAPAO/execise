//#pragma once
#include "gengine.h"


namespace paoengine{
  std::ostream& operator << (std::ostream& os, const Sprite &sp){
    os << boost::format("(x(%d) ,y(%d))") % sp.point.x % sp.point.y;
    return os;
  }  
};

