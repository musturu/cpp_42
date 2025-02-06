#include "contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


std::string Contact::getName()
{
	return (name);
}

void	Contact::setIndex(int i)
{
	id = i;
}
std::string truncateString(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void Contact::printInfo() {

	std::cout.width(10); std::cout << std::right << id << '|';
	std::cout.width(10); std::cout << std::right << truncateString(name) << '|';
	std::cout.width(10); std::cout << std::right << truncateString(nickname) << '|';
	std::cout.width(10); std::cout << std::right << truncateString(surname);
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
