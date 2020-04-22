/************************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Movie.cpp
 ***********************************************/

#include "Movie.hpp"

/****************************************
 * Description:
 * This function will return the director
 * of a movie as a string.
 ***************************************/
std::string Movie::getDirector()
{
   return director;
}

/***************************************
 * Description:
 * This function will return the max check
 * out length of the movie as in int.
 ***************************************/
int Movie::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}

