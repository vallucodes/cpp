#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {}
// PhoneBook::~PhoneBook() {}

bool	PhoneBook::isContactSet(int index) const {
	return (contacts[index].isSet());
}

const	Contact& PhoneBook::getContact(int index) const {
	return (contacts[index]);
}

void	PhoneBook::setContact(int index, const Contact& contact) {
	contacts[index] = contact;
}
