/* 
 * File:   CheckingAccount.h
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 7:51 PM
 */

#include "Account.h"


#ifndef _CHECKINGACCOUNT_H
#define	_CHECKINGACCOUNT_H
class CheckingAccount {
private:
    double kredi;
    double bakiye;
public:
    CheckingAccount(double bakiye){
        this->bakiye= bakiye;
    }
    CheckingAccount(double bakiye,double kredi){
        this->bakiye= bakiye;
        this->kredi= kredi;
    }
    double bakiyeIncele(){
	    return bakiye;
    }
    double krediIncele(){
	    return kredi;
    }
    bool paraCek(double miktar) ;
    bool paraYatir(double miktar) ;
};
#endif	/* _CHECKINGACCOUNT_H */

