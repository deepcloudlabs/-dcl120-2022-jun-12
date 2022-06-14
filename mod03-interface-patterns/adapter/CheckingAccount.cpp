#include "CheckingAccount.h"

bool CheckingAccount::paraYatir(double miktar) {        
     bakiye += miktar;
     return true;
}

bool CheckingAccount::paraCek(double miktar) {        
        if ( bakiye < miktar ) {
            
            // Not enough bakiye to cover the miktar requested to withdraw
            // Check if there is enough in the overdraft protection (if any)
            double overdraftNeeded = miktar - bakiye;
            if ( kredi < overdraftNeeded ) {                
                // No overdraft protection or not enough to cover the miktar needed
                return false; 
            } else {                
                // Yes, there is overdraft protection and enough to cover the miktar
                bakiye -= overdraftNeeded;
            }            
        } else {            
            // Yes, there is enough bakiye to cover the miktar
            // Proceed as usual
            bakiye = bakiye - miktar;
        }
        return true;
}
