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
	e_type type = checkType(str);
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
			std::cerr << RED << "Error: Invalid/unknown format." << RES << std::endl;
			return;
	}
}

ScalarConverter::e_type ScalarConverter::checkType(const std::string &str){
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
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
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
	char c;
	if (str.length() == 3) //quoted 'a'
		c = str[1];
	else //single char
		c = str[0];
	if (isprint(c))
		std::cout << MAG << "char: '" << c << "'" << RES << std::endl;
	else
		std::cout << MAG << "char: Undisplayable character" << RES << std::endl;
	std::cout << GRE << "int: " << static_cast<int>(str[1]) << RES << std::endl;
	std::cout << BLU << "float: " << static_cast<float>(str[1]) << "f" << RES << std::endl;
	std::cout << YEL << "double: " << static_cast<double>(str[1]) << RES << std::endl;
}

void ScalarConverter::fromInt(const std::string &str) {
	int i = std::atoi(str.c_str());
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << MAG << "char: impossible" << RES << std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout << MAG << "char: Undisplayable character" << RES << std::endl;
	else
		std::cout << MAG << "char: '" << static_cast<char>(i) << "'" << RES << std::endl;
	std::cout << GRE << "int: " << i << std::endl;
	std::cout << BLU << "float: " << static_cast<float>(i) << ".0f" << RES << std::endl;
	std::cout << YEL << "double: " << static_cast<double>(i) << ".0" << RES << std::endl;
}

void ScalarConverter::fromFloat(const std::string &str) {
	float f = std::atof(str.c_str());

	if (std::isnan(f) || std::isinf(f))
		std::cout << MAG << "char: impossible" << RES << std::endl;
	else if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << MAG << "char: impossible" << RES << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << MAG << "char: Undisplayable character" << RES << std::endl;
	else
		std::cout << MAG << "char: '" << static_cast<char>(f) << "'" << RES << std::endl;

	if (std::isnan(f) || std::isinf(f))
		std::cout << GRE << "int: impossible" << RES << std::endl;
	else if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << GRE << "int: impossible" << RES << std::endl;
	else
		std::cout << GRE << "int: " << static_cast<int>(f) << RES << std::endl;

	std::cout << BLU << "float: " << f;
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f" << RES << std::endl;

	std::cout << YEL << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << RES << std::endl;
}

void ScalarConverter::fromDouble(const std::string &str) {
	double d = std::atof(str.c_str());

	if (std::isnan(d) || std::isinf(d))
		std::cout << MAG << "char: impossible" << RES << std::endl;
	else if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << MAG << "char: impossible" << RES << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << MAG << "char: Undisplayable character" << RES << std::endl;
	else
		std::cout << MAG << "char: '" << static_cast<char>(d) << "'" << RES << std::endl;	

	if (std::isnan(d) || std::isinf(d))
		std::cout << GRE << "int: impossible" << RES << std::endl;
	else if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << GRE << "int: impossible" << RES << std::endl;
	else
		std::cout << GRE << "int: " << static_cast<int>(d) << RES << std::endl;	

	float f = static_cast<float>(d);
	std::cout << BLU << "float: " << f;
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << ".0";
	std::cout << "f" << RES << std::endl;	

	std::cout << YEL <<  "double: " << d;
	if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
		std::cout << ".0";
	std::cout << RES << std::endl;
}

void ScalarConverter::fromPseudo(const std::string &str) {
	std::cout << MAG << "char: impossible" << RES << std::endl;
	std::cout << GRE << "int: impossible" << RES << std::endl;
	if (str[str.length() - 1] == 'f' && 
		str != "inf" && 
		str != "+inf" && 
		str != "-inf") {
		std::cout << BLU << "float: " << str << RES << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << RES << std::endl;
	}
	else {
		std::cout << BLU << "float: " << str << "f" << RES << std::endl;
		std::cout << YEL <<  "double: " << str << RES << std::endl;
	}
}

