#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _data(copy._data) {} //*this = copy;

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_data = copy._data;
	return (*this);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::string theline;
	std::ifstream thefile(filename.c_str());
	std::getline(thefile, theline); //read but but dont print -> skip header
	while (getline (thefile, theline))
	{
		//std::cout << theline << std::endl;
		size_t pos = theline.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = theline.substr(0, pos); //specify len -> upto pos
		std::string val = theline.substr(pos + 1); //len not specified -> til the end
		float value = static_cast<float>(std::atof(val.c_str()));
		_data[date] = value;  //store in _data as key-val
	}
	thefile.close();
	//printData();
}

void BitcoinExchange::loadInput(const std::string &filename)
{
	std::string theline;
	std::ifstream thefile(filename.c_str());
	std::getline(thefile, theline); //skip header
	while (getline (thefile, theline))
	{
		//std::cout << theline << std::endl;
		size_t pos = theline.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Bad line: " << theline << std::endl;
			continue;
		}
		std::string date = rem_whitesp(theline.substr(0, pos));
		std::string val = rem_whitesp(theline.substr(pos + 1));
		//std::cout <<date << " => " << val << std::endl;
		 try
		{
			float value = checkEntries(date, val);
			float price = findPrice(date);
			std::cout << date << " => " << value << " = " << (value * price) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	thefile.close();
}

// void BitcoinExchange::printData() const
// {
// 	for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it)
// 		std::cout << it->first << " => " << it->second << std::endl; //std::pair first & second
// }

std::string BitcoinExchange::rem_whitesp(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r"); //read basic_string
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, last - first + 1);
}

float BitcoinExchange::checkEntries(const std::string &date, const std::string &val)
{
	validDate(date);
	float value = validVal(val);
	return (value);
}

void BitcoinExchange::validDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') //must use '-'
		throw std::invalid_argument("bad entry => " + date);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2022) //range in database
		throw std::invalid_argument("bad entry => " + date);
	if (month < 1 || month > 12)
		throw std::invalid_argument("bad entry => " + date);
	if (day < 1 || day > 31)
		throw std::invalid_argument("bad entry => " + date);
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//if leap year
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1]) //compare the day in the month's actual days
		throw std::invalid_argument("bad entry => " + date);
}

float BitcoinExchange::validVal(const std::string &val) const
{
	if (val.empty())
		throw std::invalid_argument("empty value string");
	char *endptr;
	float value = std::strtof(val.c_str(), &endptr); //make it to float
	if (*endptr != '\0' && *endptr != '\n' && *endptr != '\r')
		throw std::invalid_argument("bad entry => " + val);
	if (value < 0)
		throw std::invalid_argument("negative value.");
	else if (value > 1000)
		throw std::invalid_argument("value too large.");
	return (value);
}

float BitcoinExchange::findPrice(const std::string &date) const
{
	if (_data.empty())
		throw std::runtime_error("database is empty");
	//binary search operation that returns an iterator to the first
	//element whose key is NOT LESS (<=) than the given date (must decrement afterwards)
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it != _data.end() && it->first == date) //match found
		return it->second;
	if (it == _data.begin()) //no earlier date exist
		throw std::runtime_error("unavailable for date => " + date);
	--it;
	return it->second;
}