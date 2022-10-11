#include "Floor.h"
#include <iostream>

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
                //Treasure room
                if(this->room[i][j].TypeRoom == 3){
                    ROOM.setFillColor(Color::Yellow);
                }
                //Boss room
                if(this->room[i][j].TypeRoom == 4){
                    ROOM.setFillColor(Color::Red);
                }
                //Actual room
                if(i==ActualRoom.x && j==ActualRoom.y){
                    ROOM.setFillColor(Color::Green);
                }
                window.draw(ROOM);
                delete &ROOM;
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

    for (int i = 0; i < FloorDimension; ++i) {
        for (int j = 0; j < FloorDimension; ++j) {
            if(this->room[i][j].TypeRoom!=0)
                this->GenerateRoom(i,j);
        }
    }


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
    this->ActualRoom.x=x;
    this->ActualRoom.y=y;

    //Treasure room
    this->RandomValidRoomCoordinate(x,y);
    this->room[x][y].TypeRoom = 3;
    //Boss room
    this->RandomValidRoomCoordinate(x,y);
    this->room[x][y].TypeRoom = 4;

}

void Floor::GenerateRoom(int x, int y) {
    //Doors
    if (this->room[x-1][y].TypeRoom != 0 and x-1>=0)
        this->room[x][y].DoorUp = make_unique<Door>(0);
    if (this->room[x][y+1].TypeRoom != 0 and y+1<FloorDimension)
        this->room[x][y].DoorRight = make_unique<Door>(1);
    if (this->room[x+1][y].TypeRoom != 0 and x+1<FloorDimension)
        this->room[x][y].DoorDown = make_unique<Door>(2);
    if (this->room[x][y-1].TypeRoom != 0 and y-1>=0)
        this->room[x][y].DoorLeft = make_unique<Door>(3);


}

void Floor::DrawActualRoom(RenderWindow &window) {


    if(this->room[ActualRoom.x][ActualRoom.y].DoorUp != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorUp);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorRight != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorRight);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorDown != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorDown);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorLeft != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorLeft);

}

Floor::~Floor() = default;

