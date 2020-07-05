#include <SDL.h>
#include <SDL_image.h>


#include <iostream>
#include <stdio.h>
#include <string>

#include"gengine.h"

//
// Constructor 
//
namespace paoengine{
  GameController::GameController():controller(NULL){
    init();
  }//

  void GameController::init(){
    for (int i = 0; i < SDL_NumJoysticks(); ++i) {
      
      if (SDL_IsGameController(i)) {
        this->controller = SDL_GameControllerOpen(i);
        if (controller) {
          break;
        }else{
          fprintf(stderr, "ゲームコントローラー%dを開けなかった: %s\n", i, SDL_GetError());
        }
      }
      
    }    
  } //

}

  
