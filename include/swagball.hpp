#ifndef __SWAGBALL_H__
#define __SWAGBALL_H__

#include "stdafx.h"

class SwagBall {
private:
  sf::CircleShape shape;

  void initShape(const sf::RenderWindow& window);

public:
  SwagBall(const sf::RenderWindow& window);
  virtual ~SwagBall();

  const sf::CircleShape& getShape() const;

  // functions
  void update(const float& dt);
  void render(sf::RenderTarget& target);
};

#endif
