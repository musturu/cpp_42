#include "HumanB.hpp"


void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->wpn.getType() << std::endl;
}


HumanB::HumanB(std::string name)
{
    Weapon wpn("bare fists");

    this->name = name;
    this->wpn = wpn;
}

HumanB::HumanB(std::string name, Weapon wpn)
{
    this->name = name;
    this->wpn = wpn;
}

void    HumanB::setWeapon(Weapon wpn){
    this->wpn = wpn;
}