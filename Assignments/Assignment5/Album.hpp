/***********************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Album.hpp
 **********************************************/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "LibraryItem.hpp"
#include <string> 

class Album: public LibraryItem
{
   private:
      std::string artist;

   public:
      static const int CHECK_OUT_LENGTH = 14;
      Album(std::string id_A, std::string title_A, std::string artist_A) : LibraryItem(id_A, title_A){artist = artist_A;}
//      Album(std::string id_A, std::string title_A, std::string artist_A):LibraryItem(id_A, title_A){}// for testing 
      std::string getArtist();
      int getCheckOutLength();
};

#endif
