#include <iostream>
#include <unordered_map>
#include <string>
#include "../include/platform.hpp"
#include "../include/game_object_factory.hpp"
#include "../engine/include/game.hpp"
#include "../engine/include/audio.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/text.hpp"
#include "../engine/include/scene.hpp"
#include "../engine/include/level.hpp"
#include "../engine/include/animation.hpp"
#include "../include/globals.hpp"
#include "../include/background.hpp"

using namespace engine;

int main(int,char**){


  Game& game = Game::get_instance();
  game.set_information(globals::game_name,globals::window_size);
  game.game_init();
  ///TODO change mindscape name
  mindscape::GameObjectFactory mindscape_factory = mindscape::GameObjectFactory();

  /************************LEVEL*1**********************************************/
  Level* level1 = new Level();
  
//Create background
  std::pair<int, int> background_position (0, 0);
  Image* background_image = new Image(game.renderer, "../assets/images/background.png", true, std::make_pair(0, 0), 1);
  background_image-> set_values(std::make_pair(1024, 576), std::make_pair(384, 216), std::make_pair(0, 0));
  GameObject* background = new Background("background", background_position, 1);
  background->add_component(background_image);

  GameObject* boy = mindscape_factory.fabricate(mindscape::GameObjectFactory::BOY);
  Animation* idle_right_animation = new Animation(game.renderer, "../assets/images/idle_right.png", true, std::make_pair(0, 0),1,1,8,0.9,true);
  idle_right_animation->set_values(std::make_pair(108, 140), std::make_pair(108, 140), std::make_pair(0, 0));
  Animation* idle_left_animation = new Animation(game.renderer, "../assets/images/idle_left.png", false, std::make_pair(0, 0),1,1,8,0.9,true);
  idle_left_animation->set_values(std::make_pair(108, 140), std::make_pair(108, 140), std::make_pair(0, 0));
  boy->add_component(idle_right_animation);
  boy->add_component(idle_left_animation);
  
  level1->add_object(boy);
  level1->add_object(background);
  level1->activate_game_object("boy");
  level1->activate_game_object("background");

  game.add_scene("first level", level1);
  game.change_scene("first level");

  game.run();
  return 0;
}
