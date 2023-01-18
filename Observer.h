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
    virtual void update(int value) = 0;
};

#endif