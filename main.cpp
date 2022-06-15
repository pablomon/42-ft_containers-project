#include <iostream>
#include <cstring> // strcmp

#include "tests/tests.hpp"

#ifndef STD
# define STD "FT"
#endif

int main()
{
	std::cout << "Using " << STD << " containers" << std::endl;

	std::string input;
	bool exit = false;
	while (exit == false)
	{
		exit = true;
		std::cout << "Use v(ector), s(tack) or m(ap)" << std::endl;
		std::cin >> input;
		if (input == "v")
			vector_tests();
		else if (input == "s")
			stack_tests();
		else if (input == "m")
			map_tests();
		else
		{
			std::cout << "Wrong option" << std::endl;
			exit = false;
		}
	}

	while (1)
	{
		std::cout << std::endl << "Press q to exit" << std::endl;
		std::cin >> input;
		if (input == "q")
		{
			std::cout << "Bye" << std::endl;
			return 0;
		}
	}
}
