/******************************************
 * Author: Jose Manuel Lopez Alcala
 * Assigment 4
 * File: Square.hpp
 *****************************************/
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.hpp"
class Square : public Rectangle 
{
   public: 
      Square( double s): Rectangle(s,s){}//This will call the Rectangle constructor
      void setLength(double l);
      void setWidth(double w);

};

#endif

