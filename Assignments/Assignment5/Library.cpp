/************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assigment 5
 * File: Library.cpp
 ***********************/

#include "Library.hpp"
#include "LibraryItem.hpp"
#include "Patron.hpp"
#include <vector>
#include <string>

/*******************************************************
 * Description: 
 * This is the constructor for the 
 * Library class. It sets the current date to zero
 *******************************************************/
Library::Library()
{
   currentDate = 0;
}

/********************************************************
 * Description:
 * This function will add an item to the library. 
 * The parameter has to be an library item
 *******************************************************/
void Library::addLibraryItem(LibraryItem* l)
{
   holdings.push_back(l);
}

/*******************************************************
 * Description:
 * This function will add a patron to the library. The parameter 
 * has to be a patron type. 
 *******************************************************/
void Library::addPatron(Patron* p)
{
   members.push_back(p);
}

/********************************************************
 * Description: 
 * This is function will return a string depending on the status of the 
 * return.The parameters are a string patron ID and a string item ID. If 
 * the item ID is not found, then it returns that the item was not found. 
 * If the patron was not found, then it returns item not found. If the item 
 * is checked out, then it returns that the item is checked out. If the item 
 * is on hold then, returns that the item is on hold. Otherwise, it carries out
 * the check out process and update the corresponding fields.
 ********************************************************/
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
   int holdings_index;
   int members_index;

   //This is the vector to find the item 
   //in the holdings vector 
   bool item_inLibrary = false;
   for( int i =0; i < holdings.size(); i++)
   {
      if(holdings.at(i)->getIdCode() == ItemID)
      {
	 item_inLibrary = true;
	 holdings_index = i;
	 break;
      }
   }

   if(item_inLibrary == false)
   {
      return "item not found";//if item not found 
   }

   //This is the for loop to find the patron 
   //in the members vector
   bool patron_inLibrary = false;
   for( int i =0; i < members.size(); i++)
   {
      if(members.at(i)->getIdNum() == patronID)
      {
	 patron_inLibrary = true;
	 members_index = i;
	 break;
      }
   }

   if(patron_inLibrary == false)
   {
      return "patron not found";//If patron not found
   }

   //The next check is to see if it checked out 
   //else if( (holdings.at(holdings_index))->getCheckedOutBy() != NULL)//This was the initial one 
   else if( (holdings.at(holdings_index))->getLocation() == CHECKED_OUT) 
   {
     return "item already checked out";
   }
   
   //The next check is to see if the item is on hold
   else if( (holdings.at(holdings_index))->getLocation() == ON_HOLD_SHELF)
   {
     return "item on hold by another patron";
   }

   else
   {
      (holdings.at(holdings_index))->setCheckedOutBy(members.at(members_index));//updates how checked out the item (LibraryItem's checkedOutBy
      (holdings.at(holdings_index))->setDateCheckedOut(currentDate);//updates dateCheckedOut
      (holdings.at(holdings_index))->setLocation(CHECKED_OUT);//update location

      if( (holdings.at(holdings_index))->getRequestedBy() == members.at(members_index) ) 
      {
	 holdings.at(holdings_index)->setRequestedBy(NULL);//set requestedBy to NULL if checker is the same 
      }

      members.at(members_index)->addLibraryItem( holdings.at(holdings_index) );//update patron's items 
     return "check out successful";
   }

}

/*****************************************************************************
 * Description: 
 * This function will be used to return a libray item. The parameter has to be a string 
 * of the item ( Item ID). This function will the following in the order listed: item in library,
 * if item already in the library.If neither of the previous statements are true, then it will return the 
 * item by upadating the patrons checked out items and return successfull. If the book is requested, then 
 * it will go on the requested shelf. 
 ****************************************************************************/
//Returning items to library function 
std::string Library::returnLibraryItem(std::string ItemID)
{
   int holdings_index;
   //This is the loop to find the item 
   //in the holdings vector 
   bool item_inLibrary = false;
   for( int i =0; i < holdings.size(); i++)
   {
      if(holdings.at(i)->getIdCode() == ItemID)
      {
	 item_inLibrary = true;
	 holdings_index = i;
	 break;
      }
   }

   //If item not in the library
   if(item_inLibrary == false)
   {
      return "item not found";//if item not found 
   }

   //The next check is to see if it is already in the library 
   else if( (holdings.at(holdings_index))->getLocation() == ON_SHELF)
   {
     return "item already in library";
   }

   else
   {
      //update patron's checkedOutItems
      ((holdings.at(holdings_index))->getCheckedOutBy())->removeLibraryItem(holdings.at(holdings_index));
      //Update location( shelf or hold)
      if(holdings.at(holdings_index)->getRequestedBy() != NULL)
      {
	 holdings.at(holdings_index)->setLocation(ON_HOLD_SHELF);// If requested, upon return it goes to hold shelf
      }else{
	 holdings.at(holdings_index)->setLocation(ON_SHELF);//If not requested, go to regualr shelf
      }
      //Update checkedOutBy
      holdings.at(holdings_index)->setCheckedOutBy(NULL);//points to null
      
      return "return successful";
   }
}

