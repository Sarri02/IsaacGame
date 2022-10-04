#include "Room.h"

void Room::InitRoom() {
    //Stanza non esistente
    this->TypeRoom=0;
}

Room::Room() {

    this->InitRoom();

}

Room::~Room() = default;
