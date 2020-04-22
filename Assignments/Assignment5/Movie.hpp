/****************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5 
 * File: Movie.hpp
 ***************************************/

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "LibraryItem.hpp"
#include <string> 

class Movie: public LibraryItem
{
   private:
      std::string director;
   public:
      static const int CHECK_OUT_LENGTH = 7;
      Movie(std::string id_M, std::string title_M, std::string director_M):LibraryItem(id_M, title_M){director = director_M;}
      std::string getDirector();
      int getCheckOutLength();

};

#endif
