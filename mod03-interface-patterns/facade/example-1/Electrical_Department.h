#ifndef __Electrical_Department_H__
#define __Electrical_Department_H__
class Electrical_Department {
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
          Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
          WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
          DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
          TurnInThePaperwork, Complete
    };
    int _state;
};
#endif
