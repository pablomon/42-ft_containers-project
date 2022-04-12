// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "containers/map.hpp"
#include <map>

#define log(x) std::cout << x << std::endl
#define NS ft

void printmap(NS::map<std::string, std::string> mapa, std::string name)
{
	std::cout << "printing " << name << ":" << std::endl;
	std::cout << "size = " << mapa.size() << std::endl;
	for (NS::map<std::string, std::string>::iterator it = mapa.begin(); it != mapa.end(); it++)
		std::cout << it->first << std::endl;
	std::cout << std::endl;
}


int main()
{
	{
		NS::map<std::string, std::string> mapa;
		NS::map<std::string, std::string>::iterator it1 = mapa.insert(NS::pair<std::string, std::string>("k1", "v1")).first;
		mapa.insert(it1, NS::pair<std::string, std::string>("k3", "v3"));
		NS::map<std::string, std::string>::iterator it2 = mapa.insert(NS::pair<std::string, std::string>("k2", "v2")).first;
		printmap(mapa, "mapa");
		NS::map<std::string,std::string> mapa2 = mapa;
		printmap(mapa2, "mapa2");
		log("erase k1 y k2");
		mapa.erase("k1");
		mapa.erase("k2");
		printmap(mapa, "mapa");
		log("insert mapa2 begin to end in mapa");
		mapa.insert(mapa2.begin(), mapa2.end());

		printmap(mapa, "mapa");
		printmap(mapa2, "mapa2");

		mapa2.erase(mapa2.begin(), mapa2.begin()++);
		std::cout << mapa.size() << std::endl;

		NS::map<std::string, std::string> mapa3(mapa2.begin(), mapa2.end());
		printmap(mapa3, "mapa3");

		NS::map<std::string, std::string> mapa4;
		printmap(mapa4, "mapa4");

		NS::map<std::string, std::string>::iterator ite1 = mapa.insert(NS::pair<std::string, std::string>("e1", "e1")).first;
		NS::map<std::string, std::string>::iterator ite2 = mapa.insert(NS::pair<std::string, std::string>("e2", "e2")).first;
		mapa4.erase(ite1, ite2);
		printmap(mapa4, "mapa4");

		std::cout << "-------" << std::endl;
		NS::map<std::string, std::string>::iterator itebegin = mapa4.begin();
		NS::map<std::string, std::string>::iterator iteend = mapa4.end();
		for (NS::map<std::string, std::string>::iterator it = itebegin; it != iteend; it++)
			std::cout << it->first << std::endl;
		std::cout << "-------" << std::endl;

		//access
		std::cout << "-------" << std::endl;
		NS::map<std::string, std::string> access_map;
		access_map.insert(NS::pair<std::string, std::string>("acc1", "acc1"));
		access_map["acc1"];
		access_map["acc2"];
		
		std::cout << access_map["acc1"] << std::endl;
		std::cout << access_map["acc2"] << std::endl;
		std::cout << "-------" << std::endl;
		
		NS::map<std::string, std::string> endmap;
		endmap.insert(NS::pair<std::string, std::string>("em1", "em1"));
		NS::map<std::string, std::string>::iterator itembegin = endmap.begin();

		std::cout << (itembegin)->first << std::endl;

		itembegin--;
		itembegin--;

		std::cout << (itembegin)->first << std::endl;

		NS::map<std::string, std::string>::iterator itend = endmap.end();
		endmap.insert(NS::pair<std::string, std::string>("em2", "em2"));

		std::cout << (--itend)->first << std::endl;

		NS::map<std::string, std::string>::iterator itend2 = endmap.end();
		std::cout << (--itend2)->first << std::endl;
		std::cout << "-------" << std::endl;
		
		//clear
		std::cout << "-------" << std::endl;
		NS::map<std::string, std::string> clearmap;
		clearmap.insert(NS::pair<std::string, std::string>("cm1", "cm1"));
		clearmap.insert(NS::pair<std::string, std::string>("cm2", "cm2"));
		printmap(clearmap, "clear map");

		clearmap.clear();
		printmap(clearmap, "clear map");
		std::cout << "-------" << std::endl;

		//swap
		std::cout << "-------" << std::endl;
		NS::map<std::string, std::string> swapmapa;
		swapmapa.insert(NS::pair<std::string, std::string>("swa1", "swa1"));
		swapmapa.insert(NS::pair<std::string, std::string>("swa2", "swa2"));
		printmap(swapmapa, "swapmapa");
		NS::map<std::string, std::string> swapmapb;
		swapmapb.insert(NS::pair<std::string, std::string>("swb1", "swb1"));
		printmap(swapmapb, "swapmapb");

		swapmapa.swap(swapmapb);
		printmap(swapmapa, "swapmapa");
		printmap(swapmapb, "swapmapb");
	}
}