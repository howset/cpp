#include "iter.hpp"

int main( void ) {
	 int arr[] = {5, 2, 8, 1, 9};
	 int len = 5;
	// double arr[] = {3.14, 1.23, 5.67, 0.99};
	// int len = 4;
	// char arr[] = {'z', 'a', 'm', 'b', 'c'};
	// int len = 5;

	std::cout << "Print: " << std::endl;
	iter(arr, len, printArr);
	std::cout << std::endl;
	std::cout << "Sort: " << std::endl;
	sortArr(arr, len);
	iter(arr, len, printArr);
	std::cout << std::endl;
	// std::cout << "Increment: " << std::endl;
	// iter(arr, len, incrArr<int>);
	// iter(arr, len, printArr<int>);
	// std::cout << std::endl;
	return (0);
}

/* class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
} */