#include "Casting.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Convert error: bad arguments" << std::endl << "Usage: value" << std::endl;
	}
	else
	{
		(void)argv;
		Casting caster(argv[1]);
	}
	return (0);
}
