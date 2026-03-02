#pragma once

# include <iostream>
# include <string> 
# include <cstring>
# include <limits> //numeric_limits
# include <cstdlib> //atoi
# include <cmath> // isnan, isinf
# include <cfloat> //??
# include <ostream> //??
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
			PSEUDO_LIT,
			INVALID
		};

		//instead of public, now constr & deconstr are private to avoid instantiation by user.
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

		//detect type & helpers
		static e_type	detectType(const std::string &str);
		static bool		isChar(const std::string &str);
		static bool		isInt(const std::string &str);
		static bool		isFloat(const std::string &str);
		static bool		isDouble(const std::string &str);
		static bool		isPseudo(const std::string &str);

		//conversions
		static void		fromChar(const std::string &str);
		static void		fromInt(const std::string &str);
		static void		fromFloat(const std::string &str);
		static void		fromDouble(const std::string &str);
		static void		fromPseudo(const std::string &str);
};