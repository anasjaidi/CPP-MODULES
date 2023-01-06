# include "Span.hpp"

Span::Span() :   N(0)
{
  std::cout << "default constructor called\n";
}

Span::Span(int i) :  N(i)
{
  std::cout << "Typed constructor called\n";
}

Span::Span(const Span &rhs) {
  std::cout << "copy constructor called\n";
  *this = rhs;
}

void Span::addNumber(int n) {
  if ( (int)_tab.size() == N)  throw std::exception();
  _tab.push_back(n);
}

void Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
  if ( ((int)_tab.size() + std::distance(begin, end)) > N)  throw std::exception(); _tab.insert(_tab.end(), begin, end);
}

Span &Span::operator=(const Span &rhs)
{
  N = rhs.N;
  _tab = rhs._tab;
  return *this;
}

Span::~Span() {
  std::cout << "default destructor called\n";
}

int &Span::get_N(void)  {
  return N;
}

int Span::longestSpan() {
  if (_tab.size() < 2)  throw std::exception(); return std::abs(*(std::max_element(_tab.begin(), _tab.end())) - *(std::min_element(_tab.begin(), _tab.end())));
}

int Span::shortestSpan() {
  int min1;
  int min2;

  min1 = INT_MAX;
  min2 = INT_MAX;

  for (std::list<int>::iterator it = _tab.begin(); it != _tab.end(); it++)
  {
    if (*it < min1) {
      min2 = min1;
      min1 = *it;
    } else if (*it < min2 && *it > min1) min2 = *it;
  }

  return std::abs(min1 - min2);
}