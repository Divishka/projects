#include "Base.hpp"
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "It's A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "It's B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "It's C" << std::endl;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's C" << std::endl;
}

Base* generate(void)
{
	srand(time(NULL));
	int i;
	i = rand() % 3 + 1;
	switch (i)
	{
		case (1):
			return (new A);
			break;

		case (2):
			return (new B);
			break;

		case (3):
			return (new B);
			break;

		default:
			break;
	}
	return (0);
}

int main()
{
	Base* randomBase1 = generate();
	Base* randomBase2 = generate();
	Base* randomBase3 = generate();
	
	std::cout << "****************" << std::endl;
    identify(randomBase1);
    identify(randomBase2);
    identify(randomBase3);

    std::cout << "&&&&&&&&&&&&&&&&" << std::endl;
    identify(randomBase1);
    identify(randomBase2);
    identify(randomBase3);
	
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;
	
	std::cout << "****************" << std::endl;
    identify(a);
    identify(b);
    identify(a);

    std::cout << "&&&&&&&&&&&&&&&&" << std::endl;
    identify(c);
    identify(c);
    identify(b);

	return (0);
}
