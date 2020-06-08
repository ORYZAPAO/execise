#include <SDL.h>
#include <SDL_image.h>


#include <iostream>
#include <stdio.h>
#include <string>

#include"gengine.h"

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;


//The window we'll be rendering to
//SDL_Window* gWindow = NULL;

//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

// 
//
//
extern bool my_init();
bool paoengine::Core::init(){
  //Initialization flag
  bool success = true;
  
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) < 0 ) {
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


  SDL_GameController *controller = NULL;
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (SDL_IsGameController(i)) {
      controller = SDL_GameControllerOpen(i);
      if (controller) {
        break;
      }else{
        fprintf(stderr, "ゲームコントローラー%dを開けなかった: %s\n", i, SDL_GetError());
        success = false;
      }
    }
  }
  
  
  if( success ) my_init();

  return success;
}


//
//
//
extern void  my_close();
void paoengine::Core::close()
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
void paoengine::Core::draw(){
  my_draw();
}

//
//
//
void paoengine::Core::update(){
  //Update the surface
  SDL_UpdateWindowSurface( gWindow );
}


//
//
//
extern void my_key_down(SDL_Event* event);
void paoengine::Core::key_down(SDL_Event* event){
  std::cout << "Key Down" << std::endl;
  my_key_down(event);
}


//
//
//
extern void my_mouse_motion(SDL_Event *event);
void paoengine::Core::mouse_motion(SDL_Event *event){
}


//
//
//
extern void my_mouse_wheel(SDL_Event *event);
void paoengine::Core::mouse_motion_wheel(SDL_Event *event){
}

//
//
//
extern void my_mouse_button_down(SDL_Event *event);
void paoengine::Core::mouse_button_down(SDL_Event *event){
}


//
//
//
extern void my_mouse_button_up(SDL_Event *event);
void paoengine::Core::mouse_button_up(SDL_Event *event){
}


//コントローラーが動いた
extern void my_controller_axis_motion(SDL_Event *event);
void paoengine::Core::controller_axis_motion(SDL_Event *event){
}

//コントローラーのボタンが押された
extern void my_controller_button_down(SDL_Event *event);
void paoengine::Core::controller_button_down(SDL_Event *event){
  std::cout << "Ctrl Button OFF" << std::endl;
}

//コントローラーのボタンが離された
extern void my_controller_button_up(SDL_Event *event);
void paoengine::Core::controller_button_up(SDL_Event *event){
  std::cout << "Ctrl Button On" << std::endl;
}

//コントローラーが接続された
extern void my_controller_device_added(SDL_Event *event);
void paoengine::Core::controller_device_added(SDL_Event *event){
  std::cout << "Connect" << std::endl;
}

//コントローラーが切断された
extern void my_controller_device_removed(SDL_Event *event);
void paoengine::Core::controller_device_removed(SDL_Event *event){
  std::cout << "DisConnect" << std::endl;
}

//コントローラーのマッピングが変わった
extern void my_controller_device_remapped(SDL_Event *event);
void paoengine::Core::controller_device_remapped(SDL_Event *event){
}











