#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>



void	search(PhoneBook pb) {
	for (int i = 0; i < 8; i++)
	{
		if (pb.contacts[i].is_set == false)
			break ;
		std::cout << std::setw(10) << i << " | ";
		std::cout << std::setw(10) << pb.contacts[i].first_name << " | ";
		std::cout << std::setw(10) << pb.contacts[i].last_name << " | ";
		std::cout << std::setw(10) << pb.contacts[i].nickname << " | " <<
		std::endl;
	}
}

void	add(PhoneBook& pb, size_t& i) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "phone_number: ";
	std::cin >> phone_number;
	std::cout << "darkest_secret: ";
	std::cin >> darkest_secret;
	pb.contacts[i] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	i = (i + 1) % 8;
}

int	main() {
	std::string	input;
	PhoneBook	pbook;
	size_t		i = 0;

	while (input != "EXIT")
	{
		std::cout << "New prompt: ";
		std::cin >> input;
		if (input == "add")
			add(pbook, i);
		else if (input == "sea")
			search(pbook);
	}
	return (0);
}
