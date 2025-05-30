#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

void	exit_function() {
	std::cout << std::endl << "Exiting phonebook" << std::endl;
	exit(1);
}

std::string	format_field(std::string field) {
	if (field.length() > 10)
		field = field.substr(0, 9) + ".";
	return (field);
}

void	display_requested_contact(std::string input, PhoneBook pb) {
	int	index = std::stoi(input) - 1;
	const Contact& c = pb.getContact(index);

	std::cout << std::endl;
	std::cout << "First name: ";
	std::cout << c.getFirstName() << std::endl;
	std::cout << "Last name: ";
	std::cout << c.getLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << c.getNickname() << std::endl;
	std::cout << "Phone number: ";
	std::cout << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << c.getDarkestSecret() << std::endl << std::endl;;
}

bool	display_current_table(PhoneBook pb) {
	if (pb.isContactSet(0) == 0)
	{
		std::cout << std::endl << "It seems like there is no contacts in your phonebook, try adding some" << std::endl << std::endl;
		return (false);
	}
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << " | " << std::endl;
	std::cout << std::string(51, '-') << std::endl;
	for (int i = 0; i < 8; i++)
	{
		const Contact& c = pb.getContact(i);
		if (pb.isContactSet(i) == 0)
			break ;
		std::cout << std::setw(10) << (i + 1) << " | ";
		std::cout << std::setw(10) << format_field(c.getFirstName()) << " | ";
		std::cout << std::setw(10) << format_field(c.getLastName()) << " | ";
		std::cout << std::setw(10) << format_field(c.getNickname()) << " | " <<
		std::endl << std::endl;
	}
	return (true);
}

bool	is_valid(std::string input, PhoneBook pb) {
	int	index;

	if (input.length() != 1)
		return (false);
	if (input[0] < '1' || input[0] > '8')
		return (false);
	index = std::stoi(input) - 1;
	if (pb.isContactSet(index) == 0)
		return (false);
	return (true);
}

void	search_contact(PhoneBook pb) {
	std::string	input;

	if (!display_current_table(pb))
		return ;
	while (1)
	{
		std::cout << "Type index of contact to display contact information (or RETURN to go back): ";
		if (!std::getline(std::cin, input))
			exit_function();
		if (std::cin.eof())
			exit_function();
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

std::string	readInput(const std::string& prompt) {
	std::string input;

	std::cout << prompt;
	if (!std::getline(std::cin, input))
		exit_function();
	if (std::cin.eof())
		exit_function();
	return (input);
}

void	add_contact(PhoneBook& pb, size_t& i) {
	std::string	first_name = readInput("First name: ");
	std::string	last_name = readInput("Last name: ");
	std::string	nickname = readInput("Nickname: ");
	std::string	phone_number = readInput("Phone number: ");
	std::string	darkest_secret = readInput("Darkest secret: ");
	pb.setContact(i, Contact(first_name, last_name, nickname, phone_number, darkest_secret));
	i = (i + 1) % 8;
}

void	intro_prompt() {
	std::cout << "This is phonebook. Available commands: " << std::endl;
	std::cout << std::endl;
	std::cout << "ADD:    Add new contact to the list" << std::endl;
	std::cout << std::endl;
	std::cout << "SEARCH: Search for existing contact information" << std::endl;
	std::cout << std::endl;
	std::cout << "EXIT:   Exit program" << std::endl;
	std::cout << std::endl;
}

int	main(int ac, char **) {
	std::string	input;
	PhoneBook	pbook;

	if (ac != 1)
	{
		std::cout << "There should be given no arguments" << std::endl;
		return (1);
	}
	intro_prompt();
	size_t	i = 0;
	while (input != "EXIT")
	{
		std::cout << "> ";
		if(!std::getline(std::cin, input))
			exit_function();
		if (std::cin.eof())
			exit_function();
		if (input == "add")
			add_contact(pbook, i);
		else if (input == "sea")
			search_contact(pbook);
	}
	std::cout << "Exiting phonebook" << std::endl;
	return (0);
}

//todo
//change functions to methods
