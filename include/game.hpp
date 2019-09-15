#ifndef __GAME_HPP__
#define __GAME_HPP__
#include "player.hpp"
#include "swagball.hpp"

class Game{
private:
  sf::VideoMode videoMode;
  sf::RenderWindow* window;
  bool endGame;
  sf::Event sfmlEvent;
  Player player;

  std::vector<SwagBall> swagBalls;

  float spawnTimer;
  float spawnTimerMax;
  int maxSwagBalls;

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
  void spawnSwagBalls();
  void pollEvents();
  void update();
  void render();
};

#endif
