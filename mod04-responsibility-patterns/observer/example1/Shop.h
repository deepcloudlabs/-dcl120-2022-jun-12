#pragma once
#include <iostream>
#include <string>
#include "Observer.h"

class Shop : Observer {
    //Name of the Shop
    std::string name;
    float price;
public:
    Shop(std::string n); 
    void update(float price);          
};
