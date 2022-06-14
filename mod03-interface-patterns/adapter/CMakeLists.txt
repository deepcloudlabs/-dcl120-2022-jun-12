project(adapter)

add_executable(adapter BankApp.cpp Bank.h Bank.cpp Account.h Account.cpp CheckingAccount.h CheckingAccount.cpp CheckingAccountAdapter.h CheckingAccountAdapter.cpp CustomerReport.h Customer.h Customer.cpp)