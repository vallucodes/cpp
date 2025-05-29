#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
class Contact
{
	public:
		Contact() : is_set(false) {};
		Contact(std::string fname, std::string lname, std::string nname,
				std::string pnum, std::string secret);
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		bool		is_set;
		// ~Contact();
};
class PhoneBook
{
	public:
		Contact contacts[8];
		PhoneBook();
		// ~PhoneBook();
};

#endif
