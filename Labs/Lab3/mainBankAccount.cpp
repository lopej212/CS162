
#include "BankAccount.hpp"
#include <iostream>
#include <string>
int main ()
{

BankAccount account1("Harry Potter", "K437", 100.50);
string name = account1.getName();
string ID = account1.getID();
double balance = account1.getBalance();
cout<< "Account Name: " << name << endl;
cout << "Account ID: " << ID << endl;
cout << "Initial Balance: " << balance << endl;
account1.withdraw(50.5);
account1.deposit(25.2);
account1.withdraw(1000);
account1.deposit(500);

double finalBalance = account1.getBalance();
cout << "Balance: " << finalBalance << endl;

return 0;

}
