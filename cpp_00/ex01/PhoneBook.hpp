#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact entry[8]; //obj from Contact
		int	 index;
		int	 total;
	public:
		void initialize();
		void add_contact();
		void search_contact();
};

#endif