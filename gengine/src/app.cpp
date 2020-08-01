#include <stdio.h>
#include <string>

#include"gengine.h"

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

extern void my_init();
extern void my_draw();
extern void my_close();
extern void my_key_down(SDL_Event* event);


extern bool loadMedia();

//
//
//
void my_init(){
  //Load media
  if( !loadMedia() ){
    printf( "Failed to load media!\n" );
    exit(0);
  }
  //Set default current surface
  gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DEFAULT ];
}

//
//
//
void my_close()
{
  //Deallocate surfaces
  for( int i = 0; i < paoengine::KEY_PRESS_SURFACE_TOTAL; ++i )
    {
      SDL_FreeSurface( gKeyPressSurfaces[ i ] );
      gKeyPressSurfaces[ i ] = NULL;
    }  
}

//
//
//
void my_draw(){
  //Apply the current image
  SDL_BlitSurface( gCurrentSurface, NULL, core.gScreenSurface, NULL );
}

//
//
//
void my_key_down(SDL_Event* event){
  //Select surfaces based on key press
  switch( event->key.keysym.sym ) {
  case SDLK_UP:
    gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_UP ];
    break;
    
  case SDLK_DOWN:
    gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DOWN ];
    break;
    
  case SDLK_LEFT:
    gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_LEFT ];
    break;
    
  case SDLK_RIGHT:
    gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_RIGHT ];
    break;
    
  default:
    gCurrentSurface = gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DEFAULT ];
    break;
  }

}



//============================================================
//
//
bool loadMedia(){
  //Loading success flag
  bool success = true;
  
  //Load default surface
  gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DEFAULT ] = IMG_Load("img/press.png"); /*loadSurface( "img/press.bmp" );*/
  if( gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DEFAULT ] == NULL ){
    printf( "Failed to load default image!\n" );
    success = false;
  }
  
  //Load up surface
  gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_UP ] = core.loadSurface( "img/up.bmp" );
  if( gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_UP ] == NULL ) {
    printf( "Failed to load up image!\n" );
    success = false;
  }
  
  //Load down surface
  gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DOWN ] = core.loadSurface( "img/down.bmp" );
  if( gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_DOWN ] == NULL ){
    printf( "Failed to load down image!\n" );
    success = false;
  }
  
  //Load left surface
  gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_LEFT ] = core.loadSurface( "img/left.bmp" );
  if( gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_LEFT ] == NULL ){
    printf( "Failed to load left image!\n" );
    success = false;
  }
  
  //Load right surface
  gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_RIGHT ] = core.loadSurface( "img/right.bmp" );
  if( gKeyPressSurfaces[ paoengine::KEY_PRESS_SURFACE_RIGHT ] == NULL ){
    printf( "Failed to load right image!\n" );
    success = false;
  }
  
  return success;
}
