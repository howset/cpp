/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 18:34:41 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //cin, cout,cerr
#include <fstream> //open infile outfile
#include <string> //getline

int	checks(std::fstream &fin,
			std::ofstream &fout,
			std::string s1,
			std::string s2)
{
	if (!fin.is_open())
	{
		std::cerr << "fin not opening!" << std::endl;
		return(1);
	}
	else if (!fout.is_open())
	{
		std::cerr << "fout not opening!" << std::endl;
		return(1);
	}
	else if (s1.empty())
	{
		std::cerr << "s1 empty!" << std::endl;
		return(1);
	}
	else if (s2.empty())
	{
		std::cerr << "s2 empty!" << std::endl;
		return(1);
	}
	else
		return(0);
}

void	replace(std::fstream &fin,
			std::ofstream &fout,
			std::string s1,
			std::string s2)
{
	std::string	line;
	size_t pos;
	while (getline(fin, line))
		pos = 0;
		// while (found : from s1[pos]) {substitute && update pos}	
		while ((pos = line.find(s1, pos)) != std::string::npos) //npos = not found
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		fout << line << std::endl;
}


//unnecessary close(), destructor does this automatically;
int main(int argc, char *argv[])
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		newfilename;
	std::fstream	fin;
	std::ofstream	fout;

	//preliminary check
	if (argc != 4)
	{
		std::cout << "try again!" << std::endl;
		return (1);
	}
	//assigning & opening stuffs
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	newfilename = filename + ".replace";
	fin.open(filename);
	fout.open((newfilename).c_str());
	//checks if they are ok
	if (checks(fin, fout, s1, s2))
		return (1);
	//replacing
	replace(fin, fout, s1, s2);
	// std::cout << s1 << std::endl;
	// std::cout << s2 << std::endl;
	return (0);
}