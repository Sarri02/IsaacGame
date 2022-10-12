#include "Room.h"

void Room::InitRoom() {
    //Stanza non esistente
    this->TypeRoom=0;
    this->RoomCode=0;

    //Doors
    this->DoorLeft= nullptr;
    this->DoorDown= nullptr;
    this->DoorRight= nullptr;
    this->DoorUp= nullptr;

}

Room::Room() {

    this->InitRoom();

}

Room::~Room() = default;
