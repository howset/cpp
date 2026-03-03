#include "main.hpp"

int main()
{
	PhoneBook		pb;
	std::string		cmd;

	pb.initialize();
	while (1)
	{
		cmd = handle_input();
		handle_eof();
		if (cmd == "ADD" || cmd == "add")
			pb.add_contact();
		else if (cmd == "SEARCH" || cmd == "search")
			pb.search_contact();
		else if (cmd == "EXIT" || cmd == "exit")
			break;
		else if (cmd == "test")
			fill_pb(pb);
		else
			std::cerr << "Error! Invalid option." << std::endl;
	}
	return (0);
}

std::string handle_input()
{
	std::string	command;

	std::cout << std::endl;
	std::cout << "Pick one option (ADD, SEARCH, EXIT): ";
	std::getline(std::cin, command);
	return (command);
}

void handle_eof()
{
	if (std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << "EOF!" << std::endl;
		std::exit(0);
	}
}
