#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>

void exit_function();

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

std::string	PhoneBook::readInput(const std::string& prompt) {
	std::string input;

	std::cout << prompt;
	if (!std::getline(std::cin, input))
		exit_function();
	if (std::cin.eof())
		exit_function();
	if (input == "")
		std::cout << "Given information field can't be empty" << std::endl;
	return (input);
}

void	PhoneBook::addContact(PhoneBook& pb, size_t& i) {
	std::string	first_name = readInput("First name: ");
	std::string	last_name = readInput("Last name: ");
	std::string	nickname = readInput("Nickname: ");
	std::string	phone_number = readInput("Phone number: ");
	std::string	darkest_secret = readInput("Darkest secret: ");
	std::cout << std::endl;
	pb.setContact(i, Contact(first_name, last_name, nickname, phone_number, darkest_secret));
	i = (i + 1) % 8;
}
