#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>

extern bool init();

//The window we'll be rendering to
extern SDL_Window* gWindow;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Surface* gScreenSurface;

// 
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;


// 
//
//
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
  
  return success;
}
