#include "Zombie.hpp"
#include "Zombie.h"



int main()
{
    Zombie *horde;
    int N;

    horde = zombieHorde(N, "MauroZombie");

    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie n: " << i << ": ";
        horde[i].announce();
    }
    delete[] horde;
}