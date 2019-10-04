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

  int points;

  sf::Font font;
  sf::Text guiText;
  sf::Text endGameText;

  std::vector<SwagBall> swagBalls;

  float spawnTimer;
  float spawnTimerMax;
  int maxSwagBalls;

  void initVariables();
  void initWindow();
  void initFont();
  void initText();

public:
  // constructor & destructor
  Game();
  ~Game();

  // accessors
  const bool running() const;
  const bool getEndGame() const;

  // modifiers

  // functions
  const int randBallType() const;
  void spawnSwagBalls();
  void pollEvents();
  void updatePlayer();
  void updateCollision();
  void updateGui();
  void update();
  void renderGui(sf::RenderTarget* target);
  void render();
};

#endif
