#include "Room.h"

void Room::InitRoom() {
    //Stanza non esistente
    this->TypeRoom=0;
}

Room::Room() {

    this->InitRoom();
    this->GenerateRoom();

}

void Room::GenerateRoom() {
    //Door
    //TODO genera le stanze
}
