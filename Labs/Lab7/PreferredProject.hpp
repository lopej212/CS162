//Jose Manuel Lopez Alcala
//lab 7 
//PreferredProject.hpp

#ifndef PREFERRED_PROEJECT_H
#define PREFERRED_PROJECT_H
#include "CustomerProject.hpp"
class PreferredProject: public CustomerProject
{
   public:
      PreferredProject(double h , double m, double t): CustomerProject(h,m,t){}

      double billAmount();
};

#endif
