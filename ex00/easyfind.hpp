#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


// template <typename T>
// int easyfind(const T & haystack, const int & needle)
// {
// 	typename T::const_iterator result;

// 	result = find(haystack.begin(), haystack.end(), needle);

// 	if (result == haystack.end())
// 	{
// 		throw std::exception();
// 	}


// 	return *result;
// }

template <typename T>
typename T::const_iterator easyfind(const T & haystack, const int & needle)
{
	typename T::const_iterator result;

	result = find(haystack.begin(), haystack.end(), needle);


	return result;
}



#endif