#include "Game.h"
#include <iostream>



void Game::InitVariable() {

    //Isaac
    isaac = make_unique<Isaac>(Vector2f(444,400));
    ActualFloor = 0;
    KeyTime=isaac->Tear;

    //Missions
    textureM[0].loadFromFile("./Texture/Mission0.png");
    missions[0] = make_unique<AchievementsDisplay>(isaac.get(),&textureM[0],2);
    textureM[1].loadFromFile("./Texture/Mission1.png");
    missions[1] = make_unique<AchievementsDisplay>(isaac.get(),&textureM[1],5);
    textureM[2].loadFromFile("./Texture/Mission2.png");
    missions[2] = make_unique<AchievementsDisplay>(isaac.get(),&textureM[2],2);
}

//Window
void Game::InitWindow() {

    window = make_unique<RenderWindow>(VideoMode(WIDHT, HEIGHT), "Main Menu", Style::Default);
    window->setFramerateLimit(65);

}

//Background
void Game::InitBackground() {

    background.setSize(Vector2f(WIDHT,HEIGHT));
    texture.loadFromFile("./Texture/BackgroundGame.png");
    background.setTexture(&(texture));
}

void Game::InitTexture() {

}



//Constructor and Destructor
Game::Game() {

    InitVariable();

    InitWindow();

    InitBackground();

    InitTexture();

}
Game::~Game() = default;

//Accessors
const bool Game::running() const {
    return window->isOpen();
}

void Game::updatePollEvents() {

    Event event;
    while (window->pollEvent(event))
    {
        if (event.Event::type == sf::Event::Closed)
            window->close();
        if (event.Event::key.code == sf::Keyboard::Escape)
            window->close();
    }
    //Bombs
    if (event.Event::type == Event::KeyReleased && event.Event::key.code == sf::Keyboard::E){
        if(isaac->Bombs>0)
            isaac->dropBomb();
        isaac->Bombs--;

    }
}

void Game::updateInput() {
    //Move up
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if(IsaacMoveIsPossible(0,-1))
            isaac->Move(0,-1);
    }
    //Move right
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        if(IsaacMoveIsPossible(1,0))
            isaac->Move(1,0);
    }
    //Move down
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        if(IsaacMoveIsPossible(0,1))
            isaac->Move(0,1);
    }
    //Move left
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if(IsaacMoveIsPossible(-1,0))
            isaac->Move(-1,0);
    }


    //KeyTime
    if (KeyTime < isaac->Tear)
        KeyTime++;

    //Shoot up
    if (Keyboard::isKeyPressed(Keyboard::Up) && KeyTime >=isaac->Tear) {
        isaac->Shoot(0,-1);
        KeyTime = 0;
        isaac->addShoot(missions[1].get());

    }
    //Shoot right
    if (Keyboard::isKeyPressed(Keyboard::Right) && KeyTime >=isaac->Tear) {
        isaac->Shoot(1,0);
        KeyTime = 0;
        isaac->addShoot(missions[1].get());

    }
    //Shoot down
    if (Keyboard::isKeyPressed(Keyboard::Down) && KeyTime >=isaac->Tear) {
        isaac->Shoot(0,1);
        KeyTime = 0;
        isaac->addShoot(missions[1].get());

    }
    //Shoot left
    if (Keyboard::isKeyPressed(Keyboard::Left) && KeyTime >=isaac->Tear) {
        isaac->Shoot(-1,0);
        KeyTime = 0;
        isaac->addShoot(missions[1].get());

    }

}

//Map
void Game::renderMap() {
    floor[ActualFloor].DrawMap(*window);
}

//Background
void Game::renderBackground() {
    window->draw(background);
}

