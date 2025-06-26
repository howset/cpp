/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 18:55:27 by hsetyamu         ###   ########.fr       */
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
	std::string	new_line;
	size_t	start;
	size_t	found;

	while (std::getline(fin, line)) 
	{
		start = 0;
		found = line.find(s1);
		while (found != std::string::npos) //"no position" used to indicate invalid or non-existent position
		{
			new_line += line.substr(start, found - start); //the part before the match
			new_line += s2; //the replacement
			start = found + s1.length(); //skip past the match
			found = line.find(s1, start); //find next match
		}
		new_line += line.substr(start); //add the remaining line part
		fout << new_line << std::endl;
	}
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
	fout.open((newfilename).c_str(), std::ios::app);
	//checks if they are ok
	if (checks(fin, fout, s1, s2))
		return (1);
	//replacing
	replace(fin, fout, s1, s2);
	return (0);
}