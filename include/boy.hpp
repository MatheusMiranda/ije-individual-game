//TODO discover how overwrite static attribute
//TODO remove littlegirl from namespace engine

#ifndef BOY_H
#define BOY_H

#include "../include/platform.hpp"
#include "../engine/include/game_object.hpp"
#include "../engine/include/keyboard_event.hpp"
#include "../engine/include/image.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;

namespace engine {

  class Boy : public GameObject {
    public:

      int animation_count = 0;
      int animation_count2 = 0;


      Boy(std::string p_name, std::pair<int, int> position, int p):GameObject(p_name, position, p,
      {
          {KeyboardEvent::LEFT,"MOVE_LEFT"},
          {KeyboardEvent::RIGHT,"MOVE_RIGHT"},
          {KeyboardEvent::UP,"JUMP"},
          {KeyboardEvent::DOWN,"CROUCH"},
      }){};
      ~Boy(){};

      bool load();
      void free();
      void update();
      void on_event(GameEvent);
      void on_collision(GameObject*, Hitbox*, Hitbox*);
  };

}

#endif
