#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(42);
    mstack.push(21);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << '\n';
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    MutantStack<int> mstack2(mstack);
    mstack2.pop();
    it = mstack.begin();
    ite = mstack.end();
    std::cout << '\n';
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    MutantStack<std::string> mstack_str;
    mstack_str.push("hello");
    mstack_str.push("world");
    mstack_str.push("bye");
    mstack_str.pop();

    MutantStack<std::string>::const_iterator its = mstack_str.begin();
    MutantStack<std::string>::const_iterator ites = mstack_str.end();

    while (its != ites)
    {
        std::cout << *its << std::endl;
        ++its;
    }
    --its;

    return 0;
}