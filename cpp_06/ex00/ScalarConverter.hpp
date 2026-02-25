#pragma once

# include <iostream>
# include <string>
# include <cstring>
# include <limits.h>
# include <cfloat>
# include <ostream>
# include <stdlib.h>

class ScalarConverter
{
	public:
		static void convert(std::string string);
	private:
		ScalarConverter();
		//ScalarConverter(the not default);
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);

}