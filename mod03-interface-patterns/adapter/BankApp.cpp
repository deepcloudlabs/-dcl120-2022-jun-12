/* 
 * File:   BankApp.cpp
 * Author: binnur.kurt
 *
 * Created on November 9, 2008, 9:42 PM
 */

#include <iostream>
using namespace std;

#include "Account.h"
#include "Bank.h"
#include "Customer.h"
#include "SavingsAccount.h"
#include "CheckingAccountAdapter.h"
#include "OverdraftException.h"
vector<Customer*> Bank::customers;

/*
 * 
 */
int main(int argc, char** argv) {
        Customer *customer;
        Account  *account;
        // Create two customers and their accounts
        Bank::addCustomer("Jack", "Shephard");
        customer = Bank::getCustomer(0);
        customer->addAccount(new SavingsAccount(500.00, 0.05));
        customer->addAccount(new CheckingAccountAdapter(200.00, 500.00));
        Bank::addCustomer("Kate", "Austen");
        customer = Bank::getCustomer(1);
        customer->addAccount(new SavingsAccount(200.00, 0.03));
        Bank::addCustomer("Ben", "Linus");
        customer = Bank::getCustomer(2);
        customer->addAccount(new SavingsAccount(20000.00, 0.03));
        // Test the checking account of Jane Simms (with overdraft protection)
        customer = Bank::getCustomer(0);
        account = customer->getAccount(1);
        cout << endl << "Customer [" << customer->getLastName()
        << ", " << customer->getFirstName() << "]"
                << " has a checking balance of "
                << account->getBalance()
                << " with a 500.00 overdraft protection.";
        try {
            cout << endl << "Checking Acct [Jack Shephard] : withdraw 150.00";
            account->withdraw(150.00);
            cout << endl << "Checking Acct [Jack Shephard] : deposit 22.50";
            account->deposit(22.50);
            cout << endl << "Checking Acct [Jack Shephard] : withdraw 147.62";
            account->withdraw(147.62);
            cout << endl << "Checking Acct [Jack Shephard] : withdraw 370.00";
            account->withdraw(170.00);
        } catch (OverdraftException e1) {
            cout << endl << "Exception: " << e1.what()
            << "   Deficit: " << e1.getDeficit();
        } 
        
        cout << endl << "Customer [" << customer->getLastName()
        << ", " << customer->getFirstName() << "]"
                << " has a checking balance of "
                << account->getBalance();
        
        cout << endl ;
        
        // Test the checking account of Owen Bryant (without overdraft protection)
        customer = Bank::getCustomer(1);
        account = customer->getAccount(0);
        cout << endl << "Customer [" << customer->getLastName()
        << ", " << customer->getFirstName() << "]"
                << " has a savings balance of "
                << account->getBalance();
        try {
            cout << endl << "Savings Acct [Kate Austen] : withdraw 100.00";
            account->withdraw(100.00);
            cout << endl << "Savings Acct [Kate Austen] : deposit 25.00";
            account->deposit(25.00);
            cout << endl << "Savings Acct [Kate Austen] : withdraw 175.00";
            account->withdraw(175.00);
        } catch (OverdraftException e1) {
            cout << endl << "Exception: " << e1.what()
            << "   Deficit: " << e1.getDeficit();
        } 

        cout << endl << "Customer [" << customer->getLastName()
        << ", " << customer->getFirstName() << "]"
                << " has a savings balance of "
                << account->getBalance()
				<< endl ;
        
		Bank::reportCustomers();
    return (EXIT_SUCCESS);
}

