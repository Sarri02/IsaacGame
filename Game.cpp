#include "Game.h"
#include <iostream>

void Game::InitVariable() {

    this->isaac = make_unique<Isaac>(Vector2f(444,360));
    this->ActualFloor = 0;
    this->KeyTime=this->isaac->Tear;

}

//Window
void Game::InitWindow() {

    this->window = make_unique<RenderWindow>(VideoMode(WIDHT, HEIGHT), "Main Menu", Style::Default);
    this->window->setFramerateLimit(65);

}

//Background
void Game::InitBackground() {

    this->background.setSize(Vector2f(WIDHT,HEIGHT));
    this->texture.loadFromFile("./Texture/BackgroundGame.png");
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
Game::~Game() = default;

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
        if(this->IsaacMoveIsPossible(0,-1))
            this->isaac->Move(0,-1);
    }
    //Move right
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        if(this->IsaacMoveIsPossible(1,0))
            this->isaac->Move(1,0);
    }
    //Move down
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        if(this->IsaacMoveIsPossible(0,1))
            this->isaac->Move(0,1);
    }
    //Move left
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if(this->IsaacMoveIsPossible(-1,0))
            this->isaac->Move(-1,0);
    }


    //KeyTime
    if (this->KeyTime < this->isaac->Tear)
        this->KeyTime++;

    //Shoot up
    if (Keyboard::isKeyPressed(Keyboard::Up) && KeyTime >=this->isaac->Tear) {
        this->isaac->Shoot(0,-1);
        KeyTime = 0;
    }
    //Shoot right
    if (Keyboard::isKeyPressed(Keyboard::Right) && KeyTime >=this->isaac->Tear) {
        this->isaac->Shoot(1,0);
        KeyTime = 0;
    }
    //Shoot down
    if (Keyboard::isKeyPressed(Keyboard::Down) && KeyTime >=this->isaac->Tear) {
        this->isaac->Shoot(0,1);
        KeyTime = 0;
    }
    //Shoot left
    if (Keyboard::isKeyPressed(Keyboard::Left) && KeyTime >=this->isaac->Tear) {
        this->isaac->Shoot(-1,0);
        KeyTime = 0;
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
    this->textureStats.loadFromFile("./Texture/Life.png");
    int xPosLife = 64, yPosLife = 60;
    for (int k = 0; k < this->isaac->isaac.getLife(); k++) {
        RectangleShape life;
        life.setSize(Vector2f(42, 42));
        life.setPosition(xPosLife,yPosLife);
        life.setTexture(&this->textureStats);
        window->draw(life);
        if (k == 4) {
            xPosLife = 64;
            yPosLife += 52;
        }
        else
            xPosLife += 52;
        delete &life;
    }
    //Bomb
    this->textureStats.loadFromFile("./Texture/Bomb.png");
    int xPosBomb = 420, yPosBomb = 43;
    for (int k = 0; k < this->isaac->Bombs; k++) {
        RectangleShape bomb;
        bomb.setSize(Vector2f(42, 42));
        bomb.setPosition(xPosBomb,yPosBomb);
        bomb.setTexture(&this->textureStats);
        this->window->draw(bomb);
        xPosBomb += 46;
        delete &bomb;
    }
    //Keys
    this->textureStats.loadFromFile("./Texture/Key.png");
    int xPosKeys = 420, yPosKeys = 123;
    for (int k = 0; k < this->isaac->Keys; k++) {
        RectangleShape key;
        key.setSize(Vector2f(42, 42));
        key.setPosition(xPosKeys,yPosKeys);
        key.setTexture(&this->textureStats);
        this->window->draw(key);
        xPosKeys += 46;
        delete &key;
    }
}

//Isaac
void Game::renderIsaac() {
    this->isaac->DrawIsaac(*this->window);
}
void Game::updateIsaac() {
    this->updateInput();
}

//Bullet
void Game::updateBullet() {
    for (int i = this->isaac->bullets.size() - 1; i >= 0; i--)
    {
        if(!(this->isaac->bullets[i]->updateBullet()))
        {
            delete this->isaac->bullets[i];
            this->isaac->bullets.erase(this->isaac->bullets.begin() + i);
        }
    }
}

void Game::renderBullet() {

    for (auto *bullet : this->isaac->bullets) {
        bullet->drawBullet(*(this->window));
    }
}

//Room
void Game::updateRoom() {

    //Doors
    //Porta su
    if(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorUp!= nullptr)
        if(this->CheckCollision(this->isaac->IsaacFigure,*this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorUp)){
            this->isaac->IsaacFigure.move(Vector2f(0,380));
            this->floor->ActualRoom.x--;

        }
    //Porta destra
    if(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorRight!= nullptr)
        if(this->CheckCollision(this->isaac->IsaacFigure,*this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorRight)){
            this->isaac->IsaacFigure.move(Vector2f(-820,0));
            this->floor->ActualRoom.y++;

        }
    //Porta giu
    if(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorDown!= nullptr)
        if(this->CheckCollision(this->isaac->IsaacFigure,*this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorDown)){
            this->isaac->IsaacFigure.move(Vector2f(0,-380));
            this->floor->ActualRoom.x++;

        }
    //Porta sinistra
    if(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorLeft!= nullptr)
        if(this->CheckCollision(this->isaac->IsaacFigure,*this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].DoorLeft)){
            this->isaac->IsaacFigure.move(Vector2f(820,0));
            this->floor->ActualRoom.y--;

        }
    //Obstacles
    for (int i = this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].Roocks.size() - 1; i >= 0; i--)
    {
        if(!this->CheckCollision(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].Roocks[i]->rock,this->isaac->IsaacFigure))
        {

        }
    }
}


//Actual Room
void Game::renderActualRoom() {

    this->floor->DrawActualRoom(*this->window);

}

//Update
void Game::update() {

    this->updatePollEvents();
    this->updateIsaac();
    this->updateBullet();
    this->updateRoom();
}

//Render
void Game::render() {

    this->window->clear();

    //Draw game objects
    this->renderBackground();
    this->renderMap();
    this->renderStats();
    this->renderActualRoom();
    this->renderIsaac();
    this->renderBullet();



    this->window->display();
}

bool Game::CheckCollision(RectangleShape one, RectangleShape two) {

    bool collisionX = one.getPosition().x + one.getSize().x >= two.getPosition().x &&
            two.getPosition().x + two.getSize().x >= one.getPosition().x;
    bool collisionY = one.getPosition().y + one.getSize().y >= two.getPosition().y &&
            two.getPosition().y + two.getSize().y >= one.getPosition().y;
    return collisionX && collisionY;

}

bool Game::IsaacMoveIsPossible(float dirX, float dirY) {
    Vector2f pos=this->isaac->IsaacFigure.getPosition();
    float x = pos.x;
    float y = pos.y;
    x+=(dirX*this->isaac->isaac.getSpeed());
    y+=(dirY*this->isaac->isaac.getSpeed());
    bool collisionRock = false;
    Isaac clone = *this->isaac;
    clone.IsaacFigure.move(Vector2f(dirX*this->isaac->isaac.getSpeed(),dirY*this->isaac->isaac.getSpeed()));
    for (int i = this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].Roocks.size() - 1; i >= 0; i--)
    {
        if(this->CheckCollision(this->floor->room[this->floor->ActualRoom.x][this->floor->ActualRoom.y].Roocks[i]->rock,clone.IsaacFigure))
        {
            collisionRock= true;
        }
    }
    return (x<880 && x>40 && y<615 && y>215 && !collisionRock);
}

