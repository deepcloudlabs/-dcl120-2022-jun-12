#pragma once

#include <vector>
#include <list>
#include "Shop.h"

class Subject{
    //Lets keep a track of all the shops we have observing
    std::vector<Shop*> list;

public:
    void attach(Shop *product);
    void detach(Shop *product);
    void notify(float price); 
};
