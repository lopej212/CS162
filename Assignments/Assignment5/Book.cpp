/****************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Book.cpp
 **************************************/
#include "Book.hpp"
/***********************
 * Description:
 * This function will returnt the author of the 
 * book object. 
 ************************/
std::string Book::getAuthor()
{
   return author;
}

/************************************
 * Description:
 * This function will return the book 
 * max check out length.
 ***********************************/
int Book::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}

