#ifndef __Facilities_Department_H__
#define __Facilities_Department_H__
class Facilities_Department {
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
          Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
          EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
          ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
          EngineerFillsOutPaperWork, Complete
    };
    int _state;
};
#endif
