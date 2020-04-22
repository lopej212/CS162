//Jose Manuel Lopez Alcala
// lab 7 
// RegularProject.hpp
#ifndef REGULAR_PROEJCT_H
#define REGULAR_PROJECT_H

#include "CustomerProject.hpp"
class RegularProject: public CustomerProject
{
   public:
      RegularProject(double h, double m , double t) : CustomerProject( h,m,t){}
      double billAmount();

};

#endif
