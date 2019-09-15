#ifndef __SWAGBALL_H__
#define __SWAGBALL_H__

#include "stdafx.h"

class SwagBall {
private:
  sf::CircleShape shape;

  void initShape();

public:
  SwagBall();
  virtual ~SwagBall();

  // functions
  void update(const float& dt);
  void render(sf::RenderTarget& target);
};

#endif
