#include "Span.hpp"
#include <cstdlib>
#include <ctime>

class Display
{
	public:
		void operator()(int a) const
		{
			std::cout << a << std::endl;
		}
};

class GiveRandNumb
{
	private :
		const int _modulo;

	public :
		GiveRandNumb() : _modulo(0){};
		GiveRandNumb(const int n) : _modulo(n){};
		~GiveRandNumb(){};

		int operator()(){return rand() % this->_modulo;};
};

int main()
{
	const int N = 10;

	srand(time(NULL));

	std::vector<int> randomNumbers(7);

	GiveRandNumb giveRandN(N);

	std::generate(randomNumbers.begin(), randomNumbers.end(), giveRandN);

	std::vector<int> copy(2);

	copy = randomNumbers;
	for_each(randomNumbers.begin(), randomNumbers.end(), Display());
	std::cout << std::endl;
	//for_each(copy.begin(), copy.end(), Display());

	Span span0;
	std::cout << "span0 " << "size = " << span0.size() << " " << span0.get_datas().size() << std::endl;
	try
	{
		span0.addNumber(18);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	Span span1(2);
	std::cout << "span1 " << "size = " << span1.size() << " " << span1.get_datas().size() << std::endl;

	span1.addNumber(18);
	span1.addNumber(19);
	std::cout << "span1 " << "size = " << span1.size() << " " << span1.get_datas().size() << std::endl;


	std::cout << "TEST = " << *(span1.get_datas().end() - 1) << std::endl;
	for_each(span1.get_datas().begin(), span1.get_datas().end(), Display());


	std::cout << "---------- SPAN 2 ---------" << std::endl;

	Span span2(10);

	span2.addNumber(48);
	span2.addNumber(49);
	span2.addNumber(59);

	for_each(span2.get_datas().begin(), span2.get_datas().end(), Display());

	span2.addNumbers(randomNumbers.begin(), randomNumbers.end());

	// span0.addNumber(19);
	// std::cout << "size = " << span0.size() << " " << span0.get_datas().size() << std::endl;



	//for_each(span2.get_datas().begin(), span2.get_datas().end(), Display());



	// Span span1(10);

	// //span1.fill(2);
	// span1.fillRandomly(10000);
	// //span1.fillRandomly(0);

	// span1.addNumbers(randomNumbers.begin(), randomNumbers.end());

	// std::cout << "maxi = " << span1.max() << " mini = " << span1.min() << " Distance = " << span1.longestSpan() << std::endl;	// std::cout << span1;

	// span1.shortestSpan();
	// for (unsigned int i = 0; i < span1.get_N(); ++i)
	// {
	// 	std::cout << span1.get_datas()[i] << " ";
	// }

	// std::cout<<std::endl;

	// std::cout << "shortest span = " << span1.shortestSpan() << std::endl;

	return 0;
}