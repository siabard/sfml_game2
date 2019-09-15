#include "include/stdafx.h"
#include "include/game.hpp"

int main(){
  // init random seed
  srand(static_cast<unsigned>(time(0)));

  // init game object
  Game game;

  // Game loop
  while(game.running()) {
    game.update();
    game.render();
  }

  return 0;
}
