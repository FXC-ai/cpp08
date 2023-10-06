#include "Span.hpp"

Span::Span() : _N(0){}

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

const std::vector<int>&	Span::get_datas() const
{
	return this->_datas;
}

void Span::addNumber(int n)
{
	if (this->_datas.size() >= this->_N)
	{
		throw SpanInsufficientSize();
	}
	this->_datas.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	size_t ini_size = this->size();
	long avaible_storage = this->_N - ini_size;

	if (avaible_storage >= std::distance(first, last))
	{
		while (first != last)
		{
			this->_datas.push_back(*first);
			first++;
		}
	}
	else
	{
		throw SpanInsufficientSize();
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
		throw SpanInsufficientSize();
	}
	return this->max() - this->min();
}

int Span::shortestSpan()
{
	if (this->size() <= 1)
	{
		throw SpanInsufficientSize();
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