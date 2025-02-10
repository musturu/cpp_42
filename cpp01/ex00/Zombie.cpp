#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(const Zombie &other) {
    *this = other;
}

Zombie::~Zombie() {
    std::cout << "Deconstructed->" << this->name << std::endl;
}

Zombie &Zombie::operator=(const Zombie &other) {
    if (this != &other) {
        // Copy members here
    }
    return *this;
}
