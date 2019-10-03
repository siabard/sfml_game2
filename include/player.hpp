#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "stdafx.h"

class Player {
private:
  sf::RectangleShape shape;

  float movementSpeed;
  int hp;
  int hpMax;

  void initVariables();
  void initShape();

public:
  Player(float x = 0.f, float y = 0.f);
  virtual ~Player();

  // accessors
  const sf::RectangleShape& getShape() const;
  const int& getHp() const;
  const int& getHpMax() const;

  // functions

  void takeDamage(const int damage);
  void gainHealth(const int health);

  void updateInput();
  void updateWindowBoundsCollision(const sf::RenderTarget* target);
  void update(const sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
};

#endif
