# include "Span.hpp"


int main()
{
  int n=30;
  Span a(n);
  std::list<int> aa;
  /* code */
  for (int i = 0; i < n / 2 - 8 ; i++)
  {
    a.addNumber(i);
    aa.push_back(i + 10);
  }
  a.addNumber(aa.begin(), aa.end());
  a.addNumber(-1);
  a.addNumber(111);
  a.addNumber(-2);


  std::cout << "Longest: " << a.longestSpan() << std::endl;
  std::cout << "shortest: " << a.shortestSpan() << std::endl;
  a.shortestSpan();
  return 0;
}
