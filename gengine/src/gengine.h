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
extern SDL_Surface* loadSurface( std::string );
extern void close();
extern void key_down(SDL_Event* event);
