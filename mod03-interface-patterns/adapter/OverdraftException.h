#include <exception>
#include <string>

using namespace std; 

#ifndef __OverdraftException__
#define __OverdraftException__
class OverdraftException : public exception {
     double deficit;
     string reason;
   public:
     OverdraftException(string reason,double deficit) :
          reason(reason),
          deficit(deficit)
     {
     }
     ~OverdraftException() throw() {
     }
     double getDeficit(){
        return deficit;
     }
     const char* what() const throw() {
        return reason.c_str();
     }
};
#endif
