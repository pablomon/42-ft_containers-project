#include <vector>
#include <iostream>
#include "containers/vector.hpp"

#define NS ft

template <typename T>
void PrintVector(const NS::vector<T>& vector, std::string name)
{
	std::cout << "  Vector " << name << ":\n";
	std::cout << "  size = " << vector.size() << ", ";
	std::cout << "capacity = " << vector.capacity() << std::endl;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << "  [" << i << "] = " << vector[i] << std::endl;
}

int main(void)
{

	NS::vector<std::string> v;
	v.push_back("a");
	v.push_back("b");
	v.push_back("c");

	{
		NS::vector<std::string>::iterator it = v.begin();
		while (it != v.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		NS::vector<std::string>::reverse_iterator rit = v.rbegin();
		while (rit != v.rend())
		{
			std::cout << *rit << std::endl;
			rit++;
		}
	}
	{
		NS::vector<std::string>::const_iterator cit = v.begin();
		while (cit != v.end())
		{
			std::cout << *cit << std::endl;
			cit++;
		}
	}
	{
		NS::vector<std::string>::const_reverse_iterator cit = v.rbegin();
		while (cit != v.rend())
		{
			std::cout << *cit << std::endl;
			cit++;
		}
	}

	return 0;
}