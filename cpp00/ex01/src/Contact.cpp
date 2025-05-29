#include "Contact.hpp"
#include "Phonebook.hpp"
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
