#pragma once
# include <map>
# include <string>
class BitcoinExchange
{
private:
	//key-value map (string-float)
	std::map<std::string, float> _data;

	bool isValidDate(const std::string &date) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadData(const std::string &filename);
	void processInput(const std::string &filename);
};