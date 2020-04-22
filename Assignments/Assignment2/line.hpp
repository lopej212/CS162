/* Jose Manuel Lopez Alcala
 * Assignment 2 Line Header 
 * File Name: line.hpp
 * */

#ifndef LINE_H
#define LINE_H
#include "point.hpp"

class Line
{
   private:
      Point point1;
      Point point2;

   public:


      class DegenerateLineException
      {
	 public:
	    bool same;
	    DegenerateLineException(bool s)
	    {
	       same = s;
	    }
      };
      
      class UndefinedSlopeException
      {
	 public:
	    bool undefined;
	    UndefinedSlopeException(bool u)
	    {
	       undefined = u;
	    }

      };

      class ParallelLinesException
      {
	 public:
	   bool parallel;
	  ParallelLinesException(bool p)
	  {
	    parallel = p;
	  }
      };
      Point getPoint1();
      Point getPoint2();
      Line( Point p1, Point p2);
      double slope();
      Point intersectWith(Line l);
};

#endif
