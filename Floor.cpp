#include "Floor.h"
//Select a random room
void Floor::RandomValidRoomCoordinate(int &x, int &y) {

    while(this->room[x][y].TypeRoom != 1){
        x = rand()%FloorDimension;
        y = rand()%FloorDimension;
    }
}


//Draw floor map
void Floor::DrawMap(RenderWindow &window) {
    int xPos=697, yPos=48;
    for (int i = 0; i < FloorDimension; i++) {
        for (int j = 0; j < FloorDimension; j++) {
            if(this->room[i][j].TypeRoom != 0){

                RectangleShape ROOM;
                ROOM.setSize(Vector2f(25,12));
                ROOM.setPosition(xPos,yPos);
                ROOM.setFillColor(Color::White);
                //Starting room
                if(this->room[i][j].TypeRoom == 2){
                    ROOM.setFillColor(Color::Green);
                }
                //Treasure room
                if(this->room[i][j].TypeRoom == 3){
                    ROOM.setFillColor(Color::Yellow);
                }
                //Boss room
                if(this->room[i][j].TypeRoom == 4){
                    ROOM.setFillColor(Color::Red);
                }
                window.draw(ROOM);
            }
            xPos += 35;
        }
        xPos = 697;
        yPos += 17;
    }
}
//Constructor

Floor::Floor() {

    srand(time(NULL));

    this->GenerateFloor();

}

void Floor::GenerateFloor() {


    //First room
    int x=FloorDimension/2 ,y=FloorDimension/2;
    this->room[x][y].TypeRoom = 1;

    //Other room generetor
    for (int i = 0; i < MaxRooms-1; i++) {


        this->RandomValidRoomCoordinate(x,y);

        if(rand()%2==0)
            x += (rand()%2)*2-1;
        else
            y += (rand()%2)*2-1;
        if(x<FloorDimension and x>=0 and y<FloorDimension and y>=0)
        {
            if(this->room[x][y].TypeRoom == 0){

                this->room[x][y].TypeRoom = 1;
            }
            else
                i--;
        }
        else
            i--;
    }

    //Starting room
    this->RandomValidRoomCoordinate(x,y);
    this->room[x][y].TypeRoom = 2;
    //Treasure room
    this->RandomValidRoomCoordinate(x,y);
    this->room[x][y].TypeRoom = 3;
    //Boss room
    this->RandomValidRoomCoordinate(x,y);
    this->room[x][y].TypeRoom = 4;
}

