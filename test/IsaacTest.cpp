#include "gtest/gtest.h"
#include "../Game.h"
#include "../EnemyBasic.h"


using namespace sf;

TEST(Isaac, Constructor){
Isaac isaac(sf::Vector2f(0,0));
ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(0,0));
}

TEST(Isaac, Shoot){
    Isaac isaac(sf::Vector2f(300,300));
    int size = isaac.bullets.size();
    isaac.Shoot(1,0);
    ASSERT_EQ(size+1, isaac.bullets.size());
    size = isaac.bullets.size();
    isaac.Shoot(-1,0);
    ASSERT_EQ(size+1, isaac.bullets.size());
    size = isaac.bullets.size();
    isaac.Shoot(0,1);
    ASSERT_EQ(size+1, isaac.bullets.size());
    size = isaac.bullets.size();
    isaac.Shoot(0,-1);
    ASSERT_EQ(size+1, isaac.bullets.size());
}

TEST(Isaac, ShotEnemy){
   Game game;
   //create enemy
   game.floor[game.ActualFloor].room[game.floor->ActualRoom.x][game.floor->ActualRoom.y].Enemies.push_back( new EnemyBasic(Vector2f(game.isaac->IsaacFigure.getPosition().x+40,game.isaac->IsaacFigure.getPosition().y)));
   ASSERT_EQ(game.floor[game.ActualFloor].room[game.floor->ActualRoom.x][game.floor->ActualRoom.y].Enemies.size(),1);
   //3 shot for kill him
   game.isaac->Shoot(1,0);
   game.isaac->Shoot(1,0);
   game.isaac->Shoot(1,0);
   while(game.isaac->bullets.size()>0) {
       game.update();
   }
   ASSERT_EQ(game.floor[game.ActualFloor].room[game.floor->ActualRoom.x][game.floor->ActualRoom.y].Enemies.size(),0);
}

TEST(Isaac, Move){
    Isaac isaac(sf::Vector2f(300,300));
    isaac.Move(1,0);
    ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(300+isaac.getSpeed(),300));
    isaac.Move(-1,0);
    ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(300,300));
    isaac.Move(0,1);
    ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(300,300+isaac.getSpeed()));
    isaac.Move(0,-1);
    ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(300,300));
}

TEST(Isaac, MoveRock){
    Game game;
    //move without rock
    ASSERT_TRUE(game.IsaacMoveIsPossible(1,0));
    //create rock
    game.floor[game.ActualFloor].room[game.floor->ActualRoom.x][game.floor->ActualRoom.y].Roocks.push_back( new Rock(Vector2f(game.isaac->IsaacFigure.getPosition().x+70,game.isaac->IsaacFigure.getPosition().y)));
    ASSERT_EQ(game.floor[game.ActualFloor].room[game.floor->ActualRoom.x][game.floor->ActualRoom.y].Roocks.size(),1);
    //NO move with rock
    ASSERT_FALSE(game.IsaacMoveIsPossible(1,0));
}


TEST(Isaac, Bombs){
    Isaac isaac(sf::Vector2f(0,0));
    int size = isaac.bombs.size();
    isaac.dropBomb();
    ASSERT_EQ(size+1, isaac.bombs.size());
}