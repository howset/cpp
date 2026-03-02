#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	//empty copy constructor & copy assignment operator purely to satisfy OCF
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	//empty copy constructor & copy assignment operator purely to satisfy OCF
	(void) copy; 
	return (*this);
};

void ScalarConverter::convert(const std::string str){
	e_type type = detectType(str);
};

ScalarConverter::e_type ScalarConverter::detectType(const std::string &str){
	if (isChar(str)) {return CHAR;}
	if (isInt(str)) {return INT;}
	if (isFloat(str)) {return FLOAT;}
	if (isDouble(str)) {return DOUBLE;}
	return INVALID;
}

bool ScalarConverter::isChar(const std::string &str) {
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &str) {
	int non_number = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] == '+')))
			non_number++;
	}
	if (non_number == 0 && str.length() > 0)
		return (true);
	return (false);
}

bool ScalarConverter::isFloat(const std::string &str) {
	if (str.length() > 1 && str[str.length() - 1] == 'f' && str.find('.') != std::string::npos)
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(const std::string &str) {
	if (str.find('.') != std::string::npos)
		return (true);
	return (false);
}