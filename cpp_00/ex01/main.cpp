#include "main.hpp"

void handle_inputfail()
{
	if (std::cin.eof())
	{
		std::cout << "\nEOF found, exit!" << std::endl;
		std::exit(0);
	}
}

std::string handle_input()
{
	std::string	command;

	std::cout << "Pick one option (ADD, SEARCH, EXIT): ";
	std::getline(std :: cin, command);
	return (command);
}

int main()
{
	PhoneBook		pb;
	std::string		command;

	while (1)
	{
		command = handle_input();
		handle_inputfail();
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cerr << "Invalid option!" << std::endl;
	}
	return (0);
}
