#include "Room.h"

void Room::InitRoom() {
    //Stanza non esistente
    this->TypeRoom=0;
}

Room::Room() {

    this->InitRoom();
    this->GenerateRoom();

}

Room::~Room() = default;


void Room::GenerateRoom() {

    //TODO genera stanza

}

