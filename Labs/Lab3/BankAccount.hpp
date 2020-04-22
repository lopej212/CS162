/* CS162 Lab3 
 * Jose Manuel Lopez Alcala
 * Week 3
 *  */ 

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount
{
private:
   string customerName;
   string customerID;
  double customerBalance; 

public:
  BankAccount(string name,string ID, double balance);
  string getName();
  string getID();
  double getBalance();
  void withdraw(double x);
  void deposit(double n);
};

#endif
