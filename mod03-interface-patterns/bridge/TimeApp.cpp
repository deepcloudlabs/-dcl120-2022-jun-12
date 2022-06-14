#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

class TimeImpl {
  public:
    TimeImpl(int hr, int min) {
        hr_ = hr;
        min_ = min;
    }
    virtual void tell() {
        cout << "time is " << setw(2) << setfill('*') << hr_ << min_ << endl;
    }
  protected:
    int hr_, min_;
};

class CivilianTimeImpl: public TimeImpl {
  public:
    CivilianTimeImpl(int hr, int min, int pm): TimeImpl(hr, min) {
        if (pm)
          strcpy(whichM_, " PM");
        else
          strcpy(whichM_, " AM");
    }

    /* virtual */
    void tell() {
        cout << "time is " << hr_ << ":" << min_ << whichM_ << endl;
    }
  protected:
    char whichM_[4];
};

class ZuluTimeImpl: public TimeImpl {
  public:
    ZuluTimeImpl(int hr, int min, int zone): TimeImpl(hr, min) {
        if (zone == 5)
          strcpy(zone_, " Eastern Standard Time");
        else if (zone == 6)
          strcpy(zone_, " Central Standard Time");
    }

    /* virtual */
    void tell() {
        cout << "time is " << setw(2) << setfill('*') << hr_ << min_ << zone_ <<
          endl;
    }
  protected:
    char zone_[30];
};

class Time {
  public:
    Time(){}
    Time(int hr, int min) {
        impl = new TimeImpl(hr, min);
    }
    virtual void sayTime() {
        impl->tell();
    }
  protected:
    TimeImpl *impl;
};

class CivilianTime: public Time {
  public:
    CivilianTime(int hr, int min, int pm) {
        impl = new CivilianTimeImpl(hr, min, pm);
    }
};

class ZuluTime: public Time {
  public:
    ZuluTime(int hr, int min, int zone) {
        impl = new ZuluTimeImpl(hr, min, zone);
    }
};

int main() {
  Time *times[3];
  times[0] = new Time(14, 30);
  times[1] = new CivilianTime(2, 30, 1);
  times[2] = new ZuluTime(14, 30, 6);
  for (int i = 0; i < 3; i++)
    times[i]->sayTime();
}
