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
};

#endif
