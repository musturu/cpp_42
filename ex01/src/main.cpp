#include "contact.hpp"
#include "phonebook.hpp"
#include <cstdio>
#include <string>
#include <iostream>

int main() 
{
	std::string input;
	Phonebook	pb = Phonebook();

	std::cout << "Lmoricon's Phonebook, insert your first Contact with \"ADD\"\n";
	while (1)
	{
		std::cout << ":";
		std::cin >> input;
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Please enter a valid command [ADD|SEARCH|EXIT]\n";
		input = "";
	}
}
