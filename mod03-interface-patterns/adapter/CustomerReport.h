/* 
 * File:   CustomerReport.h
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 10:02 PM
 */
#include "Bank.h"

#ifndef _CUSTOMERREPORT_H
#define	_CUSTOMERREPORT_H
class CustomerReport {
private:
    Bank *bank;
public:
    CustomerReport() {
        bank= new Bank();
    }
    
    Bank* getBank() {
        return bank;
    }
    
    void setBank(Bank *bank) {
        this->bank = bank;
    }
    
    void generateReport() const ;
};
#endif	/* _CUSTOMERREPORT_H */

