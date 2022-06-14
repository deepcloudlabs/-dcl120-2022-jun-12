/* 
 * File:   Bank.h
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 7:30 PM
 */
#include "Customer.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef _BANK_H
#define	_BANK_H

struct SortCustomerByBalance{
	bool operator()(Customer *cus1,Customer *cus2){
		  return cus1->getTotalBalance()
				 >
				 cus2->getTotalBalance();
	}
};

struct ShowName {
	bool operator()(Customer *cus){
		cout 	<< cus->getLastName() 
				<< ","
				<< cus->getFirstName()
				<< endl;
		return true;
	}
};

class Bank {
private:
    static vector<Customer*> customers;
    Bank();
public:
    static void addCustomer(string f,string l);
    static int getNumOfCustomers(){
        return customers.size();
    }
    static Customer *getCustomer(int index);
    static void reportCustomers(){
		sort(customers.begin(),customers.end(),SortCustomerByBalance());
		for_each(customers.begin(),customers.end(),ShowName());
    }
} ;

#endif	/* _BANK_H */

