/* 
 * File:   Customer.h
 * Author: binnur.kurt
 *
 * Created on November 7, 2008, 3:43 PM
 */
#include "Account.h"
#include <string>
#include <algorithm>
#include <list>
using namespace std;

#ifndef _CUSTOMER_H
#define	_CUSTOMER_H
/*
struct BalanceAccumulator {
	double operator()(double acc,Account *p){
		return acc + p->getBalance();
	}
};
*/
class Customer {
private:
    string firstName;
    string lastName;
    list<Account*> accounts;
public:
    Customer(std::string firstName,std::string lastName);
    void addAccount(Account *acc){
        accounts.push_back(acc);
    }
	double getTotalBalance();
    Account *getAccount(int index){
        if (index<0) index=0;
        if (index>=accounts.size()) index=accounts.size()-1;
        list<Account*>::iterator iter= accounts.begin();
        advance(iter,index);
        return *iter;
    }
    std::string getFirstName(){
        return firstName;
    }
    std::string getLastName(){
        return lastName;
    }
    int getNumOfAccounts(){
        return accounts.size();
    }
    ~Customer(){
        for (list<Account*>::iterator iter=accounts.begin();
             iter != accounts.end();
             ++iter)
            delete *iter;
    }
} ;
#endif	/* _CUSTOMER_H */

