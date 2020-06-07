#pragma once

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


//The window we'll be rendering to
extern SDL_Window* gWindow;

//The surface contained by the window
extern SDL_Surface* gScreenSurface;

//
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//
extern bool init();
extern void game();
extern void close();

extern void draw();
extern void update();

extern void key_down(SDL_Event* event);

extern void mouse_motion(SDL_Event *event);
extern void mouse_motion_wheel(SDL_Event *event);
extern void mouse_button_down(SDL_Event *event);
extern void mouse_button_up(SDL_Event *event);

extern void controller_axis_motion(SDL_Event *event);
extern void controller_button_down(SDL_Event *event);
extern void controller_button_up(SDL_Event *event);
extern void controller_device_added(SDL_Event *event);
extern void controller_device_removed(SDL_Event *event);
extern void controller_device_remapped(SDL_Event *event);

extern SDL_Surface* loadSurface( std::string );


class GameController{
 private:
  SDL_GameController *controller;
 public:
  GameController();
};



