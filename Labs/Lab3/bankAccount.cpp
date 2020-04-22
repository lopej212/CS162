#include <iostream>
#include "BankAccount.hpp"
#include <string>
BankAccount::BankAccount(std::string name, std::string ID, double balance)
{
   customerName = name;
   customerID = ID;
   customerBalance = balance;
}

std::string BankAccount::getName()
{
   return customerName;
}

std::string BankAccount::getID()
{
   return customerID;
}

double BankAccount::getBalance()
{
   return customerBalance;
}

void BankAccount::withdraw(double x)
{
   customerBalance -= x;
}

void BankAccount::deposit(double n)
{
   customerBalance += n;
}




