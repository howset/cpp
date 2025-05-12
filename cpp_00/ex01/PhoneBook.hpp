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
		PhoneBook() //constructor
		{
			index = 0;
			total = 0;
		}
		void add_contact();
		void search_contact();
};

#endif