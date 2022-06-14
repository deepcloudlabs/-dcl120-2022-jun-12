#include <iostream>

class SubSystemOne {
public:
    void methodOne()  {
    	std::cout << " SubSystemOne Method" << std::endl;
    }
};


class SubSystemTwo {
public:
    void methodTwo() {
    	std::cout << " SubSystemTwo Method" << std::endl;
    }
};

class SubSystemThree {
public:
    void methodThree() {
    	std::cout << " SubSystemThree Method" << std::endl;
    }
};

// Subsystem ClassD" 

class SubSystemFour {
public:
    void methodFour() {
    	std::cout << " SubSystemFour Method" << std::endl;
    }
};

// "Facade" 

class Facade {
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;
    SubSystemFour four;

public:
    Facade() { }

    void methodA() {
    	std::cout << "\nMethodA() ---- " << std::endl;
    	one.methodOne();
    	two.methodTwo();
    	four.methodFour();
    }

    void methodB() {
    	std::cout << "\nMethodB() ---- " << std::endl;
    	two.methodTwo();
    	three.methodThree();
    }
};

int main() {
    Facade *facade = new Facade();

    facade->methodA();
    facade->methodB();

    delete facade;

    return 0;
}
