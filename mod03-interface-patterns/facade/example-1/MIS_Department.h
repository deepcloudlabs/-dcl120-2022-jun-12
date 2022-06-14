#ifndef __MIS_Department_H__
#define __MIS_Department_H__
class MIS_Department {
  public:
    void submitNetworkRequest() {
        _state = 0;
    }
    bool checkOnStatus() {
        _state++;
        if (_state == Complete)
          return true;
        return false;
    }
  private:
    enum States {
          Received, DenyAllKnowledge, ReferClientToFacilities,
          FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
          ElectricianDidItWrong, DispatchTechnician, SignedOff, 
          DoesNotWork, FixElectriciansWiring, Complete
    };
    int _state;
};
#endif
