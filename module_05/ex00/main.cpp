#include "Bureaucrat.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    std::cout << b << std::endl;
    b.dec();
    std::cout << b << std::endl;
    b.dec();
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}