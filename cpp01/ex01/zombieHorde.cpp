#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zh = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zh[i].SetName(name);
	}
	return (zh);
}
