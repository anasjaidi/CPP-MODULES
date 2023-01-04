# include "Span.hpp"


int main()
{
  Span a;
  int &l = a.get_N();
  l = 10;
  std::cout << a.get_N();
  /* code */
  return 0;
}
