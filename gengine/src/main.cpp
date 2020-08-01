//Using SDL, standard IO, and strings
#include <stdio.h>
#include <string>

#include"gengine.h"

class UserApp{
  virtual void init()=0;
  //  virtual void 
};

paoengine::Core core;

int main( int argc, char* args[] ){
  core.game();
  
  return 0;
}
