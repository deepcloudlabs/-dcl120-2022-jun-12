#include <vector>
#include <typeinfo>
#include <iterator>
#include <iostream>

using namespace std;

class Sensor;

class Visitor {
public:
	virtual void accept(Sensor *sensor) = 0;
};

class Sensor {	
public:
	virtual void visit(Visitor* visitor) = 0;
	virtual double readSensorValue() = 0;
};

class Reporter : public Visitor {
public:
	void accept(Sensor *sensor){
		cout << "Reading sensor (" << typeid(*sensor).name() << ") value: " << sensor->readSensorValue() << endl;
	}
};

class Alarmer : public Visitor {
public:
	void accept(Sensor *sensor){
		if
		cout << "Reading sensor (" << typeid(*sensor).name() << ") value: " << sensor->readSensorValue() << endl;
	}
};

class Composite {
protected:
	vector<Sensor*> sensors;
public:
	virtual void visit(Visitor* visitor) = 0;
	void add(Sensor *sensor){
		sensors.push_back(sensor);
	}
};

class TemperatureSensor : public Sensor {
private:
	double temperature;
public:
	void visit(Visitor* visitor){
		visitor->accept(this);
	}
	double readSensorValue(){
		return temperature;
	}
};

class HumiditySensor : public Sensor {
private:
	double humidity;
public:
	void visit(Visitor* visitor){
		visitor->accept(this);
	}
	double readSensorValue(){
		return humidity;
	}
};


class Room : public Composite {
   public:
	   void visit(Visitor* visitor){
		   for (auto it = sensors.begin(); it!=sensors.end(); ++it){
			   (*it)->visit(visitor);
		   }
	   }
};

int main(int argc, char* argv[]) {
	Room roomA;
	TemperatureSensor ts1, ts2;
	HumiditySensor hs1, hs2;
	roomA.add(&ts1);
	roomA.add(&hs1);
	roomA.add(&ts1);
	roomA.add(&hs2);
	Reporter reporter;
	roomA.visit(&reporter);
	return 0;
}

