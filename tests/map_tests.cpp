#include "tests.hpp"
#include "../containers/map.hpp"
#include <map>
#include <iomanip>

#define T std::string
std::string k[] = { "k1", "k2", "k3", "k4", "k5", "k6"};
std::string v[] = { "v1", "v2", "v3", "v4", "v5", "v6"};

template <class U>
void printmap(NS::map<U,U> mapa, std::string name)
{
	std::cout << "printing " << name << std::endl;
	std::cout << "  size = " << mapa.size() << std::endl;
	for (typename NS::map<U, U>::iterator it = mapa.begin(); it != mapa.end(); it++)
		std::cout << "  " << it->first << std::endl;
	std::cout << "end of print" << std::endl;
	std::cout << std::endl;
}

void m_testConstructors()
{
	chapter("\nCONSTRUCTORS");
	{
		title("Empty constructor");
		NS::map<T,T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		printmap(map, "map");
	}
	{
	 	title("Range constructor");
		NS::map<T, T> basemap;
		basemap.insert(NS::pair<T, T>(k[0], v[0]));
		basemap.insert(NS::pair<T, T>(k[1], v[1]));
		basemap.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(basemap, "source map");
		
		NS::map<T, T> map(basemap.begin(), basemap.end());
		printmap(map, "destination map");
		NS::map<T, T>::iterator it = map.begin();
		assert(it->first == k[0]);
		it = map.end();
		--it;
		assert(it->first == k[2]);
	}
	{
	 	title("Copy constructor");
		NS::map<T, T> basemap;
		basemap.insert(NS::pair<T, T>(k[0], v[0]));
		basemap.insert(NS::pair<T, T>(k[1], v[1]));
		basemap.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(basemap, "source map");
		
		NS::map<T, T> map(basemap);
		printmap(map, "destination map");
		NS::map<T, T>::iterator it = map.begin();
		assert(it->first == k[0]);
		it = map.end();
		--it;
		assert(it->first == k[2]);		
	}

	chapterend("CONSTRUCTORS OK");
}

void m_testOperators()
{
	chapter("\nOPERATORS");
	{
		title("Assignment operator");
		NS::map<T, T> basemap;
		basemap.insert(NS::pair<T, T>(k[0], v[0]));
		basemap.insert(NS::pair<T, T>(k[1], v[1]));
		basemap.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(basemap, "source map");
		
		NS::map<T, T> map;
		basemap.insert(NS::pair<T, T>(k[4], v[4]));
		printmap(map, "destination map");
		map = basemap;
		printmap(map, "destination map after assignment");
		NS::map<T, T>::iterator it = map.begin();
		assert(it->first == k[0]);
		it = map.end();
		--it;
		assert(it->first == k[2]);
	}
}

void map_tests()
{
	chapter("\nT E S T I N G   M A P");

	m_testConstructors();
	m_testOperators();


}