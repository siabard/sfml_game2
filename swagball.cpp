#include "include/swagball.hpp"

void SwagBall::initShape(const sf::RenderWindow& window) {
  this->shape.setRadius(static_cast<float>(rand() % 10 + 10));

  sf::Color color;

  switch(this->type) {
  case SwagBallType::DEFAULT:
    color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    break;

  case SwagBallType::DAMAGING:
    color = sf::Color::Red;
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(2.f);
    break;

  case SwagBallType::HEALING:
    color = sf::Color::Green;
    this->shape.setOutlineColor(sf::Color::White);
    this->shape.setOutlineThickness(2.f);

    break;

  default:
    std::cout << "ERROR::SWAGBALL::INITSHAPE::INVALID TYPE VLAUE" << std::endl;
    break;
  }

  this->shape.setFillColor(color);
  this->shape.setPosition(rand() % window.getSize().x - this->shape.getGlobalBounds().width, rand() % window.getSize().y - this->shape.getGlobalBounds().height);
}

SwagBall::SwagBall(const sf::RenderWindow& window, int type) : type(type) {

  this->initShape(window);

}

SwagBall::~SwagBall() {}

// Accessors;
const int& SwagBall::getType() const {
  return this->type;
}

const sf::CircleShape& SwagBall::getShape() const {
  return this->shape;
}

void SwagBall::update(const float& dt) {}

void SwagBall::render(sf::RenderTarget& target) {
  target.draw(this->shape);
}
