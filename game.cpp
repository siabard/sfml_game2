#include "include/game.hpp"

void Game::initVariables() {
  this->endGame = false;
  this->spawnTimer = 0.f;
  this->spawnTimerMax = 10.f;
  this->maxSwagBalls = 10;
  this->points = 0;

}

void Game::initWindow() {
  this->videoMode = sf::VideoMode(800, 600);
  this->window = new sf::RenderWindow(this->videoMode, "Game 2", sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60);
}

void Game::initFont() {
  if(!this->font.loadFromFile("fonts/DroidSans.ttf")) {
    std::cout << "ERROR::GAME::INITFONT::CANNOT OPEN FONT DroidSans.ttf" << std::endl;
  }

}

void Game::initText() {
  this->guiText.setFont(this->font);
  this->guiText.setFillColor(sf::Color::White);
  this->guiText.setCharacterSize(24);
  this->guiText.setString("test");

  // end game text
  this->endGameText.setFont(this->font);
  this->endGameText.setFillColor(sf::Color::Red);
  this->endGameText.setCharacterSize(60);
  this->endGameText.setPosition(sf::Vector2f(20, 300));
  this->endGameText.setString("Game Over");
}

// constructor & destructor

Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFont();
  this->initText();
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

const bool Game::getEndGame() const {
  return this->endGame;
}

// modifiers

// functions
const int Game::randBallType() const {
  int type = SwagBallType::DEFAULT;

  int randValue = rand() % 100 + 1;

  if (randValue >= 60 && randValue < 80) {
    type = SwagBallType::DAMAGING;
  } else if (randValue > 80) {
    type = SwagBallType::HEALING;
  }

  return type;
}

void Game::spawnSwagBalls() {
  // Timer
  if (this->spawnTimer < this->spawnTimerMax) {
    this->spawnTimer += 1.f;
  } else {
    // Spawn Ball
    if(this->swagBalls.size() < this->maxSwagBalls) {
      this->swagBalls.push_back(SwagBall(*this->window, this->randBallType()));

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

void Game::updatePlayer() {
  this->player.update(this->window);

  if(this->player.getHp() <= 0) {
    this->endGame = true;
  }
}

void Game::updateCollision() {
  // check collision
  for(size_t i = 0; i < this->swagBalls.size(); i++) {
    if(this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds())) {

      switch(this->swagBalls[i].getType()) {
      case SwagBallType::DEFAULT:
        break;
      case SwagBallType::DAMAGING:
        this->player.takeDamage(9);
        break;
      case SwagBallType::HEALING:
        this->player.gainHealth(1);
        break;
      default:
        std::cout << " ERROR " << std::endl;
        break;
      }
      // add points
      this->points++;


      this->swagBalls.erase(this->swagBalls.begin() + i);

      break;
    }
  }

}

void Game::updateGui() {
  std::stringstream ss;

  ss << " Points: " << this->points << std::endl
     << " - Health: " << this->player.getHp() << " / " << this->player.getHpMax() << std::endl;

  this->guiText.setString(ss.str());
}

void Game::update() {
  this->pollEvents();

  if(this->endGame == false) {
    this->spawnSwagBalls();
    this->updatePlayer();
    this->updateCollision();
    this->updateGui();
  }
}

void Game::renderGui(sf::RenderTarget* target) {
  target->draw(this->guiText);
}

void Game::render() {
  this->window->clear();

  // render stuff

  this->player.render(this->window);

  for(auto i : this->swagBalls) {
    i.render(*this->window);
  }


  // render gui
  this->renderGui(this->window);

  // render end text
  if(this->endGame == true) {
    this->window->draw(this->endGameText);
  }

  this->window->display();
}
