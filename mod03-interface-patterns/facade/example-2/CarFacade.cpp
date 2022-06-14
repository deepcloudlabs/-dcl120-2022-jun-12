#include <iostream>

using namespace std;

class Engine {

public:
    void start() { 
       cout << "Engine has started!" << endl ;
    }

};

class Headlights {

public:
    void turnOn() { 
       cout << "Headlights are ON!" << endl ;
    }

};

//  That's your facade.
class Car {

private:
    Engine engine;
    Headlights headlights;

public:
    void turnIgnitionKeyOn() {
    	headlights.turnOn();
    	engine.start();
    }

};

int main(int argc, char *argv[]){
    Car car;
    car.turnIgnitionKeyOn();

    return 0;
}
