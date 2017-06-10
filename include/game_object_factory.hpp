#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include "../engine/include/game.hpp"
#include "../engine/include/game_object.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "boy.hpp"
#include "background.hpp"
#include <iostream>
#include <string>

namespace mindscape {
  class GameObjectFactory {
    public:
      typedef enum {
        BOY, BACKGROUND
      } Options;

      GameObjectFactory(){};
      ~GameObjectFactory(){};

      // FIXME: hitbox still being a SDL_Rect, it will not be included here,
      // you need to setup it hardcoded
      engine::GameObject* fabricate(
        Options option,
        std::pair<int, int> coordinates = std::make_pair(0,0),
        int priority = 0
      );
      
    private:
      engine::GameObject* fabricate_boy();
      engine::GameObject* fabricate_background();
  };
}

#endif
