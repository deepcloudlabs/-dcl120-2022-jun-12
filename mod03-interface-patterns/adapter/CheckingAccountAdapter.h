/* 
 * File:   CheckingAccountAdapter.h
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 7:51 PM
 */

#include "Account.h"
#include "CheckingAccount.h"
#include "OverdraftException.h"


#ifndef _CHECKINGACCOUNTADAPTER_H
#define	_CHECKINGACCOUNTADAPTER_H
class CheckingAccountAdapter : public Account {
private:
    CheckingAccount *checkingAccount;
public:
    CheckingAccountAdapter(double bakiye) : Account(0) {
        checkingAccount= new CheckingAccount(bakiye);
    }
    CheckingAccountAdapter(double bakiye,double kredi) : Account(0){
        checkingAccount= new CheckingAccount(bakiye,kredi);
    }
    virtual double getBalance(){
        return checkingAccount->bakiyeIncele();
    }
    virtual bool deposit(double amt);
    virtual void withdraw(double amt) ;
    ~CheckingAccountAdapter(){
      delete checkingAccount;
   }
};
#endif	/* _CHECKINGACCOUNTADAPTER_H */

