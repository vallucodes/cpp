#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

bool	is_valid(std::string input, PhoneBook pb)
{
	int	index;

	if (input.length() != 1)
		return (false);
	if (input[0] < '1' || input[0] > '8')
		return (false);
	index = std::stoi(input);
	if (pb.contacts[index - 1].is_set == 0)
		return (false);
	return (true);
}

void	display_requested_contact(std::string input, PhoneBook pb)
{
	int	index;

	index = std::stoi(input) - 1;
	std::cout << "First name: ";
	std::cout << pb.contacts[index].first_name << std::endl;
	std::cout << "Last name: ";
	std::cout << pb.contacts[index].last_name << std::endl;
	std::cout << "Nickname: ";
	std::cout << pb.contacts[index].nickname << std::endl;
	std::cout << "Phone numnber: ";
	std::cout << pb.contacts[index].phone_number << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << pb.contacts[index].darkest_secret << std::endl;
}
std::string	format_field(std::string field)
{
	if (field.length() > 10)
		field = field.substr(0, 9) + ".";
	return (field);
}

void	display_current_table(PhoneBook pb) {
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << " | " <<
	std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (pb.contacts[i].is_set == false)
			break ;
		std::cout << std::setw(10) << (i + 1) << " | ";
		std::cout << std::setw(10) << format_field(pb.contacts[i].first_name) << " | ";
		std::cout << std::setw(10) << format_field(pb.contacts[i].last_name) << " | ";
		std::cout << std::setw(10) << format_field(pb.contacts[i].nickname) << " | " <<
		std::endl;
	}
}

void	search(PhoneBook pb) {
	std::string	input;

	display_current_table(pb);
	while (1)
	{
		std::cout << "Type index of contact to display contact information (or RETURN to go back): ";
		std::cin >> input;
		if (input == "RETURN")
			break ;
		if (!is_valid(input, pb))
		{
			std::cout << "Given index invalid.\n";
			continue ;
		}
		else
		{
			display_requested_contact(input, pb);
			break ;
		}
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
