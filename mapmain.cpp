// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "containers/map.hpp"
#include "tests/tests.hpp"
#include <map>

#define NS ft

#define T std::string
std::string k[] = { "k1", "k2", "k3", "k4", "k5", "k6", "k7"};
std::string v[] = { "v1", "v2", "v3", "v4", "v5", "v6", "v7"};

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

void m_iterators()
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

void m_capacity()
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
void m_access()
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

int main()
{
	chapter("\nT E S T I N G   M A P");

	m_testConstructors();
	m_testOperators();
	m_iterators();
	m_capacity();
	m_access();

	return 0;

	{
		NS::map<T, T> mapaend;
		mapaend.insert(NS::pair<T, T>(k[0], v[0]));
		// Esto tiene que dar un segfault
		//NS::map<T, T>::iterator itmapaend = mapaend.end();
		//std::cout << "Printing end() : " << itmapaend->first << std::endl;

		NS::map<T, T> mapa;
		NS::map<T, T>::iterator it1 = mapa.insert(NS::pair<T, T>(k[0], v[0])).first;
		mapa.insert(it1, NS::pair<T, T>(k[2], v[2]));
		NS::map<T, T>::iterator it2 = mapa.insert(NS::pair<T, T>(k[1], v[1])).first;
		printmap(mapa, "mapa");
		NS::map<T,T> mapa2 = mapa;
		printmap(mapa2, "mapa2");
		log("erase k1 y k2");
		mapa.erase(k[0]);
		mapa.erase(k[1]);
		printmap(mapa, "mapa");
		log("insert mapa2 begin to end in mapa");
		mapa.insert(mapa2.begin(), mapa2.end());

		printmap(mapa, "mapa");
		printmap(mapa2, "mapa2");

		mapa2.erase(mapa2.begin(), mapa2.begin()++);
		std::cout << mapa.size() << std::endl;

		NS::map<T, T> mapa3(mapa2.begin(), mapa2.end());
		printmap(mapa3, "mapa3");

		NS::map<T, T> mapa4;
		printmap(mapa4, "mapa4 hola");

		NS::map<T, T>::iterator ite1 = mapa.insert(NS::pair<T, T>("e1", "e1")).first;
		NS::map<T, T>::iterator ite2 = mapa.insert(NS::pair<T, T>("e2", "e2")).first;
		mapa4.erase(ite1, ite2);
		printmap(mapa4, "mapa4");

		std::cout << "-------" << std::endl;
		NS::map<T, T>::iterator itebegin = mapa4.begin();
		NS::map<T, T>::iterator iteend = mapa4.end();
		for (NS::map<T, T>::iterator it = itebegin; it != iteend; it++)
			std::cout << it->first << std::endl;
		std::cout << "-------" << std::endl;

		//access
		std::cout << "-------" << std::endl;
		NS::map<T, T> access_map;
		access_map.insert(NS::pair<T, T>("acc1", "acc1"));
		access_map["acc1"];
		access_map["acc2"];
		
		std::cout << access_map["acc1"] << std::endl;
		std::cout << access_map["acc2"] << std::endl;
		std::cout << "-------" << std::endl;
		
		NS::map<T, T> endmap;
		endmap.insert(NS::pair<T, T>("em1", "em1"));
		NS::map<T, T>::iterator itembegin = endmap.begin();

		std::cout << (itembegin)->first << std::endl;

		itembegin--;
		itembegin--;

		std::cout << (itembegin)->first << std::endl;

		NS::map<T, T>::iterator itend = endmap.end();
		endmap.insert(NS::pair<T, T>("em2", "em2"));

		std::cout << (--itend)->first << std::endl;

		NS::map<T, T>::iterator itend2 = endmap.end();
		std::cout << (--itend2)->first << std::endl;
		std::cout << "-------" << std::endl;
		
		//clear
		std::cout << "-------" << std::endl;
		NS::map<T, T> clearmap;
		clearmap.insert(NS::pair<T, T>("cm1", "cm1"));
		clearmap.insert(NS::pair<T, T>("cm2", "cm2"));
		printmap(clearmap, "clear map");

		clearmap.clear();
		printmap(clearmap, "clear map");
		std::cout << "-------" << std::endl;

		//swap
		std::cout << "-------" << std::endl;
		NS::map<T, T> swapmapa;
		swapmapa.insert(NS::pair<T, T>("swa1", "swa1"));
		swapmapa.insert(NS::pair<T, T>("swa2", "swa2"));
		printmap(swapmapa, "swapmapa");
		NS::map<T, T> swapmapb;
		swapmapb.insert(NS::pair<T, T>("swb1", "swb1"));
		printmap(swapmapb, "swapmapb");

		swapmapa.swap(swapmapb);
		printmap(swapmapa, "swapmapa");
		printmap(swapmapb, "swapmapb");

		//size and maxsize
		std::cout << "-------" << std::endl;
		NS::map<T, T> sizemap;
		printmap(sizemap, "size map");
		sizemap.insert(NS::pair<T, T>("sm1", "sm1"));
		sizemap.insert(NS::pair<T, T>("sm2", "sm2"));
		sizemap.insert(NS::pair<T, T>("sm3", "sm3"));
		sizemap.insert(NS::pair<T, T>("sm4", "sm4"));
		printmap(sizemap, "size map");
		sizemap.erase("sm1");
		printmap(sizemap, "size map");
		sizemap.erase(sizemap.begin(), sizemap.end());
		printmap(sizemap, "size map");
		log("max size:");
		log(sizemap.max_size());
		std::cout << "-------" << std::endl;

		//key compare
		{
			std::cout << "-------" << std::endl;
			std::map<char, int> mymap;

			std::map<char, int>::key_compare mycomp = mymap.key_comp();

			mymap['a'] = 100;
			mymap['b'] = 200;
			mymap['c'] = 300;

			std::cout << "mymap contains:\n";

			char highest = mymap.rbegin()->first;     // key value of last element

			std::map<char, int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while (mycomp((*it++).first, highest));

			std::cout << '\n';
			std::cout << "-------" << std::endl;
		}
		
		//value compare
		{
			NS::map<char, int> mymap;

			mymap['x'] = 1001;
			mymap['y'] = 2002;
			mymap['z'] = 3003;

			std::cout << "mymap contains:\n";

			NS::map<char, int>::iterator itend = mymap.end();
			itend--;
			NS::pair<char, int> highest = *itend;
			NS::map<char, int>::iterator it = mymap.begin();
			while (mymap.value_comp()(*it, highest))
			{
				std::cout << it->first << " => " << it->second << '\n';
				it++;
			}
		}

		//find
		{
			std::cout << "-------" << std::endl;
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[2], v[2]));
			map.insert(NS::pair<T, T>(k[3], v[3]));
			printmap(map, "map");
			NS::map<T, T>::iterator it;
			it = map.find(k[2]);
			std::cout << it->first << " => " << it->second << std::endl;
			it = map.find(k[4]);
			if (it == map.end())
				std::cout << "not found, iterator = end()" << std::endl;
			std::cout << "-------" << std::endl;
		}

		//count
		{
			std::cout << "-------" << std::endl;
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			printmap(map, "map");
			std::cout << "count k1 = " << map.count(k[0]) << std::endl;
			std::cout << "count k666 = " << map.count("k666") << std::endl;
			std::cout << "-------" << std::endl;
		}

		//bounds and equal_range
		{
			std::cout << "-------" << std::endl;
			NS::map<T, T> map;
			map.insert(NS::pair<T, T>(k[0], v[0]));
			map.insert(NS::pair<T, T>(k[1], v[1]));
			map.insert(NS::pair<T, T>(k[5], v[5]));
			map.insert(NS::pair<T, T>(k[6], v[6]));
			printmap(map, "map");

			NS::map<T, T>::iterator it;

			it = map.lower_bound(k[0]);
			std::cout << "lowerbound(k1) = " << it->first << std::endl;
			it = map.lower_bound("k0");
			std::cout << "lowerbound(k0) = " << it->first << std::endl;
			it = map.lower_bound(k[3]);
			std::cout << "lowerbound(k4) = " << it->first << std::endl;
			it = map.lower_bound(k[6]);
			std::cout << "lowerbound(k7) = " << it->first << std::endl;
			std::cout << "-------" << std::endl;

			it = map.upper_bound(k[0]);
			std::cout << "upperbound(k1) = " << it->first << std::endl;
			it = map.upper_bound("k0");
			std::cout << "upperbound(k0) = " << it->first << std::endl;
			it = map.upper_bound(k[3]);
			std::cout << "upperbound(k4) = " << it->first << std::endl;
			it = map.upper_bound(k[6]);

			if (it == map.end())
				std::cout << "equal" << std::endl;
			else
				std::cout << "upperbound(k7) = " << it->first << std::endl;

			NS::map<T, T>::const_iterator cit;
			cit = map.lower_bound(k[0]);
			std::cout << "const lowerbound(k1) = " << cit->first << std::endl;
			cit = map.lower_bound("k0");
			std::cout << "const lowerbound(k0) = " << cit->first << std::endl;
			cit = map.lower_bound(k[3]);
			std::cout << "const lowerbound(k4) = " << cit->first << std::endl;
			std::cout << "-------" << std::endl;

			NS::pair<NS::map<T, T>::iterator,NS::map<T, T>::iterator> range;
			range = map.equal_range(k[1]);
			std::cout << "equal_range(k2) = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
			range = map.equal_range("k0");
			std::cout << "equal_range(k0) = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
			range = map.equal_range(k[4]);
			std::cout << "equal_range(k5) = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
			range = map.equal_range("k10");
			std::cout << "equal_range(k10) = <" << range.first->first << ", " << range.second->first << ">" << std::endl;
		}
	}

	return 0;
}