#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		PhoneBook();
		const Contact&	getContact(int index) const;
		void			setContact(int index, const Contact& contact);
		bool			isContactSet(int index) const;
		std::string		readInput(const std::string& prompt);
		void			addContact(PhoneBook& pb, size_t& i);
};

#endif
