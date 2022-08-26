#include "Game.h"

using namespace sf;

int main() {

    //Initialization Game
    Game game;

    //MainMenu
    Menu menu;
    menu.MainMenu(*game.window);

    //Game loop
    while (game.running())
    {

        //Update
        game.update();

        //Render
        game.render();

    }

    //End
    return 0;
}