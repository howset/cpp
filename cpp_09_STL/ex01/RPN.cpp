#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &copy): _stack(copy._stack) {}

RPN &RPN::operator=(RPN const &copy) 
{
	if (this != &copy) 
		_stack = copy._stack;
	return (*this);
}

bool RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int RPN::doOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return (a / b);
		default: //wont happen, wrong op already caught by token
			throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::evaluate(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;

	//reads space-separated tokens one at a time from the string stream
	//skips whitespace and reads the next chunk of non-whitespace characters into token
	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			int b = _stack.top(); //last one in is removed
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int res = doOperation(a, b, token[0]);
			_stack.push(res); //put res back in stack
		}
		else if (token.length() == 1 && isdigit(token[0]))
			_stack.push(token[0] - '0'); //push numbers into the stack
		else
			throw std::runtime_error("Error: invalid token => " + token);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	int res = _stack.top();
	_stack.pop();
	return (res);
}