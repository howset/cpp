#include "Contact.hpp"

void	Contact::set_content()
{
	while (1)
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first_name);

		bool valid = !first_name.empty();
		for (size_t i = 0; i < first_name.length(); i++)
		{
			if (!std::isalpha(first_name[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			std::cerr << "❌ Invalid First Name! Only letters are allowed.\n";
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last_name);

		bool valid = !last_name.empty();
		for (size_t i = 0; i < last_name.length(); i++)
		{
			if (!std::isalpha(last_name[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			std::cerr << "❌ Invalid Last Name! Only letters are allowed.\n";
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter nick_name: ";
		std::getline(std::cin, nick_name);

		bool valid = !nick_name.empty();
		for (size_t i = 0; i < nick_name.length(); i++)
		{
			if (!std::isalpha(nick_name[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			std::cerr << "❌ Invalid nick_name! Only letters are allowed.\n";
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter Phone Number (10 digits): ";
		std::getline(std::cin, phone_number);

		bool valid = phone_number.length() == 10;
		for (size_t i = 0; i < phone_number.length(); i++)
		{
			if (!std::isdigit(phone_number[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			std::cerr << "❌ Invalid Phone Number! It must be exactly 10 digits.\n";
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, dark_secret);

		bool valid = !dark_secret.empty();
		for (size_t i = 0; i < dark_secret.length(); i++)
		{
			if (!std::isalpha(dark_secret[i]))
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			std::cerr << "❌ Invalid Secret! Only letters are allowed.\n";
		else
			break;
	}
}

// std::setw(10) -> set width (# of letters).
// If text is shorter, then spaces are automatically added.
// std::right -> right justify
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
	std::cout << "nick_name : " << nick_name << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Drakest secret : " << dark_secret <<std::endl;
	std::cout << std::endl;
}

std::string	Contact::trim_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}