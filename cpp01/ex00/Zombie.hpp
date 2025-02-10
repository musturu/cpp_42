#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>
#include <iostream>


class Zombie {
    public:
        // Canonical form
        Zombie();
        Zombie(std::string name);
        Zombie* newZombie( std::string name );
        Zombie(const Zombie &other);
        ~Zombie();
        void announce(void);
        Zombie &operator=(const Zombie &other);

    private:
    std::string name;
        // Add private members here
};

#endif
