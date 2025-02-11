#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->wpn.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &wpn) : wpn(wpn)
{
    this->name = name;
}

void    HumanA::setWeapon(Weapon wpn){
    this->wpn = wpn;
}