#pragma once

# include <iostream>
# include <string>
# include <cstring>
# include <limits>
# include <cfloat>
# include <ostream>
//# include <stdlib.h>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		enum e_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			//PSEU_LIT, //merge pesudo lit & unknown to invalid?
			//UNKNOWN
			INVALID
		};

		//instead of public, now constr & deconstr are private to avoid instantiation by user.
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

		static e_type	detectType(const std::string &str);
		static bool		isChar(const std::string &str);
		static bool		isInt(const std::string &str);
		static bool		isFloat(const std::string &str);
		static bool		isDouble(const std::string &str);
};