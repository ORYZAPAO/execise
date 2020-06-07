#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <string>

#include"gengine.h"

void game(){

  //Start up SDL and create window
  if( !init() ) {
    printf( "Failed to initialize!\n" );
    exit(0);
  }


  //// とりあえず、ゲームコントローラを初期化
  /// 
  GameController cc;
  
  //Main loop flag
  bool quit = false;
  
  //Event handler
  SDL_Event e;

  //While application is running
  while( !quit ){
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ){
      switch( e.type ){
      case SDL_QUIT:
        //User requests quit
        quit = true;
        break;

      //------------------------------------------------------------
      // Mouse Event
      case SDL_MOUSEMOTION:
        //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
        mouse_motion(&e);
        break;
        
      case SDL_MOUSEWHEEL:
        //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
        mouse_motion_wheel(&e);
        break;
        
      case SDL_MOUSEBUTTONDOWN:
        //mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
        mouse_button_down(&e);
        break;
        
      case SDL_MOUSEBUTTONUP:
        //mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
        mouse_button_up(&e);
        break;
        
      //------------------------------------------------------------
      // Game Controller
      case SDL_CONTROLLERAXISMOTION:	//コントローラーが動いた
        controller_axis_motion(&e);
        break;
      case SDL_CONTROLLERBUTTONDOWN:	//コントローラーのボタンが押された
        controller_button_down(&e);
        break;
      case SDL_CONTROLLERBUTTONUP:	//コントローラーのボタンが離された
        controller_button_up(&e);
        break;
      case SDL_CONTROLLERDEVICEADDED:	//コントローラーが接続された
        controller_device_added(&e);
        break;
      case SDL_CONTROLLERDEVICEREMOVED:	//コントローラーが切断された
        controller_device_removed(&e);
        break;
      case SDL_CONTROLLERDEVICEREMAPPED://コントローラーのマッピングが変わった
        controller_device_remapped(&e);
        break;

      //------------------------------------------------------------
      // Keyboard
      case SDL_KEYDOWN:
        key_down(&e);
        break;

      //------------------------------------------------------------
      // Touch 
      case SDL_FINGERDOWN:	// デバイスに指をつけた
        break;
      case SDL_FINGERUP:	// デバイスから指を離した
        break;
      case SDL_FINGERMOTION:	// デバイス上で指を動かした
        break;

      //------------------------------------------------------------
      // Audio Hot Plug
      case SDL_AUDIODEVICEADDED:	// オーディオデバイスが新たに接続された (SDL 2.0.4以降)
        break;
      case SDL_AUDIODEVICEREMOVED:	// オーディオデバイスが取り除かれた (SDL 2.0.4以降)
        break;

      //------------------------------------------------------------
      // Render 
      case SDL_RENDER_TARGETS_RESET:	// レンダラの対象がリセットされコンテキストを更新する必要がある (SDL2.0.2以降)
        break;
      case SDL_RENDER_DEVICE_RESET:	// デバイスがリセットされ全てのテクスチャを再生成する必要がある (SDL2.0.4以降)
        break;
      }

      
      //Apply the current image
      draw();

      //Update the surface
      update();    
    }
  }

  //Free resources and close SDL
  close();

}
