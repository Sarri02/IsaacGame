#include "Game.h"

//Window
void Game::InitVariable() {

    this->window = nullptr;
    this->ActualFloor = 0;

}

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

//Constructor and Destructor
Game::Game() {

    this->InitVariable();

    this->InitWindow();

    this->InitBackground();

}
Game::~Game() {

    delete this->window;

}

//Accessors
const bool Game::running() const {
    return this->window->isOpen();
}

//Function public
void Game::pollEvents() {

    while (this->window->pollEvent(event)) {

        //Close the window
        if (this->event.type == Event::Closed)
            this->window->close();

        //Game command
        //Close the window (Escape)
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            this->window->close();
        }
    }
    //Move up
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        this->Isaac.Move(0);
    }
    //Move right
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        this->Isaac.Move(1);
    }
    //Move down
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        this->Isaac.Move(2);
    }
    //Move left
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        this->Isaac.Move(3);
    }
    //Shoot up
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        this->Isaac.Shoot(0, *this->window);
    }
    //Shoot right
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        this->Isaac.Shoot(1, *this->window);
    }
    //Shoot down
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        this->Isaac.Shoot(2, *this->window);
    }
    //Shoot left
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        this->Isaac.Shoot(3, *this->window);
    }
}


void Game::update() {

    //Background of game
    this->pollEvents();


}

void Game::render() {

    //Draw game objects
    this->window->draw(this->background);
    this->floor[ActualFloor].DrawMap(*this->window);
    this->Isaac.DrawIsaac(*this->window);
    this->Isaac.DrawConsumables(*this->window);

    this->window->display();
    this->window->clear();

}





