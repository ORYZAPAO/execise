//Using SDL, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>

//Screen dimension constants
extern int SCREEN_WIDTH ;
extern int SCREEN_HEIGHT;

//Key press surfaces constants
enum KeyPressSurfaces
{
 KEY_PRESS_SURFACE_DEFAULT,
 KEY_PRESS_SURFACE_UP,
 KEY_PRESS_SURFACE_DOWN,
 KEY_PRESS_SURFACE_LEFT,
 KEY_PRESS_SURFACE_RIGHT,
 KEY_PRESS_SURFACE_TOTAL
};

//Starts up SDL and creates window
extern bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
extern SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
extern SDL_Window* gWindow;
	
//The surface contained by the window
extern SDL_Surface* gScreenSurface;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;


//
//
//

//
//
//
bool loadMedia(){
  //Loading success flag
  bool success = true;
  
  //Load default surface
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = IMG_Load("img/press.png"); /*loadSurface( "img/press.bmp" );*/
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL ){
    printf( "Failed to load default image!\n" );
    success = false;
  }
  
  //Load up surface
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "img/up.bmp" );
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
    printf( "Failed to load up image!\n" );
    success = false;
  }
  
  //Load down surface
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "img/down.bmp" );
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ){
    printf( "Failed to load down image!\n" );
    success = false;
  }
  
  //Load left surface
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "img/left.bmp" );
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ){
    printf( "Failed to load left image!\n" );
    success = false;
  }
  
  //Load right surface
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "img/right.bmp" );
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ){
    printf( "Failed to load right image!\n" );
    success = false;
  }
  
  return success;
}

void close()
{
  //Deallocate surfaces
  for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
      SDL_FreeSurface( gKeyPressSurfaces[ i ] );
      gKeyPressSurfaces[ i ] = NULL;
    }
  
  //Destroy window
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  
  //Quit SDL subsystems
  SDL_Quit();
}



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

  //Load media
  if( !loadMedia() ){
    printf( "Failed to load media!\n" );
    exit(0);
  }

  //Main loop flag
  bool quit = false;
  
  //Event handler
  SDL_Event e;
  
  //Set default current surface
  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
  
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
        //Select surfaces based on key press
        switch( e.key.keysym.sym ) {
        case SDLK_UP:
          gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
          break;
          
        case SDLK_DOWN:
          gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
          break;
          
        case SDLK_LEFT:
          gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
          break;
          
        case SDLK_RIGHT:
          gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
          break;
          
        default:
          gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
          break;
        }
      }
    }
    
    //Apply the current image
    SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
    
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
  }
  

  //Free resources and close SDL
  close();

  return 0;
}
