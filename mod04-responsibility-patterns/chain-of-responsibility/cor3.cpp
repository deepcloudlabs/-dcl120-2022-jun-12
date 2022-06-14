#include <iostream>

using namespace std;

class Loan {
   private:
      int amount;
   public:
      Loan(int amount){
            this->amount = amount;
      }
      int getAmount() const {
            return amount;
      }
};

class LoanApprover{
    protected:
        LoanApprover* nextApprover;
    public:
        void setNextApprover(LoanApprover* nextApprover){
            this->nextApprover = nextApprover;
        }
        virtual bool approve(const Loan& loan)=0;
};

class Manager : public LoanApprover {
   public:
       bool approve(const Loan& loan) {
            if (loan.getAmount() <= 100000){
                cout << "Approved by the manager!" << endl ;
                return true; 
            }
            return nextApprover->approve(loan);
        }
};

class Director : public LoanApprover {
   public:
       bool approve(const Loan& loan) {
            if (loan.getAmount() <= 250000){
                cout << "Approved by the director!" << endl ;
                return true;
            } 
            return nextApprover->approve(loan);
        }
};


class VicePresident : public LoanApprover {
   public:
       bool approve(const Loan& loan) {
            cout << "Approved by the vice president!" << endl ;
            return loan.getAmount() <= 1000000;
       }
};


int main(){
    Loan loan1(  20000);
    Loan loan2( 200000);
    Loan loan3(1500000);
    LoanApprover* a = new Manager();
    LoanApprover* b = new Director();
    LoanApprover* c = new VicePresident();
    a->setNextApprover(b);
    b->setNextApprover(c);
    a->approve(loan1);  //this will be approved by the manager
    a->approve(loan2);  //this will be approved by the director
    a->approve(loan3);  //this will be approved by the vice president
}