//Stats
void Game::renderStats() {
    //Life
    textureStats.loadFromFile("./Texture/Life.png");
    int xPosLife = 64, yPosLife = 60;
    RectangleShape life;
    for (int k = 0; k < isaac->getLife(); k++) {
        life.setSize(Vector2f(42, 42));
        life.setPosition(xPosLife,yPosLife);
        life.setTexture(&textureStats);
        window->draw(life);
        if (k == 4) {
            xPosLife = 64;
            yPosLife += 52;
        }
        else
            xPosLife += 52;
    }
    //Bomb
    textureStats.loadFromFile("./Texture/Bomb.png");
    int xPosBomb = 420, yPosBomb = 43;
    RectangleShape bomb;
    for (int k = 0; k < isaac->Bombs; k++) {
        bomb.setSize(Vector2f(42, 42));
        bomb.setPosition(xPosBomb,yPosBomb);
        bomb.setTexture(&textureStats);
        window->draw(bomb);
        xPosBomb += 46;
    }
    //Keys
    textureStats.loadFromFile("./Texture/Key.png");
    int xPosKeys = 420, yPosKeys = 123;
    RectangleShape key;
    for (int k = 0; k < isaac->Keys; k++) {
        key.setSize(Vector2f(42, 42));
        key.setPosition(xPosKeys,yPosKeys);
        key.setTexture(&textureStats);
        window->draw(key);
        xPosKeys += 46;
    }
}

//Isaac
void Game::renderIsaac() {
    isaac->Draw(*window);
    //Missions
    if(missions[0]->isDrawable()){
        missions[0]->drawAchievements(*(window));
    }
    if(missions[1]->isDrawable()){
        missions[1]->drawAchievements(*(window));
    }
    if(missions[2]->isDrawable()){
        missions[2]->drawAchievements(*(window));
    }
}
void Game::updateIsaac() {

    updateInput();
    if(isaac->getLife()<=0)
        window->close();
}

//Bullet
void Game::updateBullet() {
    for (int i = isaac->bullets.size() - 1; i >= 0; i--)
    {
        if(!(isaac->bullets[i]->updateBullet()))
        {
            delete isaac->bullets[i];
            isaac->bullets.erase(isaac->bullets.begin() + i);
        }
    }
}

void Game::renderBullet() {

    for (auto *bullet : isaac->bullets) {
        bullet->drawBullet(*(window));
    }
}

//Bombs
void Game::updateBomb() {
    for (int i = isaac->bombs.size() - 1; i >= 0; i--)
    {
        //explosion

        if(!(isaac->bombs[i]->updateBomb()))
        {
            //Explosion
            //Rock
            for (int j = floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks.size() - 1; j >= 0; j--){
                if(CheckCollision(isaac->bombs[i]->explosion,floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks[j]->rock)){
                    //Signed Rock
                    if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks[j]->isSigned){
                        switch (rand()%3) {
                            case 0:
                                isaac->setLife(isaac->getLife()+1);
                                break;
                            case 1:
                                isaac->Bombs+=2;
                                break;
                            case 2:
                                isaac->Keys+=2;
                                break;
                        }
                    }
                    delete floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks[j];
                    floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks.erase(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks.begin() + j);
                }
            }
            //Enemies
            for (int j = floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies.size()-1;j>=0;j--){
                if(CheckCollision(isaac->bombs[i]->explosion,floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[j]->EnemyFigure))
                    floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[j]->TakeDamage(1);
                }
            //Isaac
            if(CheckCollision(isaac->bombs[i]->explosion,isaac->IsaacFigure))
                isaac->TakeDamage(1);
            delete isaac->bombs[i];
            isaac->bombs.erase(isaac->bombs.begin() + i);
        }
    }
}

void Game::renderBomb() {

    for (auto *bombs : isaac->bombs) {
        bombs->DrawBomb(*(window));
    }
}

