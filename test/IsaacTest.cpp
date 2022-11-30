#include "gtest/gtest.h"
#include "../Isaac.h"
#include "../Rock.h"


using namespace sf;

TEST(Isaac, Constructor){
Isaac isaac(sf::Vector2f(0,0));
ASSERT_EQ(isaac.IsaacFigure.getPosition(), Vector2f(0,0));
}

TEST(Isaac, Shoot){
    Isaac isaac(sf::Vector2f(0,0));
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

TEST(Isaac, Bombs){
    Isaac isaac(sf::Vector2f(0,0));
    int size = isaac.bombs.size();
    isaac.dropBomb();
    ASSERT_EQ(size+1, isaac.bombs.size());
}