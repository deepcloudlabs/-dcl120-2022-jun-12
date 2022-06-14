#include <vector>
#include <iostream>

using namespace std;

class Sensor;

class Visitor {
public:
    virtual void accept(Sensor *sensor) = 0;
};

class Sensor {
public:
    virtual void visit(Visitor *visitor) = 0;

    virtual double readSensorValue() = 0;
};

class Reporter : public Visitor {
public:
    void accept(Sensor *sensor) {
        cout << "Reading sensor value: " << sensor->readSensorValue() << endl;
    }
};


class Composite {
protected:
    vector<Sensor *> sensors;
public:
    virtual void visit(Visitor *visitor) = 0;

    void add(Sensor *sensor) {
        sensors.push_back(sensor);
    }
};

class TemperatureSensor : public Sensor {
private:
    double temperature;
public:
    void visit(Visitor *visitor) {
        visitor->accept(this);
    }

    double readSensorValue() {
        return temperature;
    }
};

class HumiditySensor : public Sensor {
private:
    double humidity;
public:
    void visit(Visitor *visitor) {
        visitor->accept(this);
    }

    double readSensorValue() {
        return humidity;
    }
};


class Room : public Composite {
public:
    void visit(Visitor *visitor) {
        for (auto &sensor : sensors) {
            visitor->accept(sensor);
        }
    }
};

int main(int argc, char *argv[]) {
    Room roomA;
    TemperatureSensor ts1, ts2;
    roomA.add(&ts1);
    roomA.add(&ts2);
    Reporter reporter;
    roomA.visit(&reporter);
    return 0;
}

