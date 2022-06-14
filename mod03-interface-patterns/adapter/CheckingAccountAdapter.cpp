#include "CheckingAccountAdapter.h"

void CheckingAccountAdapter::withdraw(double amt) {
     if (!checkingAccount->paraCek(amt))
        throw new OverdraftException("Insufficient balance",amt-checkingAccount->krediIncele()-checkingAccount->bakiyeIncele());
}

bool CheckingAccountAdapter::deposit(double amt) {
     checkingAccount->paraYatir(amt);
     return true;
}
