/***********************************************
 * Autho: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Album.cpp
 ***********************************************/

#include "Album.hpp"
//#include <string>// for testing 
/*****************************
 * Description: 
 * This function will return the artist
 * of an album object
 *****************************/
std::string Album::getArtist()
{
   return artist;
}

/*******************************
 * Description: 
 * This function will return the 
 * check out lenght of an album object
 ******************************/
int Album::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}

/*
//This is just for testing 
Album(std::string id_A, std::string title_A, std::string artist_A)
{
   artist = artist_A;
}
*/
