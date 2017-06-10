#include "game_object_factory.hpp"

using namespace mindscape;

engine::GameObject* GameObjectFactory::fabricate(
  GameObjectFactory::Options option,
  std::pair<int, int> coordinates,
  int priority){

  switch(option){
    case(GameObjectFactory::BOY):
      return fabricate_boy();
    case(GameObjectFactory::BACKGROUND):
      return fabricate_background();
    default:
      return NULL;
  }
}

engine::GameObject* GameObjectFactory::fabricate_background(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_boy(){
  engine::Game& game = engine::Game::get_instance();

  std::pair<int, int> place (416, 335);

  //Creating running right image
  engine::Image* image_idle_right = new engine::Image(
    game.renderer,
    "../assets/images/idle_right.png",
    true,
    std::make_pair(0, 0),
    2
  );
  image_idle_right->set_values(
    std::make_pair(108, 140),
    std::make_pair(108, 140),
    std::make_pair(0, 0)
  );

  //Creating running right image
  engine::Image* image_idle_left = new engine::Image(
    game.renderer,
    "../assets/images/idle_left.png",
    false,
    std::make_pair(0, 0),
    2
  );
  image_idle_left->set_values(
    std::make_pair(108, 140),
    std::make_pair(108, 140),
    std::make_pair(0, 0)
  );

  engine::GameObject* boy = new engine::Boy("boy", place, 52);
  
  engine::Hitbox* hitbox= new engine::Hitbox("hitbox", boy->position, std::make_pair(60,130), std::make_pair(50,1));
  boy->collidable = true;
  //boy->add_component(image_idle_right);
  //boy->add_component(image_idle_left);
  boy->add_component(hitbox);

  return boy;
}
