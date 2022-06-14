#include "Customer.h"
#include "Account.h"
#include <numeric>

using namespace std;
struct Balance {
    double operator()(double sum, Account *p){
       return sum + p->getBalance() ;
    }
} ;

Customer::Customer(string firstName,string lastName){
    this->firstName= firstName;
    this->lastName= lastName;
}

double Customer::getTotalBalance(){
	return accumulate(accounts.begin(),accounts.end(), double(),Balance());
}
