#pragma once

# include <iostream>
# include <stack>
# include <sstream> //istringstream

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