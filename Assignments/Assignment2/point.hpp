/* Jose Manuel Lopez Alcala
 * point.hpp
 * Assignment2
 * */

#ifndef POINT_H
#define POINT_H

class Point
{
   private:
      double xCoordinate;
      double yCoordinate;

   public:
     Point(double x, double y);
     Point ();
     double xget();
     double yget();
     double distanceTo(Point p);
};

#endif

