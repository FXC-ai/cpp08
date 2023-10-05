#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>


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


class Span
{

	public :
		Span();
		Span(unsigned int N);
		Span(const Span & src);
		~Span();

		Span & operator=(const Span & rhs);
		unsigned int 		get_N() const;
		std::vector<int>	get_datas() const;

		void				addNumber(int n);
		void				addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
		void				fillRandomly(int max);
		size_t				size();
		int					longestSpan();
		int					shortestSpan();
		int					min();
		int					max();

	private :
		std::vector<int>	_datas;
		unsigned int 			_N;


};

Span::Span() : _N(1){}

Span::Span(unsigned int N) : _N(N){}

Span::Span(const Span & src) : _N(src.get_N())
{
	this->_datas = src.get_datas();
}

Span::~Span(){};

Span & Span::operator=(const Span & rhs)
{
	if (&rhs != this)
	{
		this->_N = rhs.get_N();
		this->_datas = rhs.get_datas();
	}
	return *this;
}

unsigned int Span::get_N() const
{
	return this->_N;
}

std::vector<int>	Span::get_datas() const
{
	return this->_datas;
}

void Span::addNumber(int n)
{
	if (this->_datas.size() == this->_N)
	{
		throw std::exception();
	}
	this->_datas.push_back(n);
}

// void Span::fill(int value)
// {
// 	this->_datas.resize(this->_N, value);
// }

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{

	std::cout << "DISTANCE = "<< distance(first, last) << std::endl;


	// if (this->size() < this->_N)
	// {
	// 	for (size_t index = this->size(); index < N; ++index)
	// 	{
	// 		this->_datas[index] = *(first + index);
	// 	}
	// }



}



void Span::fillRandomly(int max)
{

	GiveRandNumb giveRandN(max);
	
	if (this->size() < this->_N)
	{
		for (size_t index = this->size(); index < this->_N; ++index)
		{
			this->addNumber(giveRandN());
		}
	}
	else
	{
		generate(this->_datas.begin(), this->_datas.end(), giveRandN);
	}
}

size_t Span::size()
{
	return this->_datas.size();
}

int Span::longestSpan()
{
	if (this->size() <= 1)
	{
		throw std::exception();
	}

	return this->max() - this->min();
}

int Span::shortestSpan()
{
	if (this->size() <= 1)
	{
		throw std::exception();
	}
	sort(this->_datas.begin(), this->_datas.end());
	return this->_datas[1] - this->_datas[0];
}

int Span::min()
{
	std::vector<int>::iterator mini = min_element(this->_datas.begin(), this->_datas.end());
	return *mini;
}

int Span::max()
{
	std::vector<int>::iterator maxi = max_element(this->_datas.begin(), this->_datas.end());
	return *maxi;
}


class Display
{
	public:
		void operator()(int a) const
		{
			std::cout << a << std::endl;
		}


};




int main()
{
	int N = 10;


	srand(time(NULL));
	// unsigned int imax = std::numeric_limits<unsigned int>::max();
	// std::cout << imax << std::endl;
	std::vector<int> randomNumbers(N);

	GiveRandNumb giveRandN(N);

	std::generate(randomNumbers.begin(), randomNumbers.end(), giveRandN);

	for_each(randomNumbers.begin(), randomNumbers.end(), Display());

	Span span0;
	Span span1(10);

	//span1.fill(2);
	span1.fillRandomly(10000);
	//span1.fillRandomly(0);

	span1.addNumbers(randomNumbers.begin(), randomNumbers.end());

	std::cout << "maxi = " << span1.max() << " mini = " << span1.min() << " Distance = " << span1.longestSpan() << std::endl;	// std::cout << span1;

	span1.shortestSpan();
	for (unsigned int i = 0; i < span1.get_N(); ++i)
	{
		std::cout << span1.get_datas()[i] << " ";
	}

	std::cout<<std::endl;

	std::cout << "shortest span = " << span1.shortestSpan() << std::endl;

	return 0;
}