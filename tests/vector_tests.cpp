#include "tests.hpp"
#include "../containers/vector.hpp"
#include <vector>

// #define T std::string
// std::string val[] = { "11", "22", "33", "42", "666", "66", "77", "88"};

#define T int
int val[] = { 11,22,33,42,666,66,77,88 };

template <class U, class Alloc>
int	cmp(const NS::vector<U, Alloc> &lhs, const NS::vector<U, Alloc> &rhs)
{
	int res = 0;
	std::cout << "=============\n";
	std::cout << "eq: " << (lhs == rhs);
	res += (lhs == rhs); res = res << 1;
	std::cout << " | ne: " << (lhs != rhs) << std::endl;
	res += (lhs != rhs); res = res << 1;
	std::cout << "lt: " << (lhs < rhs);
	res += (lhs < rhs); res = res << 1;
	std::cout << " | le: " << (lhs <= rhs) << std::endl;
	res += (lhs <= rhs); res = res << 1;
	std::cout << "gt: " << (lhs >  rhs);
	res += (lhs > rhs); res = res << 1;
	std::cout << " | ge: " << (lhs >= rhs) << std::endl;
	res += (lhs >= rhs); res = res << 1;
	std::cout << "=============\n";
	std::cout << "res = " << res << "\n";
	return res;
}

template <typename U>
void PrintVector(const NS::vector<U>& vector, std::string name)
{
	std::cout << "  Vector " << name << ":\n";
	std::cout << "  size = " << vector.size() << ", ";
	std::cout << "capacity = " << vector.capacity() << std::endl;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << "  [" << i << "] = " << vector[i] << std::endl;
}

void v_testConstructors()
{
	chapter("\nCONSTRUCTORS");
	{
		title("Empty constructor");
		NS::vector<T> v = NS::vector<T>();
		PrintVector(v, "v");
	}
	{
		title("Fill constructor");
		NS::vector<T> v = NS::vector<T>(4, val[0]);
		assert(v[3] == val[0]);
		PrintVector(v, "v");
	}
	{
		title("Range constructor");
		NS::vector<T> vo = NS::vector<T>();
		vo.push_back(val[0]);
		vo.push_back(val[1]);
		vo.push_back(val[2]);
		PrintVector(vo, "vo");

		NS::vector<T> v = NS::vector<T>(vo.begin(), vo.end());
		assert(v[2] == val[2]);
		PrintVector(v, "v");
	}

	chapterend("CONSTRUCTORS OK");
}

void v_testAccess()
{
	chapter("\nELEMENT ACCESS");

	NS::vector<T> v;
	v.push_back(val[0]);
	v.push_back(val[1]);
	v.push_back(val[2]);
	assert(v[2] == val[2]);
	PrintVector(v, "v");

	title("Operator []");
	log("Value at pos 2: ");
	assert(v[2] == val[2]);
	logn(v[2]);
	// The following throws a heap-overflow on mac
	// log("Value at pos 100: ");
	// logn(v[100]);

	title("at");
	try
	{
		log("Value at pos 2: ");
		assert(v[2] == val[2]);
		logn(v.at(2));
		log("Value at pos 100: ");
		logn(v.at(100));
	}
	catch(const std::exception& e)
	{
		std::cout << "Catch:" << std::endl;
		std::cerr << e.what() << '\n';
	}

	title("Front & back");
	log("Front: ");
	assert(v.front() == v[0]);
	logn(v.front());
	log("Back: ");
	assert(v.back() == v[2]);
	logn(v.back());
	logn("Removng elements 1 and 2");
	v.pop_back();
	v.pop_back();
	log("Front: ");
	assert(v.front() == v[0]);
	logn(v.front());
	log("Back: ");
	assert(v.back() == v[0]);
	logn(v.back());

	chapterend("ACCESS OK");
}

