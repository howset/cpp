#include "ScalarConverter.hpp"

void testCase(const std::string& input) {
	std::cout << CYA << "Testing: \"" << input << "\"" << RES << std::endl;
	ScalarConverter::convert(input);
}

int main(int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	std::cout << "\n" << MAG << " CHAR " << RES << std::endl;
	testCase("'a'");
	testCase("'0'");
	testCase("' '");

	std::cout << "\n" << MAG << " INT " << RES << std::endl;
	testCase("0");
	testCase("-42");
	testCase("2147483647");   //INT_MAX
	testCase("-2147483649");  //INT_MIN - 1 (underflow)

	std::cout << "\n" << MAG << " FLOAT " << RES << std::endl;
	testCase("4.2f");
	testCase("-4.2f");
	testCase("0.00001f");
	testCase("123.456f");

	std::cout << "\n" << MAG << " DOUBLE " << RES << std::endl;
	testCase("4.2");
	testCase("-4.2");
	testCase("123.456789");

	std::cout << "\n" << MAG << " PSEUDO-LITERAL " << RES << std::endl;
	testCase("nan");
	testCase("nanf");
	testCase("+inf");
	testCase("-inf");
	testCase("+inff");
	testCase("-inff");
	testCase("inf");
	testCase("inff");

	std::cout << "\n" << MAG << " EDGE " << RES << std::endl;
	testCase("128");	// Beyond char range
	testCase("-1");	 // Negative to char
	testCase("31");	 // Non-displayable char
	testCase("255");	// Edge of unsigned char

	std::cout << "\n" << MAG << " INVALID/ERROR " << RES << std::endl;
	testCase("abc");
	testCase("12abc");
	testCase("--42");
	testCase("4.2.2");
	testCase(".");
	testCase("42ff");
	testCase("nanff");

	return 0;
}