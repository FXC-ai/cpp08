#include "easyfind.hpp"
#include <vector>
#include <deque>

int main ()
{
	std::vector<int> vector0;

	vector0.push_back(3);
	vector0.push_back(1);
	vector0.push_back(4);
	vector0.push_back(28000000);

	if (easyfind(vector0, 55) == vector0.end())
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found" << std::endl;
	}

	std::deque<int> deque0;

	deque0.push_back(3);
	deque0.push_back(1);
	deque0.push_back(4);
	deque0.push_back(28000000);

	if (easyfind(deque0, 28000000) == deque0.end())
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found" << std::endl;
	}

	return 0;
}