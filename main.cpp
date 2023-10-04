#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <typename T>
int easyfind(const T & haystack, const int & needle)
{
	typename T::const_iterator result;

	result = find(haystack.begin(), haystack.end(), needle);

	if (result == haystack.end())
	{
		std::cout << "Pas trouve mon frere" << std::endl;
	}


	return 800800;
}

int main ()
{
	std::vector<int> vector0;

	vector0.push_back(3);
	vector0.push_back(1);
	vector0.push_back(4);
	vector0.push_back(28000000);

	std::cout << easyfind(vector0, 45) << std::endl;

	return 0;
}