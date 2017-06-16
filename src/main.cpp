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
using par = std::pair<int,int>;
using pares = std::pair<par,par>;

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
  Animation* idle_right_animation = new Animation(game.renderer, "../assets/images/idle_right.png", false, std::make_pair(0, 0),1,1,8,0.9,true);
  idle_right_animation->set_values(std::make_pair(108, 140), std::make_pair(108, 140), std::make_pair(0, 0));
  Animation* idle_left_animation = new Animation(game.renderer, "../assets/images/idle_left.png", false, std::make_pair(0, 0),1,1,8,0.9,true);
  idle_left_animation->set_values(std::make_pair(108, 140), std::make_pair(108, 140), std::make_pair(0, 0));

  std::vector<pares> punch_sprites_sizes;
  punch_sprites_sizes.push_back(pares(par(0,0),par(139,127)));punch_sprites_sizes.push_back(pares(par(139,0),par(121,130)));
  punch_sprites_sizes.push_back(pares(par(260,0),par(171,128)));punch_sprites_sizes.push_back(pares(par(431,0),par(165,124)));
  punch_sprites_sizes.push_back(pares(par(596,0),par(124,128)));punch_sprites_sizes.push_back(pares(par(720,0),par(168,130)));

  Animation* punching_right_animation = new Animation(game.renderer,"../assets/images/punch_animation/punching_right.png",true,
    std::make_pair(0,0),1,1,6,0.9,true);
  punching_right_animation->set_values(std::make_pair(139, 127), std::make_pair(139, 127), std::make_pair(0, 0));
  punching_right_animation->set_sprites_sizes(punch_sprites_sizes);

  Animation* punching_left_animation = new Animation(game.renderer,"../assets/images/punch_animation/punching_left.png",false,
    std::make_pair(0,0),1,1,6,0.9,true);
  punching_left_animation->set_values(std::make_pair(139, 127), std::make_pair(139, 127), std::make_pair(0, 0));
  punching_left_animation->set_sprites_sizes(punch_sprites_sizes);

  boy->add_component(idle_right_animation);
  boy->add_component(idle_left_animation);
  boy->add_component(punching_right_animation);
  boy->add_component(punching_left_animation);

  //Animation* punching_right = new Animation();

  level1->add_object(boy);
  level1->add_object(background);
  level1->activate_game_object("boy");
  level1->activate_game_object("background");

  game.add_scene("first level", level1);
  game.change_scene("first level");

  game.run();
  return 0;
}
