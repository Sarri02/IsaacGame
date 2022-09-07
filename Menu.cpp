#include "Menu.h"


#define DMNS 40
#define DMS 50

//Initialization of Background Menu
void Menu::InitBackground() {

    this->MainBackGround.setSize(Vector2f(WIDHT,HEIGHT));
    this->MainTexture.loadFromFile("../Texture/BackGroundMenu.png");
    this->MainBackGround.setTexture(&(this->MainTexture));
}

//Drawing Selections
void Menu::DrawMenu(RenderWindow & window) {

    for (int i=0; i < MaxMainMenu; i++ )
    {
        window.draw(MenuSelections[i]);
    }

}

//Initialization of Selections Menu
void Menu::InitTextMenu() {

    //Font
    this->MainFont.loadFromFile("../Fonts/DePixelHalbfett.ttf");

    //Start
    this->MenuSelections[0].setFont(this->MainFont);
    this->MenuSelections[0].setFillColor(Color::Black);
    this->MenuSelections[0].setString("START");
    this->MenuSelections[0].setCharacterSize(DMNS);
    this->MenuSelections[0].setPosition(315, 150);
    //Commands
    this->MenuSelections[1].setFont(this->MainFont);
    this->MenuSelections[1].setFillColor(Color::Black);
    this->MenuSelections[1].setString("COMMANDS");
    this->MenuSelections[1].setCharacterSize(DMNS);
    this->MenuSelections[1].setPosition(315, 300);
    //Quit
    this->MenuSelections[2].setFont(this->MainFont);
    this->MenuSelections[2].setFillColor(Color::Black);
    this->MenuSelections[2].setString("QUIT");
    this->MenuSelections[2].setCharacterSize(DMNS);
    this->MenuSelections[2].setPosition(315, 450);

    //Commands and Option
    this->Commands.setFont(this->MainFont);
    this->Commands.setFillColor(Color::Black);
    this->Commands.setString("       COMMANDS\n\nMOVE ON               W\n\nMOVE LEFT            A\n\nMOVE DOWN         S\n\nMOVE RIGHT         D\n\nSHOOT UP              up\n\nSHOOT LEFT           left\n\nSHOOT DOWN       down\n\nSHOOT RIGHT        right\n\nBOMBS                    E");
    this->Commands.setCharacterSize(24);
    this->Commands.setPosition(320, 80);

}

//Initialization of first selection of Menu
void Menu::InitMenu() {

    this->MainMenuSelected = 0;
    this->MenuSelections[MainMenuSelected].setCharacterSize(DMS);
}

//Constructor
Menu::Menu() {
    this->MenuType = 0;
    this->MenuIsRunning = true;
    this->InitBackground();
    this->InitTextMenu();
    this->InitMenu();
}

//Destructor
Menu::~Menu() = default;

//MoveUp
void Menu::MoveUp()
{
    if (this->MainMenuSelected + 1 >= 0)
    {
        this->MenuSelections[this->MainMenuSelected].setCharacterSize(DMNS);

        this->MainMenuSelected--;
        if (this->MainMenuSelected == -1)
        {
            this->MainMenuSelected = 2;
        }
        this->MenuSelections[this->MainMenuSelected].setCharacterSize(DMS);
    }
}
//MoveDown
void Menu::MoveDown()
{
    if (this->MainMenuSelected - 1 <= MaxMainMenu)
    {
        this->MenuSelections[MainMenuSelected].setCharacterSize(DMNS);
        this->MainMenuSelected++;
        if (this->MainMenuSelected == 3)
        {
            this->MainMenuSelected = 0;
        }
        this->MenuSelections[this->MainMenuSelected].setCharacterSize(DMS);
    }
}

//Menu effettivo
void Menu::MainMenu(RenderWindow & window) {

    //Loop
    while (MenuIsRunning) {
        while (window.pollEvent(ev)) {
            switch (this->ev.type) {
                case Event::Closed:
                    window.close();
                    this->MenuIsRunning = false;
                    break;
                case Event::KeyReleased:
                    //Escape close window
                    if (this->ev.key.code == Keyboard::Escape) {
                        if (this->MenuType > 0)
                            //Return to MainMenu
                            this->MenuType = 0;
                        else{
                            //Close the window from the Menu
                            this->MenuIsRunning = false;
                            window.close();
                        }

                        break;
                    }
                    //Move up in Menu
                    if (this->ev.key.code == Keyboard::Up and this->MenuType == 0) {
                        this->MoveUp();
                        break;
                    }
                    //Move down in Menu
                    if (this->ev.key.code == Keyboard::Down and this->MenuType == 0) {
                        this->MoveDown();
                        break;
                    }
                    if (this->ev.key.code == Keyboard::Enter and this->MenuType == 0) {
                        switch (this->MainMenuSelected) {
                            //Start
                            case 0:
                                window.setTitle("The Binding of Isaac");
                                this->MenuIsRunning = false;
                                break;
                                //Commands
                            case 1:
                                this->MenuType = 1;
                                break;
                                //Quit
                            case 2:
                                window.close();
                                this->MenuIsRunning = false;
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                default:
                    break;
            }
        }
        //Draw
        window.draw(this->MainBackGround);
        if (this->MenuType == 0) {
            this->DrawMenu(window);
        }
        if (this->MenuType == 1) {
            window.draw(this->Commands);
        }
        window.display();
        window.clear();
    }
}
