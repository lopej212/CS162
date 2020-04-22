/* Jose Manuel Lopez Alcala
 * FILE NAME: IntegerSet.hpp
 */
#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>
class IntegerSet
{
   private: 
      int *ptr;
      int array_size;
      int numbers_inSet;

   public:
      IntegerSet();
      IntegerSet(const IntegerSet &number_set);
      IntegerSet& operator=(const IntegerSet &right);
      ~IntegerSet();
      int size();
      bool isEmpty();
      bool contains(int value);
      void add(int a);
      void remove(int r);
      void print();
      std::vector<int> getAsVector();
      IntegerSet operator+(IntegerSet set2);
      IntegerSet operator*(IntegerSet set2);
      IntegerSet operator/(IntegerSet set2);
      

    
};

#endif

