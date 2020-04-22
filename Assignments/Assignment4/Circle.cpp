/*****************************************
 * Author: Jose Manuel Lopez Alcala
 * File: Circle.cpp
 * Assignment 4
 ****************************************/
#include "Circle.hpp" 
/*********************************
 * Description: 
 * This fucntion will set the radius of the 
 * cirlce object.
 *********************************/ 
void Circle::setRadius(double  r)
{
   radius = r;
}
/*********************************
 * Description: 
 * This is a circle constructor that will create
 * a circle of radius r
 *********************************/
 Circle::Circle( double r)
{
   setRadius( r);
}
/*********************************
 * Description:
 * This function will return the area of
 * a circle object.
 *********************************/
double Circle::Area()
{
   return ( (3.1415926)*(radius)*(radius));
}
/**************************************
 * Description: 
 * This function will return the perimeter of the 
 * circle. More specifically it will return the circumference.
 *************************************/
double Circle::Perimeter()
{
   return ( 2*(3.1415926)* radius);
}



