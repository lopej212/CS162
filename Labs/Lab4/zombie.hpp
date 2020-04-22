#ifndef ZOMBIE_h
#define ZOMBIE_h

#include <string> 

class Zombie
{
   private: 
      std::string name;
   public: 
      static int zombieCount;
      Zombie(std::string n);
      void speakZ();
      ~Zombie();
};

#endif
