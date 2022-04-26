#include <iostream>
#include <cstring> // strcmp 

#ifndef STD
#define STD "FT"
#endif
#include "tests/tests.hpp"

int main(int argc, char **argv)
{
	std::cout << "Using " << STD << " containers" << std::endl;
	if (argc == 1)
	{
		std::cout << "Use v(ector), s(tack) or m(ap)" << std::endl;
		return 0;
	}
	
	if (std::strcmp(argv[1], "v") == 0 )
		vector_tests();
	else if (std::strcmp(argv[1], "s") == 0 )
		stack_tests();
	else if (std::strcmp(argv[1], "m") == 0)
		map_tests();
	else
		std::cout << "Use v(ector), s(tack) or m(ap)" << std::endl;

	return 0;
}
