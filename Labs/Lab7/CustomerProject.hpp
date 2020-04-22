// Jose Manuel Lopez Alcala
// Lab 7

#ifndef CUSTOMER_PROJECT_H
#define CUSTOMER_PROEJECT_H

class CustomerProject
{
   protected: 
      double hours;
      double materials;
      double transportation;

   public:
      double getHours();
      double getMaterials();
      double getTransportation();

      void setHours(double h );
      void setMaterials(double m);
      void setTransportation(double t );

      virtual double billAmount=0;

      CustomerProject(double h, double m, double t);

};

#endif
