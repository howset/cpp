#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

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

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Real type (pointer): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Real type (pointer): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Real type (pointer): C" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Real type (ref): A" << std::endl;
		return;
	} catch (std::exception &e) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Real type (ref): B" << std::endl;
		return;
	} catch (std::exception &e) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Real type (ref): C" << std::endl;
	} catch (std::exception &e) {}
}