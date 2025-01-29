#include "contact.hpp"
#include <iostream>
#include <string>


void	Contact::setIndex(int i)
{
	id = i;
}

void Contact::printInfo() {
    
	std::string idStr = std::to_string(id);
	std::cout.width(10); std::cout << std::right << idStr << '|';
	std::cout.width(10); std::cout << std::right << name << '|';
	std::cout.width(10); std::cout << std::right << nickname << '|';
	std::cout.width(10); std::cout << std::right << surname << '|';
}

void Contact::printAll() {
    std::cout << "ID:          "      << id         << "\n"
              << "Name:        "      << name       << "\n"
              << "Nickname:    "      << nickname   << "\n"
              << "Surname:     "      << surname    << "\n"
              << "Secret:      "      << secret     << "\n"
              << "PhoneNumber: "      << phonenumber << "\n";
}


Contact::Contact()
{

}


Contact::Contact(std::string name, std::string surname, std::string nickname, std::string phonenumber, std::string secret, int len)
{
	this->id = len;
	this->name = name;
	this->secret = secret;
	this->phonenumber = phonenumber;
	this->nickname = nickname;
	this->surname = surname;
}
