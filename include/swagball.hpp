#ifndef __SWAGBALL_H__
#define __SWAGBALL_H__

#include "stdafx.h"

enum SwagBallType {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};
class SwagBall {
private:
  sf::CircleShape shape;
  int type;

  void initShape(const sf::RenderWindow& window);

public:
  SwagBall(const sf::RenderWindow& window, int type);
  virtual ~SwagBall();

  // accessors
  const int& getType() const;
  const sf::CircleShape& getShape() const;

  // functions
  void update(const float& dt);
  void render(sf::RenderTarget& target);
};

#endif
