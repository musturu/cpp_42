#include "Zombie.hpp"
#include "Zombie.h"

void randomChump( std::string name )
{
    Zombie *z;
    z = newZombie(name);
    z->announce();
    delete(z);
}