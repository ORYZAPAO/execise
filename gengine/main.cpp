//Using SDL, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>

#include"gengine.h"

class UserApp{
  virtual void init()=0;
  //  virtual void 
};


int main( int argc, char* args[] ){
  //Start up SDL and create window
  if( !init() ) {
    printf( "Failed to initialize!\n" );
    exit(0);
  }


  //Main loop flag
  bool quit = false;
  
  //Event handler
  SDL_Event e;

  //While application is running
  while( !quit ){
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ){
      //User requests quit
      if( e.type == SDL_QUIT ) {
        quit = true;
      }
      //User presses a key
      else if( e.type == SDL_KEYDOWN ){
        key_down(&e);
      }
    }
    
    //Apply the current image
    extern SDL_Surface* gCurrentSurface ;
    SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
    
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
  }
  

  //Free resources and close SDL
  close();

  return 0;
}
