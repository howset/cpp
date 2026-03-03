#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main() {
	srand(time(NULL));
	Base *something[5];
	for (int i(0); i < 5; i ++) {
		something[i] = generate();
	}
	for (int i(0); i < 5; i ++) {
		identify(something[i]);
	}
	for (int i(0); i < 5; i ++) {
		identify(*something[i]);
	}
	for (int i(0); i < 5; i ++) {
		delete(something[i]);
	}
}

Base	*generate(void)
{
	int	rand = std::rand() % 3;
	if (rand == 0)
		return (new A);
	else if (rand == 1)
		return (new B);
	else
		return (new C);
}

//returns null on failure
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << RED << "Real type (pointer): A" << RES << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GRE << "Real type (pointer): B" << RES << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << BLU << "Real type (pointer): C" << RES << std::endl;
}

//references cant be null, hence need a try-catch block to throw exception
void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << RED << "Real type (ref): A" << RES << std::endl;
		return;
	} catch (std::exception &e) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << GRE << "Real type (ref): B" << RES << std::endl;
		return;
	} catch (std::exception &e) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << BLU << "Real type (ref): C" << RES << std::endl;
	} catch (std::exception &e) {}
}