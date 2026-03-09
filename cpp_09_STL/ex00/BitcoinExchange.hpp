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
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);

	void loadDatabase(const std::string &filename);
	void loadInput(const std::string &filename);

	//utils
	//void printData() const;
	std::string rem_whitesp(const std::string &str);
	void validDate(const std::string &date) const;
	float validVal(const std::string &val) const;
	float checkEntries(const std::string &date, const std::string &val);
	float findClosestPrice(const std::string &date) const;
};