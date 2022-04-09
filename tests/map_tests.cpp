#include "tests.hpp"
#include "../containers/map.hpp"
#include <map>
#include <iomanip>

void map_tests()
{
	chapter("\nT E S T I N G   M A P");

// #define NS std
// {
// 	NS::map<int,int> mapa;
// 	mapa.insert(NS::pair<int,int>(1,1));
// 	mapa.insert(NS::pair<int,int>(2,2));

// 	NS::map<int,int> mapa2 = mapa;

// 	mapa.erase(1);
// 	for (NS::map<int,int>::iterator it = mapa.begin(); it != mapa.end(); it++)
// 	{
// 		std::cout << it->first << std::endl;
// 	}
	
// 	for (NS::map<int,int>::iterator it = mapa2.begin(); it != mapa2.end(); it++)
// 	{
// 		std::cout << it->first << std::endl;
// 	}
// }
#define NS ft
{
	std::cout << std::endl;
	NS::map<int,int> mapa;
	NS::map<int,int>::iterator it1 = mapa.insert(NS::pair<int,int>(1,1)).first;
	NS::map<int,int>::iterator it2 = mapa.insert(NS::pair<int,int>(2,2)).first;
	mapa.insert(it1, NS::pair<int,int>(3,3));

	NS::map<int,int> mapa2 = mapa;

	mapa.erase(1);
	mapa.erase(2);
	mapa.insert(it1, it2);
	for (NS::map<int,int>::iterator it = mapa.begin(); it != mapa.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
	
	for (NS::map<int,int>::iterator it = mapa2.begin(); it != mapa2.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
}
}