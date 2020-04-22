/************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * File: LibraryItem.cpp
 ***********************/

#include "LibraryItem.hpp"
#include <string> 
/***********************************************************
 * Description: 
 * This function is the constructor of the libraItem class. 
 * The pararmeters it takes are  strings for id and title. It
 * sets teh idCode to idc and title to t. It also sets checkedoutby 
 * and requestedBy to NULL.The location is set to on_shelf.
 ***********************************************************/
LibraryItem::LibraryItem(std::string idc, std::string t)
{
   idCode = idc;
   title = t;
   checkedOutBy = NULL;
   requestedBy = NULL;
   location = ON_SHELF;

}

/******************************************
 * Desription:
 * This function will return the ID of the 
 * library item as a string.
 *****************************************/
std::string LibraryItem::getIdCode()
{
   return idCode;
}

/****************************************
 * Description:
 * This functionwill return the title of the 
 * library item as a string.
 ***************************************/
std::string LibraryItem::getTitle()
{
   return title;
}

/*****************************************
 * Description:
 * This function will return the location 
 * of the library item. The return type is 
 * locale; this is from the enum list.
 ****************************************/
Locale LibraryItem::getLocation()
{
   return location;
}

/*****************************************
 * Description:
 * This function sets the location of the 
 * library object. The parameter is the lcoation
 ****************************************/
void LibraryItem::setLocation(Locale l)
{
   location = l;
}

/*******************************************
 * Description:
 * This function will return pointer to the patron
 * that has checked out the library item. 
 ******************************************/
Patron* LibraryItem::getCheckedOutBy()
{
   return checkedOutBy;
}

/**********************************************
 * Description:
 * This function will point the patron pointer to 
 * point to the patron parameter passed.
 **********************************************/
void LibraryItem::setCheckedOutBy(Patron* p)
{
   checkedOutBy = p;
}

/***********************************************
 * Description:
 * This function will return the patron pointer to 
 * which a item got requested to.
 **********************************************/
Patron* LibraryItem::getRequestedBy()
{
   return requestedBy;
}

/***********************************************
 * Description:
 * This function will set the requested patron pointer 
 * to point to the pointer being passed to the function.
 ***********************************************/
void LibraryItem::setRequestedBy(Patron* p)
{
   requestedBy = p;
}

/**************************************************
 * Description:
 * This function will return the date that it got checked 
 * out as an int.
 *************************************************/
int LibraryItem::getDateCheckedOut()
{
   return dateCheckedOut;
}

/****************************************************
 * Description:
 * This function will set the date that an item got
 * check out on. 
 ***************************************************/
void LibraryItem::setDateCheckedOut(int d)
{
   dateCheckedOut = d;
}



