#include "phonebook.hpp"
#include "contact.hpp"
#include <cstdio>
#include <string>
#include <iostream>

Phonebook::Phonebook()
{
	len = 0;
}

void Phonebook::add()
{
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;

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
	if (len > 8)
		len = 8;
	for (int i = len; i >= 1; i--)
	{
		contacs[i] = contacs[i - 1];
	}
	contacs[0] = Contact(name, surname, nickname, phonenumber, secret, len);
	len++;
	contacs[0].printAll();
	/*printf("len=%s\n", len);*/
}

void Phonebook::search()
{
	int	index;

	for (int i = 0; i < len; i++)
	{
		contacs[i].printInfo();
	}

	std::cout << "\nenter INDEX:";
	std::cin >> index;

	if (index < len && index > 0)
		contacs[index].printAll();
	else
		std::cout << "INVALID INDEX\n";
}