void v_testModifiers()
{
	chapter("\nMODIFIERS");

	NS::vector<T> v = NS::vector<T>();
	PrintVector(v, "v");

	title("push_back");
	v.push_back(val[0]);
	v.push_back(val[1]);
	v.push_back(val[2]);
	assert(v[2] == val[2]);
	PrintVector(v, "v");

	title("range assign");
	logn("create v2");
	NS::vector<T> v2 = NS::vector<T>(5, val[3]);
	PrintVector(v2, "v2");
	logn("assign v to v2");
	v2.assign(v.begin(), v.end());
	assert(v2[2] == val[2]);
	PrintVector(v2, "v2");

	title("fill assign");
	v2.assign(6, val[3]);
	assert(v2[5] == val[3]);
	PrintVector(v2, "v2");

	title("pop back");
	for (size_t i = 0; i < 6; i++)
	{
		logn(i);
		v2.pop_back();
	}
	PrintVector(v2, "v2");

	title("Insert single element");
	PrintVector(v, "v");
	logn("Insert 42 at the beginnig + 2");
	NS::vector<T>::iterator it = v.insert(v.begin() + 2, val[3]);
	assert(v[2] == val[3]);
	PrintVector(v, "v");
	logn("Insert 42 at the end");
	v.insert(v.end(), val[3]);
	assert(v[4] == val[3]);
	PrintVector(v, "v");

	title("Insert fill");
	logn("Insert  3 666s at the beginnig + 1");
	v.insert(++v.begin(), 3, val[4]);
	assert(v[1] == val[4]);
	assert(v[3] == val[4]);
	PrintVector(v, "v");

	title("Insert range");
	NS::vector<T> v3;
	v3.push_back(val[0]);
	v3.push_back(val[1]);
	v3.push_back(val[2]);
	PrintVector(v, "v3");
	logn("Insert vector3 into second position");
	v.insert(v.begin() + 2, v3.begin(), v3.end());
	assert(v[2] == val[0]);
	assert(v[4] == val[2]);
	PrintVector(v, "v");

	title("Erase single");
	logn("Erase vector v pos 2");
	it = v.erase(v.begin() + 2);
	std::cout << *it << std::endl;
	assert(*it == val[1]);
	log("return iterator value = ");
	logn(*it);
	PrintVector(v, "v");

	title("Erase range");
	logn("Erase everything in v except first and last");
	it = v.erase(++v.begin(), --v.end());
	assert(*it == val[3]);
	log("return iterator value = ");
	logn(*it);
	PrintVector(v, "v");

	title("Swap");
	logn("Vector v:");
	PrintVector(v, "v");
	logn("Vector v3:");
	PrintVector(v3, "v3");
	NS::vector<T>::iterator it1 = v.begin() + 1;
	T it1val = *it1;
	std::cout << "it1 = v.begin() + 1 = " << *it1 << std::endl;
	NS::vector<T>::iterator it2 = v3.begin() + 1;
	T it2val = *it2;
	std::cout << "it2 = v3.begin() + 1 = " << *it2 << std::endl;
	 
	logn("Swap vectors:");
	v.swap(v3);
	assert(v[2] == val[2]);
	assert(v3[1] == val[3]);
	PrintVector(v, "v");
	std::cout << "it1 = " << *it1 << std::endl;
	PrintVector(v3, "v3");
	std::cout << "it2 = " << *it2 << std::endl;

	assert(*it1 == it1val);
	assert(*it2 == it2val);

	logn("Using it2 with vector v ( print until it2 == v.end() ):");
	for(; it2 != v.end(); it2++)
		std::cout << "it2 = " << *it2 << std::endl;

	title("\nClear");
	v.clear();
	assert(v.size() == 0);
	PrintVector(v, "v");

	chapterend("MODIFIERS OK");
}

void v_testCapacity()
{
	chapter("\nCAPACITY");
	NS::vector<T> v = NS::vector<T>();
	v.push_back(val[0]);
	v.push_back(val[1]);
	v.push_back(val[2]);
	assert(v[2] == val[2]);
	PrintVector(v, "v");

	title("size");
	logn(v.size());

	title("max_size");
	logn(v.max_size());

	title("resize");
	logn("resize to 10 elements");
	v.resize(10);
    assert(v[9] == T());
	PrintVector(v, "v");
	logn("resize to 2 elements");
	v.resize(2);
	assert(v.size() == 2);
	PrintVector(v, "v");

	title("reserve");
	logn("reserve at least 15 elements");
	v.reserve(15);
	assert(v.capacity() >= 15);
	PrintVector(v, "v");
	chapterend("\nCAPACITY OK");
}

