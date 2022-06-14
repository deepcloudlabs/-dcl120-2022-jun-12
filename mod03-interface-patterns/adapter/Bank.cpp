#include "Bank.h"

Bank::Bank(){
}

void Bank::addCustomer(string f,string l){
    customers.push_back(new Customer(f,l));
}

Customer *Bank::getCustomer(int index){
   if (index<0) index=0;
   if (index>=customers.size()) index=customers.size()-1;
   return customers[index]; 
}
