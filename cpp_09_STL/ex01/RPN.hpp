#pragma once

# include <iostream>
# include <stack>
# include <sstream> //istringstream

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

//doesnt really have to be a class, does it?
class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		
		int evaluate(const std::string &expr);
		bool isOperator(char c);
		int doOperation(int a, int b, char op);
};