void v_testIterators()
{
	chapter("\nITERATORS");
	title("NON CONST ITERATORS");
	{
		log("Create vector v with 3 values");
		NS::vector<T> v;
		v.push_back(val[0]);
		v.push_back(val[1]);
		v.push_back(val[2]);
		assert(v[2] == val[2]);
		PrintVector(v, "v");

		title("begin");
		logn("Begin value:");
		NS::vector<T>::iterator it = v.begin();
		logn(*it);
		assert(*it == val[0]);
		logn("Begin + 1 value:");
		assert(*(v.begin() + 1) == val[1]);
		logn(*(v.begin() + 1));

		title("end");
		logn("End - 1 value:");
		assert(*(v.end() - 1) == val[2]);
		logn(*(v.end() - 1));
		logn("End - 2 value:");
		assert(*(v.end() - 2) == val[1]);
		logn(*(v.end() - 2));
	}

	{
		title("REVERSE ITERATORS");
		log("Create vector v with 3 values");
		NS::vector<T> v;
		v.push_back(val[0]);
		v.push_back(val[1]);
		v.push_back(val[2]);
		assert(v[2] == val[2]);
		PrintVector(v, "v");

		title("rbegin");
		logn("rbegin value:");
		assert(*(v.rbegin()) == val[2]);
		logn(*(v.rbegin()));
		logn("rbegin + 1 value:");
		logn(*(v.rbegin() + 1));
		assert(*(v.rbegin() + 1) == val[1]);

		title("rend");
		logn("rend - 1 value:");
		assert(*(v.rend() - 1) == val[0]);
		logn(*(v.rend() - 1));
		logn("rend - 2 value:");
		assert(*(v.rend() - 2) == val[1]);
		logn(*(v.rend() - 2));
	}

	title("CONST ITERATORS");
	{
		log("Create vector v with 3 values");
		NS::vector<T> v;
		v.push_back(val[0]);
		v.push_back(val[1]);
		v.push_back(val[2]);
		assert(v[2] == val[2]);
		PrintVector(v, "v");

		title("const begin");
		logn("Begin value:");
		NS::vector<T>::const_iterator it;
		it = v.begin();
		logn(*it);
		assert(*it == val[0]);
		logn("Begin + 1 value:");
		assert(*(it + 1) == val[1]);
		logn(*(it + 1));
	}

	{
		title("CONST REVERSE ITERATORS");
		log("Create vector v with 3 values");
		NS::vector<T> v;
		v.push_back(val[0]);
		v.push_back(val[1]);
		v.push_back(val[2]);
		assert(v[2] == val[2]);
		PrintVector(v, "v");

		title("rbegin");
		logn("rbegin value:");
		NS::vector<T>::const_reverse_iterator rit;
		rit = v.rbegin();
		assert(*(rit) == val[2]);
		logn(*(rit));
		logn("rbegin + 1 value:");
		rit = v.rbegin() + 1;
		logn(*(rit));
		assert(*(rit) == val[1]);
	}

	chapterend("ITERATORS OK");
}

void v_relational_operators()
{
	chapter("\nRelational operators");
	NS::vector<T> v1(4);
	NS::vector<T> v2(4);

	int res;
	PrintVector(v1, "v1");
	PrintVector(v2, "v2");
	title("Comparison to itself");
	logn("v1 VS v1");
	res = cmp(v1, v1);
	assert(res = 74);

	title("Comparison to an equal vector");
	logn("v1 VS v2");
	res = cmp(v1, v2);
	assert(res = 74);

	title("Comparison to a different sized vector");
	logn("Resize v2 to 10\n");
	v2.resize(10);
	logn("v1 VS v2");
	res = cmp(v1, v2);
	assert(res = 56);
	logn("v2 VS v1");
	res = cmp(v2, v1);
	assert(res = 38);

	title("Comparison to a vector with different contents");
	logn("Set v1[2] to 42\n");
	v1[2] = 42;
	PrintVector(v1, "v1");
	logn("\nv1 VS v2");
	res = cmp(v1, v2);
	assert(res = 38);
	logn("v2 VS v1");
	res = cmp(v2, v1);
	assert(res = 56);

	title("Swap");
	logn("Swap v1 and v2\n");
	swap(v1, v2);
	logn("v1 VS v2");
	res = cmp(v1, v2);
	assert(res = 56);
	logn("v2 VS v1");
	res = cmp(v2, v1);
	assert(res = 38);

	chapterend("RELATIONAL OPERATORS OK");
}

void v_speedTest()
{
# define VECTOR_TEST_SIZE 10000000
	chapter("\nSpeed test");
	title("Allocation");
	std::cout << "Create a vector with " << VECTOR_TEST_SIZE << " strings\n";
	NS::vector<std::string> v;
	Timer();
	for (size_t i = 0; i < VECTOR_TEST_SIZE; i++)
		v.push_back(ToString(i));
	log("total s = ");
	logn(Timer());	

	title("Access");
	std::cout << "Access " << VECTOR_TEST_SIZE << " strings\n";
	std::string s;
	Timer();
	for (size_t i = 0; i < v.size(); i++)
		s = v[i];
	log("total s = ");
	logn(Timer());

	title("Copy");
	size_t copyTimes = 10;
	std::cout << "Copy v "<< copyTimes << " times" << std::endl;
	Timer();
	for (size_t i = 0; i < copyTimes; i++)
		NS::vector<std::string> nv = v;
	log("total s = ");
	logn(Timer());
}

void vector_tests()
{
	chapter("\nT E S T I N G   V E C T O R");
	v_testConstructors();
	v_testCapacity();
	v_testAccess();
	v_testModifiers();
	v_testIterators();
	v_relational_operators();
	v_speedTest();
}
