#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

Contact::Contact(std::string fname, std::string lname, std::string nname,
				std::string pnum, std::string secret)
{
	this->first_name = fname;
	this->last_name = lname;
	this->nickname = nname;
	this->phone_number = pnum;
	this->darkest_secret = secret;
	this->is_set = true;
}


Contact::Contact() : is_set(false) {}

bool	Contact::isSet() const {
	return (is_set);
}

std::string	Contact::getFirstName() const {
	return (first_name);
}

std::string	Contact::getLastName() const {
	return (last_name);
}

std::string	Contact::getNickname() const {
	return (nickname);
}

std::string	Contact::getPhoneNumber() const {
	return (phone_number);
}

std::string	Contact::getDarkestSecret() const {
	return (darkest_secret);
}
