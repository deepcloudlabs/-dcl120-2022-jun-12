/* 
 * File:   Account.h
 * Author: binnur.kurt
 *
 * Created on November 7, 2008, 3:12 PM
 */
#include "OverdraftException.h"
#ifndef _ACCOUNT_H
#define	_ACCOUNT_H
class Account {
private:

protected:
    double balance;
    Account(double balance){
       Account::balance= balance;
    }
public:
    virtual double getBalance(){
        return balance;
    }
    virtual bool deposit(double amt);
    virtual void withdraw(double amt) ;
    virtual  ~Account(){}
};
#endif	/* _ACCOUNT_H */

