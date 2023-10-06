#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	 	MutantStack()
		{
		

		};

		// std::deque<T>::iterator begin()
		// {

		// 	return std::deque<T>::iterator it; 
		// }


		void debile()
		{
			std::cout << this->c.front() <<std::endl;
			

		}

};

int main()
{
	MutantStack<int> mutant0;


	mutant0.push(14);

	std::cout << mutant0.top() <<std::endl;

	mutant0.debile();


	return 0;
}