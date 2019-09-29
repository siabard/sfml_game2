#include "include/stdafx.h"
#include "include/player.hpp"

void Player::initVariables() {
  this->movementSpeed = 5.f;
  this->hpMax = 10;
  this->hp = this->hpMax;
}

void Player::initShape() {
  this->shape.setFillColor(sf::Color::Green);
  this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y) {
  this->shape.setPosition(x, y);

  this->initVariables();
  this->initShape();

}

Player::~Player() {}

const sf::RectangleShape& Player::getShape() const {
  return this->shape;
}

void Player::updateInput() {
  // Left
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->shape.move( -this->movementSpeed, 0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->shape.move( this->movementSpeed, 0);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->shape.move( 0, -this->movementSpeed);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      this->shape.move( 0, this->movementSpeed);
  }
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target) {
  sf::FloatRect playerBounds = this->shape.getGlobalBounds();

  if(playerBounds.left <= 0.f) {
    // left
    this->shape.setPosition(0.f, playerBounds.top);
    playerBounds = this->shape.getGlobalBounds();

  }

  if(playerBounds.left + playerBounds.width >= target->getSize().x) {
    // right
    this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    playerBounds = this->shape.getGlobalBounds();

  }

  if(playerBounds.top <= 0.f) {
    // top
    this->shape.setPosition(playerBounds.left, 0.f);
    playerBounds = this->shape.getGlobalBounds();

  }

  if(playerBounds.top + playerBounds.height >= target->getSize().y) {
    // bottom
    this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
    playerBounds = this->shape.getGlobalBounds();

  }

}

void Player::update(const sf::RenderTarget* target) {
  // keyboard input
  this->updateInput();

  // window bounds collision
  this->updateWindowBoundsCollision(target);


}

void Player::render(sf::RenderTarget* target) {
  target->draw(this->shape);
}
