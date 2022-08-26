#include <SFML/Graphics.hpp>

#define MaxMainMenu 3

#define WIDHT 960
#define HEIGHT 720

using namespace sf;


class Menu {
private:
    //Variables
    RectangleShape MainBackGround;
    Texture MainTexture;
    Font MainFont;
    int MenuType;

    //Texts
    Text MenuSelections[MaxMainMenu];
    Text Commands;
    int MainMenuSelected;
    Event ev;

    //Function private
    void InitBackground();
    void InitFont();
    void InitTextMenu();
    void InitMenu();
    void DrawMenu(RenderWindow & window);

public:
    //Accessors
    bool MenuIsRunning;

    //Constructor and Destructor
    Menu();
    virtual ~Menu();

    //Function public
    void MoveUp();
    void MoveDown();
    void MainMenu(RenderWindow & window);

};