/********************************************************************************************
 * Description:
 * This function will set an item on request by a patron. It will check the followin in the order
 * listed: if the item is in the library, it the patron requesting is in the library, if the item 
 * is already requested.If it gets passed the previous checks, then it wil proceed to request the
 * item to the patron. It will update the corresponding fields and return request successful.
 ********************************************************************************************/
std::string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
   int holdings_index;
   //This is the loop to find the item 
   //in the holdings vector 
   bool item_inLibrary = false;
   for( int i =0; i < holdings.size(); i++)
   {
      if(holdings.at(i)->getIdCode() == ItemID)
      {
	 item_inLibrary = true;
	 holdings_index = i;
	 break;
      }
   }

   //If item not in the library
   if(item_inLibrary == false)
   {
      return "item not found";//if item not found 
   }



   //This is the for loop to find the patron 
   //in the members vector
   bool patron_inLibrary = false;
   int members_index;
   for( int i =0; i < members.size(); i++)
   {
      if(members.at(i)->getIdNum() == patronID)
      {
	 patron_inLibrary = true;
	 members_index = i;
	 break;
      }
   }

   if(patron_inLibrary == false)
   {
      return "patron not found";//If patron not found
   }

   
   //The next check is to see if it is on hold by someone 
   else if( ((holdings.at(holdings_index))->getRequestedBy() != NULL) || (holdings.at(holdings_index)->getLocation() == ON_HOLD_SHELF))//This will check if someone has it on hold or if it is on the hold shelf
   {
     return "item already on hold";
   }

   else
   {
      (holdings.at(holdings_index))->setRequestedBy(members.at(members_index));//upate LibraryItem's Requestdby

      if(holdings.at(holdings_index)->getLocation() == ON_SHELF)
      {
	 holdings.at(holdings_index)->setLocation(ON_HOLD_SHELF);//When requested move to shelf it is on regualr shelf
      }

      return "request successful";
   }
}

/****************************************************************************
 * Description:
 * This function will be used to pay the fine of the patron. It will make use
 * of the amend function. It will first check to see if the patron is in the 
 * library and then proceed to pay the fine.It will return payment successful
 * as confirmation as the payment. 
 **************************************************************************/
std::string Library::payFine(std::string patronID, double payment)
{

   //This is the for loop to find the patron 
   //in the members vector
   bool patron_inLibrary = false;
   int members_index;
   for( int i =0; i < members.size(); i++)
   {
      if(members.at(i)->getIdNum() == patronID)
      {
	 patron_inLibrary = true;
	 members_index = i;
	 break;
      }
   }

   if(patron_inLibrary == false)
   {
      return "patron not found";//If patron not found
   }

   //if the preceding "if" statment does not evaluate to true
   //then this following code will run
   members.at(members_index)->amendFine(payment);
   return "payment successful";
}

/*****************************************************
 * Description:
 * This function will add one to the current date and then 
 * increment the fines of the patrons whom have overdue items
 *******************************************************/
void Library::incrementCurrentDate()
{
   currentDate++;
   for(int i = 0 ;i < members.size();i++)
   {
      std::vector<LibraryItem*> items = members.at(i)->getCheckedOutItems();
      for(int j = 0; j < items.size(); j++)
      {
	 int out = items.at(j)->getDateCheckedOut();
	 int max_days = items.at(j)->getCheckOutLength();
	 int r_day= out + max_days;

	 if (currentDate >r_day)
	 {
	    members.at(i)->amendFine(0.10);
	 }
      }
   }
}

/*****************************************************
 * Description:
 * This function will return a patron pointer. The parameter will be 
 * the patron ID being used to look for patron object. 
 ****************************************************/
Patron* Library::getPatron(std::string patronID)
{

   //This is the for loop to find the patron 
   //in the members vector
   for( int i =0; i < members.size(); i++)
   {
      if(members.at(i)->getIdNum() == patronID)
      {
	 return members.at(i);
      }
   }

   //The follwing  return statement will execute
   //when the for loop does not find the patron 
   //in members vector
   return NULL;
}

/************************************************************
 * Description:
 * This function will return a libraryItem pointer.The parameter 
 * of the function is a item ID of the object that is being searched 
 * for.
 ************************************************************/
LibraryItem* Library::getLibraryItem(std::string ItemID)
{

   //This is the loop to find the item 
   //in the holdings vector 
   bool item_inLibrary = false;
   for( int i =0; i < holdings.size(); i++)
   {
      if(holdings.at(i)->getIdCode() == ItemID)
      {
	 return holdings.at(i);
      }
   }

   //This return statement will run when 
   //the item does not exist in the holdings vector
   return NULL;
}

