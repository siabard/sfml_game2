#include "include/game.hpp"

void Game::initVariables() {
  this->endGame = false;
  this->spawnTimer = 0.f;
  this->spawnTimerMax = 10.f;
  this->maxSwagBalls = 10;

}

void Game::initWindow() {
  this->videoMode = sf::VideoMode(800, 600);
  this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60);
}

// constructor & destructor

Game::Game() {
  this->initVariables();
  this->initWindow();
}

Game::~Game() {
  if(this->window != nullptr) {
    delete this->window;
  }
}


// accessors
const bool Game::running() const {
  return this->window->isOpen();
}

// modifiers

// functions
void Game::spawnSwagBalls() {
  // Timer
  if (this->spawnTimer < this->spawnTimerMax) {
    this->spawnTimer += 1.f;
  } else {
    // Spawn Ball
    if(this->swagBalls.size() < this->maxSwagBalls) {
      this->swagBalls.push_back(SwagBall(*this->window));

      this->spawnTimer = 0.f;
    }
  }
}

void Game::pollEvents() {
  while(this->window->pollEvent(this->sfmlEvent)) {

    switch(this->sfmlEvent.type) {
    case sf::Event::Closed:
      this->window->close();
      break;

    case sf::Event::KeyPressed:
      if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
        this->window->close();
      break;

    default:
      break;
    }

  }
}

void Game::update() {
  this->pollEvents();
  this->spawnSwagBalls();
  this->player.update(this->window);
}

void Game::render() {
  this->window->clear();

  // render stuff

  this->player.render(this->window);

  for(auto i : this->swagBalls) {
    i.render(*this->window);
  }

  this->window->display();
}
