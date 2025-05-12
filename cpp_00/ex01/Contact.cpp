#include "Contact.hpp"

void	Contact::set_entry()
{
	set_fields(first_name, "First Name", false);
	set_fields(last_name, "Last Name", false);
	set_fields(nick_name, "Nick Name", false);
	set_fields(phone_number, "Phone Number", true);
	set_fields(dark_secret, "Darkest Secret", false);
}

void	Contact::set_fields(std::string &field, const std::string &field_name, bool numbers)
{
	bool	valid;
	int		i;

	while (1)
	{
		std::cout << "Enter " << field_name << ": ";
		std::getline(std::cin, field);
		if (field_name == "Phone Number")
			valid = (field.length() <= 10 && field.length() >= 5);
		else
			valid = !field.empty();
		for (i = 0; i < (int)field.length() && valid; i++)
		{
			if (numbers)
			{
				if (!std::isdigit(field[i]))
				{
					valid = false;
					break;
				}
			}
			else
			{
				if (!std::isalpha(field[i]))
				{
					valid = false;
					break;
				}
			}
		}
		if (!valid)
		{
			if (numbers)
				std::cerr << "Error! Only 5-10 numbers are allowed." << std::endl;
			else
				std::cerr << "Error! Only letters are allowed." << std::endl;
		}
		else
			break;
	}
}

// std::setw(10) -> set width (# of letters).
// If text is shorter, then spaces are automatically added.
void	Contact::show_shorten(int idx)
{
	std::cout << "| " << std::setw(10) << idx 
			  << " | " << std::setw(10) << trim_str(first_name)
			  << " | " << std::setw(10) << trim_str(last_name)
			  << " | " << std::setw(10) << trim_str(nick_name) 
			  << " |" << std::endl;
}

void	Contact::show_complete()
{
	std::cout << "First Name : " << first_name << std::endl;
	std::cout << "Last Name : " << last_name << std::endl;
	std::cout << "Nick Name : " << nick_name << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Darkest Secret : " << dark_secret <<std::endl;
	std::cout << std::endl;
}

std::string	Contact::trim_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}