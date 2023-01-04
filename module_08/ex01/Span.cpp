# include "Span.hpp"

Span::Span() : _tab(nullptr) , N(0), length(0)
{
  std::cout << "default constructor called\n";
}

Span::Span(int &i) : _tab(new int[i]), N(i), length(0)
{
  std::cout << "Typed constructor called\n";
}

Span::Span(const Span &rhs) {
  std::cout << "copy constructor called\n";
  *this = rhs;
}

void Span::addNumber(int &n) {
  if (length == N)  throw std::exception();
  _tab[length] = n;
  length++;
}

    Span &Span::operator=(const Span &rhs)
{
  N = rhs.N;
  _tab = new int[N];
  for (size_t i = 0; i < static_cast<size_t>(N); i++)
    _tab[i] = rhs._tab[i];
  return *this;
}

Span::~Span() {
  std::cout << "default destructor called\n";
}

int &Span::get_N(void)  {
  return N;
}