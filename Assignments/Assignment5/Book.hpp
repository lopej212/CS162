/**************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Book.hpp
 **************************************/

#ifndef BOOK_HPP
#define BOOK_HPP

#include "LibraryItem.hpp"
#include <string>

class Book: public LibraryItem
{
   private:
      std::string author;

   public:
      static const int CHECK_OUT_LENGTH =21;
      Book(std::string id_B, std::string title_B, std::string author_b): LibraryItem(id_B,title_B){author = author_b;}
      std::string getAuthor();
      int getCheckOutLength();

};

#endif
