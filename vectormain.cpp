#include <vector>
#include <iostream>
#include "containers/vector.hpp"

#define log(x) std::cout << x << std::endl
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

	return 0;
}