#include <iostream>
#include <string>

using namespace std;

class Appliance {
   public: 
      virtual void run()=0;
} ;

//the abstraction
class Switch {
   protected:
      Appliance *appliance;
   public:
      Switch(Appliance *_appliance) : appliance(_appliance) {
      }
      virtual void turnOn()=0;
} ;


//concrete abstraction
class RemoteControl : public Switch {
   public:
      RemoteControl(Appliance *appliance) : Switch(appliance){
      }

      void turnOn(){
          appliance->run();
      }
};

//concrete implementation
class TV : public Appliance {
    private:
      string name;
    public:
      TV(string name) {
         this->name = name;
      }

      void run(){
        cout << this->name << " is running" << endl;
      }
};

//concrete implementation
class VaccumCleaner : public Appliance {
    private:
      string name;
    public:
      VaccumCleaner(string name) {
           this->name = name;
      }

      void run() {
        cout << this->name << " is running" << endl;
      }
};

//convert implementation object to abstraction object
Switch* getSwitch(Appliance *a){
   return new RemoteControl(a);
}

int main() {
    Appliance *tv = new TV((string("Bedroom TV")));  //implementation object
    Appliance *vacuum = new VaccumCleaner(string("My Vacuum Cleaner"));  //implementation object

    Switch* s1 = getSwitch(tv);  //convert to abstraction
    Switch* s2 = getSwitch(vacuum);  //convert to abstraction

    //*** client code works only with the abstraction objects, not the implementation objects ***
    s1->turnOn();
    s2->turnOn();

    delete s1;
    delete s2;
}
