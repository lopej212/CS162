/* Jose Manuel Lopez Alcala
 * point.cpp
 * Assignment 2
 * */

#include "point.hpp"
#include <math.h>

/*******************************
 * Description: This constructor will 
 * 		create a point with x and y coordiante
 */
Point::Point( double x, double y) 
{
   xCoordinate = x;
   yCoordinate = y;
}
/*********************************
 * Description: This is the defaul constructor  that will create 
 * 		x and y coordinate with values of zero. 
 */
Point::Point()
{
   xCoordinate = 0;
   yCoordinate = 0;
}

double Point::xget()
{
   return xCoordinate;
}

double Point::yget()
{
   return yCoordinate;
}
/************************************
 * Description: This fucntion will find the distance from the first 
 * 		point to the second point and return the value of the 
 * 		distance.
 */
double Point::distanceTo( Point p2)
{
  double distance;
  double x2 = p2.xget();
  double y2 = p2.yget();

  distance = sqrt(pow(x2-xCoordinate,2) + pow(y2-yCoordinate,2));

  return distance;
}

