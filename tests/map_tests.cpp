#include "tests.hpp"
#include "../containers/map.hpp"
#include <map>
#include <iomanip>

// #define T std::string
// std::string k[] = { "k1", "k2", "k3", "k4", "k5", "k6", "k7", "k8"};
// std::string v[] = { "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8"};

#define T int
int k[] = { 1, 2, 3, 4 ,5 ,6 ,7 ,8 };
int v[] = { 11,22,33,44,55,66,77,88 };

template <class U>
void printmap(NS::map<U,U> mapa, std::string name)
{
	std::cout << "printing " << name << std::endl;
	std::cout << "  size = " << mapa.size() << std::endl;
	for (typename NS::map<U, U>::iterator it = mapa.begin(); it != mapa.end(); it++)
		std::cout << "  " << it->first << " => " << it->second << std::endl;
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
		map.insert(NS::pair<T, T>(k[4], v[4]));
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
void m_testIterators()
{
	chapter("\nITERATORS");
	{
		title("Iterators");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		map.insert(NS::pair<T, T>(k[5], v[5]));
		map.insert(NS::pair<T, T>(k[6], v[6]));
		printmap(map, "map");

		// map.m_tree.print();
		NS::map<T, T>::iterator beg = map.begin();
		NS::map<T, T>::iterator end = map.end();
		while (end != beg)
		{
			--end;
			std::cout << end->first << '\n';
		}
		std::cout << "-------" << std::endl;
		NS::map<T, T> map2;
		map2.insert(NS::pair<T, T>(k[0], v[0]));
		NS::map<T, T>::iterator itembegin = map2.begin();

		std::cout << (itembegin)->first << std::endl;

		itembegin--;
		itembegin--;

		std::cout << (itembegin)->first << std::endl;

		NS::map<T, T>::iterator itend = map2.end();
		map2.insert(NS::pair<T, T>(k[1], v[1]));

		std::cout << (--itend)->first << std::endl;

		NS::map<T, T>::iterator itend2 = map2.end();
		std::cout << (--itend2)->first << std::endl;
		std::cout << "-------" << std::endl;
	}

	// const iterators
	{
		title("Constant iterators");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		map.insert(NS::pair<T, T>(k[5], v[5]));
		map.insert(NS::pair<T, T>(k[6], v[6]));
		printmap(map, "map");

		// map.m_tree.print();
		NS::map<T, T>::const_iterator beg = map.begin();
		NS::map<T, T>::const_iterator end = map.end();
		while (end != beg)
		{
			--end;
			std::cout << end->first << '\n';
		}
	}
	{
		title("Reverse iterators");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		map.insert(NS::pair<T, T>(k[5], v[5]));
		map.insert(NS::pair<T, T>(k[6], v[6]));
		printmap(map, "map");

		// map.m_tree.print();
		NS::map<T, T>::reverse_iterator rbeg = map.rbegin();
		NS::map<T, T>::reverse_iterator rend = map.rend();
		while (rbeg != rend)
		{
			std::cout << rbeg->first << '\n';
			++rbeg;
		}
	}
	{
		title("Reverse constant iterators");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		map.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(map, "map");

		// map.m_tree.print();
		NS::map<T, T>::const_reverse_iterator rbeg = map.rbegin();
		NS::map<T, T>::const_reverse_iterator rend = map.rend();
		while (rbeg != rend)
		{
			std::cout << rbeg->first << '\n';
			++rbeg;
		}
	}
}
void m_testCapacity()
{
	chapter("\nCAPACITY");
	title("Empty & Size");
	NS::map<T, T> sizemap;
	printmap(sizemap, "size map");
	std::cout << "Is empty = " << sizemap.empty() << '\n';
	assert(sizemap.size() == 0);
	assert(sizemap.empty() == true);
	sizemap.insert(NS::pair<T, T>(k[0], v[0]));
	sizemap.insert(NS::pair<T, T>(k[1], v[1]));
	sizemap.insert(NS::pair<T, T>(k[2], v[2]));
	printmap(sizemap, "size map");
	std::cout << "Is empty = " << sizemap.empty() << '\n';
	assert(sizemap.size() == 3);
	assert(sizemap.empty() == false);
	sizemap.erase(k[0]);
	printmap(sizemap, "size map");
	assert(sizemap.size() == 2);
	sizemap.erase(sizemap.begin(), sizemap.end());
	printmap(sizemap, "size map");
	assert(sizemap.size() == 0);

	title("Max size");
	std::cout << "Max size = " << sizemap.max_size() << std::endl;
	chapterend("CAPACITY OK");
}
void m_testAccess()
{
		chapter("\nELEMENT ACCESS: Operator[]");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		printmap(map, "map");
		map[k[0]];
		map[k[1]];
		printmap(map, "map");
		assert(map.size() == 2);
		
		std::cout << map[k[0]] << std::endl;
		std::cout << map[k[1]] << std::endl;
		chapterend("ELEMENT ACCESS OK");
}
void m_testModifiers()
{
	chapter("\nMODIFIERS");
	{
		title("Insert");
		NS::map<T, T> map;
		std::cout << "Single element" << '\n';
		NS::map<T, T>::iterator it1 = map.insert(NS::pair<T, T>(k[0], v[0])).first;
		assert(it1->first == k[0]);
		NS::map<T, T>::iterator it2 = map.insert(NS::pair<T, T>(k[1], v[1])).first;
		assert(it2->first == k[1]);

		std::cout << "Single element with hint" << '\n';
		NS::map<T, T>::iterator it3 = map.insert(it1, NS::pair<T, T>(k[2], v[2]));
		assert(it3->first == k[2]);
		printmap(map, "map");

		std::cout << "Range insert" << "\n";
		NS::map<T, T> map2;
		map2.insert(NS::pair<T, T>(k[3], v[3]));
		map2.insert(NS::pair<T, T>(k[4], v[4]));
		map2.insert(NS::pair<T, T>(k[5], v[5]));
		printmap(map2, "Source map");
		printmap(map, "Destination map");
		std::cout << "Insert source map begin to end in destination map" << '\n';
		map.insert(map2.begin(), map2.end());
		printmap(map, "Destination map after copy");
		assert(map.begin()->first == k[0]);
		assert((--map.end())->first == k[5]);

		// Accessing end is an undefined behaviour, possible segfault
		// NS::map<T, T> mapaend;
		// mapaend.insert(NS::pair<T, T>(k[0], v[0]));
		// NS::map<T, T>::iterator itmapaend = mapaend.end();
		// std::cout << "Printing end() : " << itmapaend->first << std::endl;
	}
	{
		title("Erase");
		NS::map<T, T> map;
		NS::map<T, T>::iterator it1 = map.insert(NS::pair<T, T>(k[0], v[0])).first;
		map.insert(NS::pair<T, T>(k[1], v[1]));
		NS::map<T, T>::iterator it2 = map.insert(NS::pair<T, T>(k[2], v[2])).first;
		map.insert(NS::pair<T, T>(k[3], v[3]));
		NS::map<T, T>::iterator it3 = map.insert(NS::pair<T, T>(k[4], v[4])).first;
		printmap(map, "map");

		std::cout << "Erase single (iterator)" << '\n';
		map.erase(it1);
		printmap(map, "map");
		assert(map.begin()->first == k[1]);

		std::cout << "Erase single (key)" << '\n';
		map.erase(k[3]);
		printmap(map, "map");
		assert(map.size() == 3);

		std::cout << "Erase range" << '\n';
		map.erase(it2, ++it3);
		printmap(map, "map");
		assert(map.size() == 1);
	}
	{
		title("Swap");
		NS::map<T, T> swapmapa;
		swapmapa.insert(NS::pair<T, T>(k[0], v[0]));
		swapmapa.insert(NS::pair<T, T>(k[1], v[1]));
		printmap(swapmapa, "swapmapa");
		NS::map<T, T> swapmapb;
		swapmapb.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(swapmapb, "swapmapb");
		std::cout << "Swap maps.." << '\n';
		swapmapa.swap(swapmapb);
		printmap(swapmapa, "swapmapa");
		printmap(swapmapb, "swapmapb");
	}
	{
		title("Clear");
		NS::map<T, T> map;
		map.insert(NS::pair<T, T>(k[0], v[0]));
		map.insert(NS::pair<T, T>(k[1], v[1]));
		map.insert(NS::pair<T, T>(k[2], v[2]));
		printmap(map, "map");
		assert(map.size() == 3);

		std::cout << "Clearing map..." << '\n';
		map.clear();
		printmap(map, "map");
		assert(map.size() == 0);
	}

	chapterend("MODIFIERS OK");
}
void m_testObservers()
{
	chapter("\nOBSERVERS");
	{
		title("Key compare");
		std::map<char, int> map;
		std::map<char, int>::key_compare compare = map.key_comp();

		map['a'] = 100;
		map['b'] = 200;
		map['c'] = 300;

		std::cout << "mymap contains:\n";

		char highest = map.rbegin()->first;     // key value of last element

		int i = 0;
		std::map<char, int>::iterator it = map.begin();
		do {
			i++;
			std::cout << it->first << " => " << it->second << '\n';
		} while (compare((*it++).first, highest));
		std::cout << '\n';
		assert(i == 3);
	}
	
	{
		title("Value compare");
		NS::map<char, int> map;

		map['x'] = 1001;
		map['y'] = 2002;
		map['z'] = 3003;

		std::cout << "mymap contains:\n";

		NS::map<char, int>::iterator itend = map.end();
		itend--;
		NS::pair<char, int> highest = *itend;
		NS::map<char, int>::iterator it = map.begin();
		int i = 0;
		while (map.value_comp()(*it, highest))
		{
			std::cout << it->first << " => " << it->second << '\n';
			it++;
			i++;
		}
		assert(i == 2);
	}

	chapterend("OBSERVERS OK");
}
void m_testOperations()
{
	chapter("\nOPERATORS");
		{
			title("Find");
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[2], v[2]));
			map.insert(NS::pair<T, T>(k[3], v[3]));
			printmap(map, "map");
			NS::map<T, T>::iterator it;
			it = map.find(k[2]);
			std::cout << it->first << " => " << it->second << std::endl;
			assert(it->first == k[2]);
			it = map.find(k[4]);
			if (it == map.end())
				std::cout << "not found, iterator = end()" << std::endl;
		}
		{
			title("Count");
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[1], v[4]));
			printmap(map, "map");
			std::cout << "count k1 = " << map.count(k[0]) << std::endl;
			assert(map.count(k[0]) == 1);
			std::cout << "count k8 = " << map.count(k[7]) << std::endl;
			assert(map.count(k[7]) == 0);
		}
		{
			title("Lower Bound");
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[5], v[5]));
			map.insert(NS::pair<T, T>(k[6], v[6]));
			printmap(map, "map");

			{
				std::cout << "Lower bounds:" << '\n';
				NS::map<T, T>::iterator it;
				it = map.lower_bound(k[1]);
				std::cout << "lowerbound(" << k[1] << ") = " << it->first << std::endl;
				assert(it->first == k[1]);
				it = map.lower_bound(k[0]);
				std::cout << "lowerbound(" << k[0] << ") = " << it->first << std::endl;
				assert(it->first == k[0]);
				it = map.lower_bound(k[3]);
				std::cout << "lowerbound(" << k[3] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.lower_bound(k[6]);
				std::cout << "lowerbound(" << k[6] << ") = " << it->first << std::endl;
				assert(it->first == k[6]);
			}
			{
				std::cout << "\nConst lower bounds:" << '\n';
				NS::map<T, T>::const_iterator it;
				it = map.lower_bound(k[1]);
				std::cout << "lowerbound(" << k[1] << ") = " << it->first << std::endl;
				assert(it->first == k[1]);
				it = map.lower_bound(k[0]);
				std::cout << "lowerbound(" << k[0] << ") = " << it->first << std::endl;
				assert(it->first == k[0]);
				it = map.lower_bound(k[3]);
				std::cout << "lowerbound(" << k[3] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.lower_bound(k[6]);
				std::cout << "lowerbound(" << k[6] << ") = " << it->first << std::endl;
				assert(it->first == k[6]);
			}
			title("Upper Bound");
			{
				std::cout << "Upper bounds:" << '\n';
				NS::map<T, T>::iterator it;
				it = map.upper_bound(k[0]);
				std::cout << "upperbound(" << k[0] << ") = " << it->first << std::endl;
				assert(it->first == k[1]);
				it = map.upper_bound(k[1]);
				std::cout << "upperbound(" << k[1] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.upper_bound(k[3]);
				std::cout << "upperbound(" << k[3] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.upper_bound(k[6]);
				if (it == map.end())
					std::cout << "end()" << std::endl;
				else
					std::cout << "upperbound(" << k[6] << ") = " << it->first << std::endl;
			}
			{
				std::cout << "\nConst upper bounds:" << '\n';
				NS::map<T, T>::const_iterator it;
				it = map.upper_bound(k[0]);
				std::cout << "upperbound(" << k[0] << ") = " << it->first << std::endl;
				assert(it->first == k[1]);
				it = map.upper_bound(k[1]);
				std::cout << "upperbound(" << k[1] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.upper_bound(k[3]);
				std::cout << "upperbound(" << k[3] << ") = " << it->first << std::endl;
				assert(it->first == k[5]);
				it = map.upper_bound(k[6]);
				if (it == map.end())
					std::cout << "end()" << std::endl;
				else
					std::cout << "upperbound(" << k[6] << ") = " << it->first << std::endl;
			}
		}
		{
			title("Equal range");
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[5], v[5]));
			map.insert(NS::pair<T, T>(k[6], v[6]));
			printmap(map, "map");
			{
				std::cout << "Equal range" << '\n';
				NS::pair<NS::map<T, T>::iterator,NS::map<T, T>::iterator> range;
				range = map.equal_range(k[1]);
				std::cout << "equal_range(" << k[1] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[1])); assert(range.second == map.upper_bound(k[1]));
				range = map.equal_range(k[0]);
				std::cout << "equal_range(" << k[0] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[0])); assert(range.second == map.upper_bound(k[0]));
				range = map.equal_range(k[4]);
				std::cout << "equal_range(" << k[4] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[4])); assert(range.second == map.upper_bound(k[4]));
				range = map.equal_range(k[7]);
				if (range.first == map.end() && range.second == map.end())
					std::cout << "equal_range(" << k[7] << ") = <" << "end()" << ", " << "end()" << ">" << std::endl;					
			}
			{
				std::cout << "\nConst equal range" << '\n';
				NS::pair<NS::map<T, T>::const_iterator,NS::map<T, T>::const_iterator> range;
				range = map.equal_range(k[1]);
				std::cout << "equal_range(" << k[1] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[1])); assert(range.second == map.upper_bound(k[1]));
				range = map.equal_range(k[0]);
				std::cout << "equal_range(" << k[0] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[0])); assert(range.second == map.upper_bound(k[0]));
				range = map.equal_range(k[4]);
				std::cout << "equal_range(" << k[4] << ") = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
				assert(range.first == map.lower_bound(k[4])); assert(range.second == map.upper_bound(k[4]));
				range = map.equal_range(k[7]);
				if (range.first == map.end() && range.second == map.end())
					std::cout << "equal_range(" << k[7] << ") = <" << "end()" << ", " << "end()" << ">" << std::endl;	
			}
		}
		{
			title("Get_allocator");
			NS::map<T, T> map;
			NS::pair<T, T> pair = NS::make_pair(k[0], v[0]);
			map.insert(pair);
			printmap(map, "map");
			NS::map<T, T>::allocator_type alloc = map.get_allocator();
			std::cout << "Pair address through allocator = " << alloc.address(pair) << std::endl;
			assert(alloc.address(pair) != 0);
		}

	chapterend("OPERATORS OK");
}
void m_testSpeed()
{
	chapter("Speed test");
	title("Insertion");

	size_t test_size;
	size_t n;
	std::cout << "Map size = 10^n. Enter n:\n";
	std::cin >> n;
	test_size = 1;
	while (n-- > 0)
		test_size *= 10;		

	std::cout << "Create a map with " << test_size << " random int\n";
    srand( (unsigned)time(NULL) );
	NS::map<int,int> map;
	Timer();
	int at10x100, at20x100, at50x100, at80x100;
    while ( map.size() < test_size )
    {
        int random = rand();
        map.insert(NS::make_pair(random, random));
		size_t s = map.size();
		if (s == test_size * 0.1f)
			at10x100 = random;
		else if (s == test_size * 0.2f)
			at20x100 = random;
		else if (s == test_size * 0.5f)
			at50x100 = random;
		else if (s == test_size * 0.8f)
			at80x100 = random;
		if (s == test_size - 1)
			break;
    }
	log("Total seconds = ");
	logn(Timer());

	title("Access all elements");
	NS::map<int,int>::iterator it;
	it = map.begin();
	while ( it != map.end())
    {
        int k = it->first;
		k = 0;
		it++;
    }
	std::cout << '\n';
	log("Total seconds = ");
	logn(Timer());

	title("Random access");
	size_t c = 0;
	std::cout << "Access random elements 10^7 times\n";
	std::cout << "map[" << at10x100 << "]" << std::endl;
	std::cout << "map[" << at20x100 << "]" << std::endl;
	std::cout << "map[" << at50x100 << "]" << std::endl;
	std::cout << "map[" << at80x100 << "]" << std::endl;
	Timer();
	while (c++ < 10000000)
	{
		int k;
		k = map[at10x100];
		k = map[at20x100];
		k = map[at50x100];
		k = map[at80x100];
		k = 0;
	}
	log("Total seconds = ");
	logn(Timer());
}

void map_tests()
{
	chapter("\nT E S T I N G   M A P");

	m_testConstructors();
	m_testOperators();
	m_testIterators();
	m_testCapacity();
	m_testAccess();
	m_testModifiers();
	m_testObservers();
	m_testOperations();
	m_testSpeed();
}