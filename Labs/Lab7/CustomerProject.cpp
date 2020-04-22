//Jose Manuel Lopez Alcala
//lab 6 CustomerProject.cpp
//
#include "CustomerProject.hpp"
double CustomerProject::getHours()
{
   return hours;
}

double CustomerProject::getMaterials()
{
   return materials;
}

double CustomerProject::getTransportation()
{
   return transportation;
}

void CustomerProject::setHours( double h)
{
   hours = h;
}

void CustomerProject::setMaterials(double  m)
{
   materials = m;
}

void CustomerProject::setTransportation( double t)
{
   transportation = t;
}

CustomerProject::CustomerProject(double h, double m, double t)
{
   setHours(h);
   setMaterials(m);
   setTransportation(t);
}


