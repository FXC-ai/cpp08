#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T & haystack, const int & needle)
{
	typename T::const_iterator result;

	result = find(haystack.begin(), haystack.end(), needle);


	return result;
}



#endif