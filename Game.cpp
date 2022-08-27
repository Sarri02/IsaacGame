#include "Game.h"

//Window
void Game::InitVariable() {

    this->window = nullptr;
    this->ActualFloor = 0;

}

void Game::InitWindow() {

    this->window = new RenderWindow(VideoMode(WIDHT, HEIGHT), "Main Menu", Style::Default);

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

    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        //Close the window
        if (this->ev.type==Event::Closed)
            this->window->close();

        //Game command
        //Close the window (Escape)
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            this->window->close();
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
        if (Keyboard::isKeyPressed(Keyboard::A)){
            this->Isaac.Move(3);
        }
    }

}

void Game::update() {

    //Background of game
    this->pollEvents();

    //Draw game objects
    this->window->draw(this->background);
    this->floor[ActualFloor].DrawMap(*this->window);
    this->Isaac.DrawIsaac(*this->window);

}

void Game::render() {

    this->window->display();
    this->window->clear();

}





