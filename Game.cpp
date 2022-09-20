#include "Game.h"

void Game::InitVariable() {

    this->window = nullptr;
    this->ActualFloor = 0;

}

//Window
void Game::InitWindow() {

    this->window = new RenderWindow(VideoMode(WIDHT, HEIGHT), "Main Menu", Style::Default);
    this->window->setFramerateLimit(60);

}

//Background
void Game::InitBackground() {

    this->background.setSize(Vector2f(WIDHT,HEIGHT));
    this->texture.loadFromFile("../Texture/BackgroundGame.png");
    this->background.setTexture(&(this->texture));
}

void Game::InitTexture() {

}


//Constructor and Destructor
Game::Game() {

    this->InitVariable();

    this->InitWindow();

    this->InitBackground();

    this->InitTexture();

}
Game::~Game() {

    delete this->window;

}

//Accessors
const bool Game::running() const {
    return this->window->isOpen();
}

void Game::updatePollEvents() {

    Event event;
    while (this->window->pollEvent(event))
    {
        if (event.Event::type == sf::Event::Closed)
            this->window->close();
        if (event.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::updateInput() {

    //Move up
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        this->Isaac.Move(0,-1);
    }
    //Move right
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        this->Isaac.Move(1,0);
    }
    //Move down
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        this->Isaac.Move(0,1);
    }
    //Move left
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        this->Isaac.Move(-1,0);
    }

    //Shoot up
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        this->Isaac.Shoot(0,-1);
    }
    //Shoot right
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        this->Isaac.Shoot(1,0);
    }
    //Shoot down
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        this->Isaac.Shoot(0,1);
    }
    //Shoot left
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        this->Isaac.Shoot(-1,0);
    }

}

//Map
void Game::renderMap() {
    this->floor[ActualFloor].DrawMap(*this->window);
}

//Background
void Game::renderBackground() {
    this->window->draw(this->background);
}

//Stats
void Game::renderStats() {
    //Life
    this->texture1->loadFromFile("../Texture/Life.png");
    int xPosLife = 64, yPosLife = 60;
    for (int k = 0; k < this->Isaac.isaac.Life; k++) {
        RectangleShape life;
        life.setSize(Vector2f(42, 42));
        life.setPosition(xPosLife,yPosLife);
        life.setTexture(this->texture1);
        window->draw(life);
        if (k == 4) {
            xPosLife = 64;
            yPosLife += 52;
        }
        else
            xPosLife += 52;
    }
    //Bomb
    this->texture1->loadFromFile("../Texture/Bomb.png");
    int xPosBomb = 420, yPosBomb = 43;
    for (int k = 0; k < this->Isaac.Bombs; k++) {
        RectangleShape bomb;
        bomb.setSize(Vector2f(42, 42));
        bomb.setPosition(xPosBomb,yPosBomb);
        bomb.setTexture(this->texture1);
        window->draw(bomb);
        xPosBomb += 46;
    }
    //Keys
    this->texture1->loadFromFile("../Texture/Key.png");
    int xPosKeys = 420, yPosKeys = 123;
    for (int k = 0; k < this->Isaac.Keys; k++) {
        RectangleShape key;
        key.setSize(Vector2f(42, 42));
        key.setPosition(xPosKeys,yPosKeys);
        key.setTexture(this->texture1);
        window->draw(key);
        xPosKeys += 46;
    }
}

//Isaac
void Game::renderIsaac() {
    this->Isaac.DrawIsaac(*this->window);
}
void Game::updateIsaac() {
    this->updateInput();
}

//Bullet
void Game::updateBullet() {
    for (auto *bullet : this->Isaac.bullets) {
        bullet->updateBullet();
    }
}

void Game::renderBullet() {

    for (auto *bullet : this->Isaac.bullets) {
        bullet->drawBullet(*this->window);
    }
}


//Update
void Game::update() {

    this->updatePollEvents();
    this->updateIsaac();
    this->updateBullet();
}

//Render
void Game::render() {

    this->window->clear();

    //Draw game objects
    this->renderBackground();
    this->renderMap();
    this->renderStats();
    this->renderIsaac();
    this->renderBullet();


    this->window->display();
}










