/* 
 * File:   SavingsAccount.h
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 7:49 PM
 */
#include "Account.h"

#ifndef _SAVINGSACCOUNT_H
#define	_SAVINGSACCOUNT_H
class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(double initBalance,double interestRate):Account(initBalance){
        this->interestRate= interestRate;
    }
} ;
#endif	/* _SAVINGSACCOUNT_H */

