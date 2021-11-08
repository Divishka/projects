#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int n = 1; n < argc; n++)
        {
            int i = 0;
            while (argv[n][i])
            {
                std::cout << (char)std::toupper(argv[n][i]);
                i++;
            }
            if (n + 1 != argc)
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return (0);
}
