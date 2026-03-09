#pragma once
# include <map> //map
# include <string> //getline
# include <iostream>
# include <fstream> //ifstream
# include <cstdlib> //atof
class BitcoinExchange
{
private:
	//key-value map (string-float)
	std::map<std::string, float> _data;

	//bool isValidDate(const std::string &date) const;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	void loadDatabase(const std::string &filename);
	void printData() const;
	void loadInput(const std::string &filename);
	std::string rem_whitesp(const std::string &str);
	void validDate(const std::string &date) const;
	float validVal(const std::string &valStr) const;
	float checkEntries(const std::string &date, const std::string &val);
	float findClosestPrice(const std::string &date) const;
};