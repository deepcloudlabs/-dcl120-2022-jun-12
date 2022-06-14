#include "Electrical_Department.h"
#include "MIS_Department.h"
#include "Facilities_Department.h"

#include <iostream>

using namespace std;

#ifndef __FacilitiesFacede_H__
#define __FacilitiesFacede_H__
class FacilitiesFacade {
  public:
    FacilitiesFacade() {
        _count = 0;
    }
    void submitNetworkRequest() {
        _state = 0;
    }
    bool checkOnStatus() {
        _count++;
        /* Job request has just been received */
        if (_state == Received) {
            _state++;
            /* Forward the job request to the engineer */
            _engineer.submitNetworkRequest();
            cout << "submitted to Facilities - " << _count << " phone calls so far" << endl;
        }
        else if (_state == SubmitToEngineer) {
            /* If engineer is complete, forward to electrician */
            if (_engineer.checkOnStatus()) {
                _state++;
                _electrician.submitNetworkRequest();
                cout << "submitted to Electrician - " << _count << " phone calls so far" << endl;
            }
        }
        else if (_state == SubmitToElectrician) {
            /* If electrician is complete, forward to technician */
            if (_electrician.checkOnStatus()) {
                _state++;
                _technician.submitNetworkRequest();
                cout << "submitted to MIS - " << _count << " phone calls so far" << endl;
            }
        }
        else if (_state == SubmitToTechnician) {
            /* If technician is complete, job is done */
            if (_technician.checkOnStatus())
              return 1;
        }
        /* The job is not entirely complete */
        return 0;
    }
    int getNumberOfCalls() {
        return _count;
    }
  private:
    enum States {
        Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
    };
    int _state;
    int _count;
    Facilities_Department _engineer;
    Electrical_Department _electrician;
    MIS_Department _technician;
};
#endif
