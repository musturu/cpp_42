#include "contact.hpp"

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
