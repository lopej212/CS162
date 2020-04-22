#ifndef NUMCONTAINER_H
#define NUMCONTAINER_H

class NumContainer
{
   private:
      double *ptr;
      int size;
   public: 
      NumContainer(int size);
      void fillArray();
      double arraySum();
      ~NumContainer();
};

#endif
