#include "Form.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    Form f = Form("form 1", 12, 13);
    std::cout << b << std::endl;
    b.dec();
    std::cout << b << std::endl;
    b.dec();
    f.beSigned(b);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}