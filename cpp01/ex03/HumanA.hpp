#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA {
    public:
    void    attack(void);
    void    setWeapon(Weapon wpn);
    HumanA(std::string name, Weapon &wpn);

    private:
    std::string name;
    Weapon      &wpn;

        // Add private members here
};

#endif
