#include "Account.h"
#include "OverdraftException.h"

bool Account::deposit(double amt){
    balance+= amt;
    return true;
}

void Account::withdraw(double amt) {
    if (amt>balance)
       throw OverdraftException("Balance does not cover amount",amt-balance);
    balance=balance-amt;
}
