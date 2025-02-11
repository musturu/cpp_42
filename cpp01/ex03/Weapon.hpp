#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>


class Weapon {
    public:
        // Canonical form
    Weapon(std::string str);
    Weapon();
    const std::string getType();
    void setType(std::string wpn);

    private:
    std::string type;
        // Add private members here
};

#endif