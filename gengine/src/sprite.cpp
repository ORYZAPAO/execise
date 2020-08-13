//#pragma once
#include "gengine.h"

namespace paoengine{
  std::ostream& operator << (std::ostream& os, const SpriteTable &sp){
    os << boost::format("(x(%d) ,y(%d))") % sp.pos.x % sp.pos.y;
    return os;
  }  
};

