/***********************************
 * Author: Jose Manuel Lopez Alcala
 * Assigment 4
 * File: Circle.hpp
 ***********************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp" 

class Circle : public Shape
{
   private: 
      double radius;

   public: 
      void setRadius( double r);
      Circle(double r);
      virtual double Area();
      virtual double Perimeter();

};

#endif
