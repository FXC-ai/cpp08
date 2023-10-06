#include <iostream>
#include <algorithm>
#include <stack>

template <typename T, >
class MutantStack : public std::stack<T, class >
{
	public :
	 	MutantStack(){};

		deque<T>::iterator begin()
		{
			return deque<T>::iterator it; 
		}

};

int main()
{
	MutantStack<int> mutant0;


	mutant0.push(14);

	std::cout << mutant0.top() <<std::endl;

	return 0;
}