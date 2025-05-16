#include "PhoneBook.hpp"

void	PhoneBook::initialize()
{
	index = 0;
	total = 0;
}

void	PhoneBook::add_contact()
{
	entry[index].set_entry();
	index = (index + 1) % 8;
	if (total < 8)
		total++;
}

void	PhoneBook::search_contact()
{
	int			i;
	std::string	input;
	int			search;

	if (total == 0)
	{
		std::cout << "Phone Book is empty." << std::endl;
		return;
	}
	std::cout << "| " << std::setw(10) << "Index" 
			  << " | " << std::setw(10) << "First Name" 
			  << " | " << std::setw(10) << "Last Name" 
			  << " | " << std::setw(10) << "nick_name" 
			  << " |" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	for (i = 0; i < total; i++)
		entry[i].show_shorten(i + 1);
	std::cout << std::endl;
		std::cout << "Enter index to view details: ";
	std::getline(std::cin, input);
	for (i = 0; input[i]; i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cerr << "Enter a number or type EXIT again to exit." << std::endl;
			return;
		}
	}
	search = std::atoi(input.c_str());
	if (search >= 1 && search <= total)
		entry[search - 1].show_complete();
	else
		std::cerr << "Error! Index between 1-8." << std::endl;
}