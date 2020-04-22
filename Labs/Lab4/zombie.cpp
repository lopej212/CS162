#include "zombie.hpp"
#include <string> 
#include <iostream>

int Zombie::zombieCount;
Zombie::Zombie(std::string n)
{
   Zombie::name = n;
   Zombie::zombieCount++;
   
}

void Zombie::speakZ()
{
   std::cout<< Zombie::name << " says brainss!" <<std::endl;
}

Zombie::~Zombie()
{
   zombieCount--;
}

