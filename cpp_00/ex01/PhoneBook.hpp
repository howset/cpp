#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact entry[8];
		int	 index;
		int	 total;
	public:
		void initialize();
		void add_contact();
		void search_contact();
};

#endif