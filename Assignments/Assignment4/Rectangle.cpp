/****************************
 * Author:Jose Manuel Lopez Alcala
 * Assignment 4
 * File: Rectangle.cpp
 ****************************/
#include "Rectangle.hpp"

/*****************************************
 * Description:
 * This function will set the value of the 
 * length of the rectangle
 ****************************************/
void Rectangle::setLength( double l)
{
   length = l;
}
/****************************************
 * Description:
 * This function will set the value of the 
 * width of the rectangle object
 ****************************************/ 
void Rectangle::setWidth(double w)
{
   width = w; 
}

/****************************************
 * Description:
 * This function will create a rectangle object with 
 * a length l and width w.
 ***************************************/ 
Rectangle::Rectangle( double l , double w)
{
   setLength(l);
   setWidth(w);
}
/*********************************************
 * Description: 
 * This function will return the area of the 
 * rectangle.
 ********************************************/ 
double Rectangle::Area()
{
   return( length * width);
}

/*******************************************
 * Description:
 * This function will return the perimeter of the 
 * rectangle.
 *******************************************/
 double Rectangle::Perimeter()
{
   return ( (2*length) + (2*width));
}

