#include "Zombie.hpp"
#include "Zombie.h"

int main()
{
    Zombie *heapz;
    Zombie stackz("StackZomb");

    stackz.announce();
    heapz = newZombie("Lezomb");
    heapz->announce();
    randomChump("HeapZombinDifferentScopeZomb");
    delete(heapz);
}