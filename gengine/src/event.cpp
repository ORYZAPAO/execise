#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>

#include"gengine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// 
//
//
extern bool my_init();
bool init(){
  //Initialization flag
  bool success = true;
  
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }else{
    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL ){
      printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
      success = false;
    }else{
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  
  if( success ) my_init();

  return success;
}



//
//
//
extern void  my_close();
void close()
{
  //Deallocate surfaces
  my_close();
  
  //Destroy window
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  
  //Quit SDL subsystems
  SDL_Quit();
}

//
//
//
extern void my_draw();
void draw(){
  my_draw();
}


//
//
//
extern void  my_key_down(SDL_Event* event);
void key_down(SDL_Event* event){
  my_key_down(event);
}
