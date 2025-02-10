#include "contact.hpp"
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__


class Phonebook {

private:
	int			len;
	Contact		contacs[8];

public:
	int			Len();
	void		add();
	void		search();
	Phonebook();
};

#endif