#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    // Extract year, month, day
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2022)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    // Check days per month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(float value) const
{
    return value >= 0 && value <= 1000;
}

float BitcoinExchange::findClosestPrice(const std::string &date) const
{
    if (_data.empty())
        return -1;
    
    // Find the exact date or the closest earlier date
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    
    // If exact match
    if (it != _data.end() && it->first == date)
        return it->second;
    
    // If no earlier date exists
    if (it == _data.begin())
        return -1;
    
    // Get the closest earlier date
    --it;
    return it->second;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        if (!isValidDate(date))
            continue;
        
        float value = static_cast<float>(std::atof(valueStr.c_str()));
        _data[date] = value;
    }
    
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header or check it
    
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        // Validate date
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Convert value
        char *endptr;
        float value = std::strtod(valueStr.c_str(), &endptr);
        
        // Check for conversion errors
        if (*endptr != '\0' && *endptr != '\n')
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        // Validate value
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Find price
        float price = findClosestPrice(date);
        if (price < 0)
        {
            std::cerr << "Error: no data available for date => " << date << std::endl;
            continue;
        }
        
        // Calculate and display result
        std::cout << date << " => " << value << " = " << (value * price) << std::endl;
    }
    
    file.close();
}