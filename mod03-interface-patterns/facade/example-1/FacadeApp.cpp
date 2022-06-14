#include "MIS_Department.h"
#include "Electrical_Department.h"
#include "Facilities_Department.h"
#include "FacilitiesFacade.h"
#include <iostream>

using namespace std;

int main(){
  FacilitiesFacade facilities;

  facilities.submitNetworkRequest();
  /* Keep checking until job is complete */
  while (!facilities.checkOnStatus())
    ;
  cout << "job completed after only " << facilities.getNumberOfCalls() << " phone calls" << endl;
  return 0;
}
