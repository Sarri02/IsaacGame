#include "gtest/gtest.h"
#include "../Isaac.h"

TEST(Isaac, Constructor){
Isaac isaac(sf::Vector2f(0,0));
ASSERT_EQ(isaac.IsaacFigure.getPosition(), sf::Vector2f(0,0));
}
