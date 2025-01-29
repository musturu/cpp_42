#include "contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

std::string formatField(const std::string& field) {
	std::cout << field;
    // If the field is longer than 10 characters, truncate and add a '.'
    if (field.size() > 10) {
        return field.substr(0, 9) + ".";
    }

    // Otherwise, right-align using stream manipulators
    std::ostringstream oss;
    oss << std::setw(10) << field;
    return oss.str();
}

void Contact::printInfo() {
    
	std::string idStr = std::to_string(id);
    std::cout
        << formatField(idStr)       << "|"
        << formatField(name) << "|"
        << formatField(surname) << "|"
        << formatField(nickname) << std::endl;
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
