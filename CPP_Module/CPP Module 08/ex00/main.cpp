#include "easyfind.hpp"

template <typename T>
void easyfind(T& container, int element)
{
	std::vector<int>::iterator it;
	it = find(container.begin(), container.end(), element);
	if (it == container.end())
		throw NotFound();
	std::cout << "Element found: " << *it << std::endl;
}

int main()
{
	std::vector<int> vec;
	vec.push_back(6);
	vec.push_back(5);
	vec.push_back(13);
	vec.push_back(21);
	vec.push_back(0);

	try
	{
		easyfind(vec, -4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(vec, 7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(vec, 13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
