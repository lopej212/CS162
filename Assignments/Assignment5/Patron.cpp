/*************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Patron.cpp
 **************************************/

#include "Patron.hpp"
#include <vector>

/*******************************************************
 * Description:
 * This functin is the constructor of the patron class.
 * It sets idNum to idn, name of the patron to n. It also 
 * sets the new patron's fine amount to zero.
 ******************************************************/
Patron::Patron(std::string idn, std::string n)
{
   idNum = idn;
   name = n;
   fineAmount = 0.0;
}

/*********************************************************
 * Description:
 * This function will return the ID of the patron object as
 * a string.
 *********************************************************/
std::string Patron::getIdNum()
{
   return idNum;
}

/**********************************************************
 * Description:
 * This function will return the name of the patron object
 * and return it as a string
 **********************************************************/
std::string Patron::getName()
{
   return name;
}

/*********************************************************
 * Description:
 * This function will return the vector of LibraryItem pointers 
 * of the library items that the patron object has checked out.
 *********************************************************/
std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
   return checkedOutItems;
}

/*********************************************************
 * Description:
 * This function will add a LibraryItem pointer to the 
 * vector that holds the items that the patron has checked 
 * out.
 ********************************************************/
void Patron::addLibraryItem(LibraryItem* b)
{
   checkedOutItems.push_back(b);
}


/*********************************************************
 * Description:
 * This function will remove a library item pointer from 
 * the vector that holds the items that the patron has 
 * currently checke out. More specifically, it will search 
 * for the parameter that it is being passed. 
 ********************************************************/
void Patron::removeLibraryItem(LibraryItem* b)
{
   for(int i = 0; i < checkedOutItems.size();i++)
   {
      if (b == checkedOutItems.at(i))
      {
	 checkedOutItems.erase(checkedOutItems.begin()+i);
      }
   }
}


/*********************************************************
 * Description:
 * This function will return the amount that the patron 
 * owes to the library.This will be returned as a double.
 ********************************************************/
double Patron::getFineAmount()
{
   return fineAmount;
}

/*********************************************************
 * Description:
 * This function will increment or decrease the amount 
 * that the patron owes to the library. It add the parameter
 * to the fine. If the parameter is negative, it substracts;if
 * positive, it adds.
 ********************************************************/
void Patron::amendFine(double amount)
{
   fineAmount += amount;
}

