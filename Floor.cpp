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
                this->GenerateDoors(i,j);
            if(this->room[i][j].TypeRoom==1)
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

void Floor::GenerateDoors(int x, int y) {
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

//STANZE (12 tipi di stanze)
void Floor::GenerateRoom(int x, int y) {
    //Obstacles
    float X,Y;
    switch (rand()%12) {

        case 0:
            //ROCCE
            X=300;
            Y=375;
            for (int i = 0; i < 5; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                X+=75;
            }

            break;

        case 1:
            //ROCCE
            X=50;
            Y=510;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=190;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=75;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=75;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X=850;
            Y=300;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=190;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=75;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=75;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            break;

        case 2:
            //ROCCE
            X=300;
            Y=225;
            for (int i = 0; i < 6; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                if(i==2)
                    X=575;
                Y+=75;
            }

            break;
        case 3:
            //ROCCE
            X=230;
            Y=320;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=450;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=180;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=450;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));


            break;
        case 4:
            //ROCCE
            X=410;
            Y=350;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            break;
        case 5:
            //ROCCE
            X=250;
            Y=375;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=220;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            break;
        case 6:
            //ROCCE
            X=50;
            Y=510;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=480;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X=50;
            Y=300;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=480;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));

            break;
        case 7:
            //ROCCE
            X=230;
            Y=290;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=450;
            Y+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=80;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));

            break;
        case 8:
            //ROCCE
            X=280;
            Y=520;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X=600;
            Y=520;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X+=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            X-=70;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));


            break;
        case 9:
            //ROCCE
            X=300;
            Y=395;
            for (int i = 0; i < 5; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                X+=75;
            }
            X=450;
            Y=320;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
            Y+=150;
            this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));

            break;
        case 10:
            //ROCCE
            X=300;
            Y=320;
            for (int i = 0; i < 5; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                X+=75;
            }
            X=300;
            Y=490;
            for (int i = 0; i < 5; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                X+=75;
            }

            break;
        case 11:
            //ROCCE
            X=250;
            Y=320;
            for (int i = 0; i < 3; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                Y+=75;
            }
            X=615;
            Y=320;
            for (int i = 0; i < 3; ++i) {
                this->room[x][y].Roocks.push_back( new Rock(Vector2f(X,Y)));
                Y+=75;
            }
            break;
        default:
            break;
    }

}

void Floor::DrawActualRoom(RenderWindow &window) {

    //Doors
    if(this->room[ActualRoom.x][ActualRoom.y].DoorUp != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorUp);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorRight != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorRight);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorDown != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorDown);
    if(this->room[ActualRoom.x][ActualRoom.y].DoorLeft != nullptr)
        window.draw(*this->room[ActualRoom.x][ActualRoom.y].DoorLeft);

    //Obstacles
    for (auto *obstacles : this->room[ActualRoom.x][ActualRoom.y].Roocks) {
        obstacles->DrawRock(window);
    }

}


Floor::~Floor() = default;

