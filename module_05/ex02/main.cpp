#include "AForm.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    AForm f = AForm("form 1", 12, 13);
    std::cout << b << std::endl;
    b.dec();
    std::cout << b << std::endl;
    b.inc();
    f.beSigned(b);
    std::cout << f << std::endl;
    
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}