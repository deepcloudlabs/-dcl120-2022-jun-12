test: BankApp.cpp Account.o Customer.o Bank.o SavingsAccount.o CheckingAccount.o OverdraftException.o CheckingAccountAdapter.o
	g++ -o test BankApp.cpp Account.o Customer.o Bank.o CheckingAccount.o CheckingAccountAdapter.o SavingsAccount.o OverdraftException.o

Account.o: Account.cpp
	g++ -c Account.cpp

CheckingAccountAdapter.o: CheckingAccountAdapter.cpp CheckingAccountAdapter.h CheckingAccount.o
	g++ -c CheckingAccountAdapter.cpp

CheckingAccount.o: CheckingAccount.cpp
	g++ -c CheckingAccount.cpp

SavingsAccount.o: SavingsAccount.cpp
	g++ -c SavingsAccount.cpp

Bank.o: Bank.cpp
	g++ -c Bank.cpp

Customer.o: Customer.cpp
	g++ -c Customer.cpp

OverdraftException.o: OverdraftException.cpp
	g++ -c OverdraftException.cpp

clean:
	rm *.o test
