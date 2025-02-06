#include "phonebook.hpp"
#include "contact.hpp"
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

Phonebook::Phonebook()
{
	len = 0;
}

void Phonebook::add()
{
	std::cin.clear();
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;
	std::string dummy;

	if (this->len == 7)
		std::cout << "Warning: you're about to ovewrite " << this->contacs[this->len-1].getName() << std::endl;
	std::cout << "enter NAME:";
	std::cin >> name;
	std::cout << "enter SURNAME:";
	std::cin >> surname;
	std::cout << "enter NICKNAME:";
	std::cin >> nickname;
	std::cout << "enter PHONE NUMBER:";
	std::cin >> phonenumber;
	std::cout << "enter DARK SECRET:";
	std::cin >> secret;
	for (int i = len; i >= 1; i--)
	{
		contacs[i] = contacs[i - 1];
		contacs[i].setIndex(i);
	}
	contacs[0] = Contact(name, surname, nickname, phonenumber, secret, len);
	contacs[0].setIndex(0);
	if (len != 7)
		len++;
	std::getline(std::cin, dummy);
}


void Phonebook::search()
{
	std::string	indexstr;
	int			index;
	std::string dummy;

	std::cout.width(10); std::cout << std::right << "ID" << '|';
	std::cout.width(10); std::cout << std::right << "NAME" << '|';
	std::cout.width(10); std::cout << std::right << "NICKNAME" << '|';
	std::cout.width(10); std::cout << std::right << "SURNAME" << "|\n";
	for (int i = 0; i < len; i++)
	{
		contacs[i].printInfo();
		std::cout << "|\n";
	}

	std::cout << "enter INDEX:";
	std::cin >> indexstr;

	index = std::atoi(indexstr.c_str());
	if (index < len && isdigit(indexstr[0]))
		contacs[index].printAll();
	else
		std::cout << "INVALID INDEX\n";
	std::getline(std::cin, dummy);
	std::cin.clear();
}
