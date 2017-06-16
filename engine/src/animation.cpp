#include <cmath>
#include "../include/animation.hpp"
#include "../include/game.hpp"

using namespace engine;
using par = std::pair<int,int>;
using pares = std::pair<par,par>;

bool Animation::load(){

    time_of_sprite = (int) std::ceil(double(duration_of_animation) /double(total_sprites));
     std::cout << "total duration " << duration_of_animation << std::endl;
     std::cout << "total colunas  " << sprite_columns << std::endl;
     std::cout << "total linhas  " << sprite_lines << std::endl;
     std::cout << "total sprites  " << total_sprites << std::endl;
     std::cout << "tempo por sprite  " << time_of_sprite << std::endl;

    aux_time = 0;
    is_active = true;

    Image::load();
    time->init_timer();
    return true;
}

void Animation::draw(int x, int y){

      is_finished = false;
      playing_duration_of_animation += time->get_elapsed_time() - aux_time;
      aux_time = time->get_elapsed_time();

      if(playing_duration_of_animation >= duration_of_animation){
        is_finished = true;
        if(in_loop){
          playing_duration_of_animation = playing_duration_of_animation - duration_of_animation;
        } else {
          playing_duration_of_animation = duration_of_animation;
        }
      }

      actual_sprite = (playing_duration_of_animation / time_of_sprite) + first_sprite;

      int actual_line = actual_sprite / sprite_columns;
      int actual_column  = actual_sprite % sprite_columns;

      if(sprites_sizes.size() == 0){
        coordinatesOnTexture.first = actual_column * dimensionOnTexture.first;
        coordinatesOnTexture.second = actual_line * dimensionOnTexture.second;
      }else{
        coordinatesOnTexture.first = sprites_sizes[actual_column].first.first;
        coordinatesOnTexture.second = sprites_sizes[actual_column].first.second * actual_line;
        dimensionOnTexture.first = sprites_sizes[actual_column].second.first;
        dimensionOnTexture.second = sprites_sizes[actual_column].second.second;
      }

    Image::draw(x,y);
}

void Animation::set_sprites_sizes(std::vector<pares> p_sprites_sizes){
  sprites_sizes = p_sprites_sizes;
} 
