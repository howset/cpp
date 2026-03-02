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
}

void ScalarConverter::convert(const std::string str){
	e_type type = detectType(str);
	switch(type) {
		case CHAR:
			return(fromChar(str));
		case INT:
			return(fromInt(str));
		case FLOAT:
			return(fromFloat(str));
		case DOUBLE:
			return(fromDouble(str));
		case PSEUDO_LIT:
			return(fromPseudo(str));
		default:
			std::cerr << "Error: Invalid/unknown format." << std::endl;
			return;
	}
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string &str){
	if (isChar(str)) {return (CHAR);}
	else if (isInt(str)) {return (INT);}
	else if (isFloat(str)) {return (FLOAT);}
	else if (isDouble(str)) {return (DOUBLE);}
	else if (isPseudo(str)) {return (PSEUDO_LIT);}
	else {return (INVALID);}
}

bool ScalarConverter::isChar(const std::string &str) {
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &str) {
	int non_number = 0;
	for (unsigned long i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] == '+')))
			non_number++;
	}
	if (non_number == 0 && str.length() > 0 && (str != "-" && str != "+"))
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

bool ScalarConverter::isPseudo(const std::string &str) {
	if (str == "nan" ||
		str == "+inf" ||
		str == "-inf" ||
		str == "nanf" ||
		str == "+inff" ||
		str == "-inff")
		return (true);
	return (false);
}

void ScalarConverter::fromChar(const std::string &str) {
	if (isprint(str[1])) //because 'A' where A is idx 1
		std::cout << "char: '" << str[1] << "'" << std::endl;
	else
		std::cout << "char: Undisplayable character" << std::endl;
	std::cout << "int: " << static_cast<int>(str[1]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[1]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[1]) << std::endl;
}

void ScalarConverter::fromInt(const std::string &str) {
	int i = std::atoi(str.c_str());
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout << "char: Undisplayable character" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(const std::string &str) {
	float f = std::atof(str.c_str());

	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Undisplayable character" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f;
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::fromDouble(const std::string &str) {
	double d = std::atof(str.c_str());

	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Undisplayable character" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;	

	if (std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;	

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;	

	std::cout << "double: " << d;
	if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::fromPseudo(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[str.length() - 1] == 'f' && 
		str != "inf" && 
		str != "+inf" && 
		str != "-inf") {
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else {
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

