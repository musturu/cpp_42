#ifndef HUMANB_HPP
# define HUMANB_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanB {
    public:
    void    attack(void);
    void    setWeapon(Weapon wpn);
    HumanB(std::string name);
    HumanB(std::string name, Weapon wpn);

    private:
    std::string name;
    Weapon      wpn;

        // Add private members here
};

#endif
