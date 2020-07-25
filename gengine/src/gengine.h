#pragma once

namespace paoengine{

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


class GameController{
  //private:
 public:
  SDL_GameController *controller;
  // public:
  GameController();
  void init();
};

class Core{
public:
  Core():gWindow(NULL), gScreenSurface(NULL),
         SCREEN_WIDTH (640), SCREEN_HEIGHT(480){}
  
  //The window we'll be rendering to
  SDL_Window* gWindow;

  //The surface contained by the window
  SDL_Surface* gScreenSurface;

  GameController gamectr;

  const int SCREEN_WIDTH;
  const int SCREEN_HEIGHT;

  
//
  bool init();
  void game();
  void close();

  void draw();
  void update();

  void key_down(SDL_Event* event);

  void mouse_motion(SDL_Event *event);
  void mouse_motion_wheel(SDL_Event *event);
  void mouse_button_down(SDL_Event *event);
  void mouse_button_up(SDL_Event *event);

  void controller_axis_motion(SDL_Event *event);
  void controller_button_down(SDL_Event *event);
  void controller_button_up(SDL_Event *event);
  void controller_device_added(SDL_Event *event);
  void controller_device_removed(SDL_Event *event);
  void controller_device_remapped(SDL_Event *event);

  SDL_Surface* loadSurface( std::string ); 
};

//The window we'll be rendering to
//extern SDL_Window* gWindow;

//The surface contained by the window
//extern SDL_Surface* gScreenSurface;

//
//extern const int SCREEN_WIDTH;
//extern const int SCREEN_HEIGHT;

  extern void leap_mortion();





}; //namespace paoengine{



extern paoengine::Core core;

