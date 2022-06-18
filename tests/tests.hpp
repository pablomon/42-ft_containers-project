#if !defined(TESTS_HPP)
#define TESTS_HPP

#include <iostream>
#include <fstream>
#include <assert.h>
#include <time.h>
#include "../utils/utils.hpp"

// types
#ifndef STD
# define NS ft
#else
# define NS std
#endif

void vector_tests();
void stack_tests();
void map_tests();

#endif // TESTS_HPP
