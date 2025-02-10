#include <string>
#ifndef __CONTACT_H__
#define __CONTACT_H__



class Contact {

private:
	int			id;
	std::string name;
	std::string nickname;
	std::string surname;
	std::string secret;
	std::string phonenumber;
public:

	//getter
	std::string getName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getSecretdark();
	int			getIndex();
	std::string getSurname();
	void		printInfo();
	void		printAll();

	void			setIndex(int i);
	//constructors
	Contact();
	Contact(std::string name, std::string surname, std::string nickname,
		 std::string phonenumber, std::string secret, int id);
};

#endif