//Room
void Game::updateRoom() {

    //Doors
    //Porta su
    if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorUp!= nullptr)
        if(CheckCollision(isaac->IsaacFigure,*floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorUp)){
            isaac->IsaacFigure.setPosition(Vector2f(444,isaac->IsaacFigure.getPosition().y+370));
            isaac->bullets.clear();
            isaac->bombs.clear();
            floor->ActualRoom.x--;
            isaac->addRoom(missions[2].get());


        }
    //Porta destra
    if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorRight!= nullptr)
        if(CheckCollision(isaac->IsaacFigure,*floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorRight)){
            isaac->IsaacFigure.setPosition(Vector2f(isaac->IsaacFigure.getPosition().x-794,400));
            isaac->bullets.clear();
            isaac->bombs.clear();
            floor->ActualRoom.y++;
            isaac->addRoom(missions[2].get());



        }
    //Porta giu
    if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorDown!= nullptr)
        if(CheckCollision(isaac->IsaacFigure,*floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorDown)){
            isaac->IsaacFigure.setPosition(Vector2f(444,isaac->IsaacFigure.getPosition().y-370));
            isaac->bullets.clear();
            isaac->bombs.clear();
            floor->ActualRoom.x++;
            isaac->addRoom(missions[2].get());



        }
    //Porta sinistra
    if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorLeft!= nullptr)
        if(CheckCollision(isaac->IsaacFigure,*floor->room[floor->ActualRoom.x][floor->ActualRoom.y].DoorLeft)){
            isaac->IsaacFigure.setPosition(Vector2f(isaac->IsaacFigure.getPosition().x+794,400));
            isaac->bullets.clear();
            isaac->bombs.clear();
            floor->ActualRoom.y--;
            isaac->addRoom(missions[2].get());

        }
    for (int j = floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items.size()-1;j>=0;j--) {
        if (!floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items[j]->UpdateItem(*isaac, CheckCollision(isaac->IsaacFigure, floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items[j]->ItemFigure))){
            delete floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items[j];
            floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items.erase(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Items.begin() + j);;
        }
    }


    }


//Actual Room
void Game::renderActualRoom() {

    floor->DrawActualRoom(*(window));

}
//Enemies
void Game::updateEnemies() {
    for (int i = floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies.size() - 1; i >= 0; i--)
    {
        floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[i]->UpdateEnemy(*(isaac));
        if(CheckCollision(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[i]->EnemyFigure,isaac->IsaacFigure)){
            isaac->TakeDamage(1);
            floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[i]->TakeDamage(2);

        }
        if(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[i]->getLife()<=0) {
            isaac->addKill(missions[0].get());
            delete floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies[i];
            floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies.erase(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Enemies.begin() + i);
        }
    }
}

//Update
void Game::update() {

    updatePollEvents();
    updateIsaac();
    updateBullet();
    updateBomb();
    updateEnemies();
    updateRoom();
}

//Render
void Game::render() {

    window->clear();

    //Draw game objects
    renderBackground();
    renderMap();
    renderStats();
    renderIsaac();
    renderActualRoom();
    renderBomb();
    renderBullet();



    window->display();
}

bool Game::CheckCollision(RectangleShape one, RectangleShape two) {

    bool collisionX = one.getPosition().x + one.getSize().x >= two.getPosition().x &&
            two.getPosition().x + two.getSize().x >= one.getPosition().x;
    bool collisionY = one.getPosition().y + one.getSize().y >= two.getPosition().y &&
            two.getPosition().y + two.getSize().y >= one.getPosition().y;
    return collisionX && collisionY;

}

bool Game::IsaacMoveIsPossible(float dirX, float dirY) {
    bool collisionRock = false;
    RectangleShape clone = isaac->IsaacFigure;
    clone.move(Vector2f(dirX*isaac->getSpeed(),dirY*isaac->getSpeed()));
    //Rock collision
    for (int i = floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks.size() - 1; i >= 0; i--)
    {
        if(CheckCollision(floor->room[floor->ActualRoom.x][floor->ActualRoom.y].Roocks[i]->rock,clone))
        {
            collisionRock= true;
        }
    }
    return (clone.getPosition().x<880 && clone.getPosition().x>35 && clone.getPosition().y<615 && clone.getPosition().y>210 && !collisionRock);
}


