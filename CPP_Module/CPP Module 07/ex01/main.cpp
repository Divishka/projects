#include "iter.hpp"

class Awesome {

public:

Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private: int _n;

};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }


template <typename T>
void iter(T* arr, size_t length, void (*func)(T const& element))
{
	for (size_t i = 0; i < length; i++)
		(*func)(arr[i]);
}

template <typename T>
void display(T const& value)
{
	std::cout << value << " ";
}

int main()
{
	int intR[5] = { 0, 1, 2, 3, 4 };
	iter(intR, 5, &display);
	std::cout << std::endl;
	iter(intR, 3, &display);
	std::cout << std::endl << "-------------------------------------" << std::endl;

	float floatR[5] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
	iter(floatR, 5, &display);
	std::cout << std::endl;
	iter(floatR, 2, &display);
	std::cout << std::endl << "-------------------------------------" << std::endl;

	double doubleR[5] = { 0.00, 1.11, 2.22, 3.33, 4.44 };
	iter(doubleR, 5, &display);
	std::cout << std::endl << "-------------------------------------" << std::endl;

	bool boolR[2] = { false, true };
	iter(boolR, 2, &display);
	std::cout << std::endl << "-------------------------------------" << std::endl;

	std::string stringR[5] = { "1", "2", "OH", "MY", "GOD" };
	iter(stringR, 5, display); std::cout << std::endl;
	iter(stringR, 4, display); std::cout << std::endl;
	iter(stringR, 3, display); std::cout << std::endl;
	iter(stringR, 2, display); std::cout << std::endl;
	iter(stringR, 1, display); std::cout << std::endl;
	iter(stringR, 0, display); std::cout << std::endl;
	
	std::cout << std::endl << "-------------------------------------" << std::endl;
	std::cout << std::endl << "CHECKLIST MAIN" << std::endl;
	
	int tab[] = { 0, 1, 2, 3, 4}; // <--- | never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
}
