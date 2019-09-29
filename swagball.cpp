#include "include/swagball.hpp"

void SwagBall::initShape(const sf::RenderWindow& window) {
  this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
  this->shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
  this->shape.setPosition(rand() % window.getSize().x - this->shape.getGlobalBounds().width, rand() % window.getSize().y - this->shape.getGlobalBounds().height);
}

SwagBall::SwagBall(const sf::RenderWindow& window) {
  this->initShape(window);
}

SwagBall::~SwagBall() {}

const sf::CircleShape& SwagBall::getShape() const {
  return this->shape;
}

void SwagBall::update(const float& dt) {}

void SwagBall::render(sf::RenderTarget& target) {
  target.draw(this->shape);
}
