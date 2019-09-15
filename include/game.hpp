#ifndef __GAME_HPP__
#define __GAME_HPP__
#include "player.hpp"

class Game{
private:
  sf::VideoMode videoMode;
  sf::RenderWindow* window;
  bool endGame;
  sf::Event sfmlEvent;
  Player player;

  void initVariables();
  void initWindow();

public:
  // constructor & destructor
  Game();
  ~Game();

  // accessors
  const bool running() const;

  // modifiers

  // functions
  void pollEvents();
  void update();
  void render();
};

#endif
