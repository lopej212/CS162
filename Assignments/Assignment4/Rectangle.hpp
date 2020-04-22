/*****************************************
 * Author: Jose Manuel Lopez Alcala
 * Assignment 4
 * File: Rectangle.hpp
 *****************************************/

#ifndef RECTANGLE_H	
#define RECTANGLE_H

#include "Shape.hpp"

class Rectangle : public Shape
{
   //The following two member variables are protected
   //becuase they have to be accesed by the 
   //Derived Square class
   protected: 
      double length;
      double width;

   public: 
      virtual void setLength(double l);
      virtual void setWidth(double w);
      Rectangle( double l, double w);
      virtual double Area();
      virtual double Perimeter();

};

#endif
