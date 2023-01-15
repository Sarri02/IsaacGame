#ifndef FLOOR_CPP_OBSERVER_H
#define FLOOR_CPP_OBSERVER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>


//Observer
class Observer {
protected:
    virtual ~Observer() = default;

public:
    virtual bool update(int value,int control) = 0;
};

#endif