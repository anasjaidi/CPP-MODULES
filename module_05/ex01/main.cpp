#include "Form.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    Form f = Form("form 1", 12, 13);
    Form f1 = Form("form 1",5, 13);
    std::cout << b << std::endl;
    b.dec();
    std::cout << b << std::endl;
    b.inc();
    f.beSigned(b);
    std::cout << f << std::endl;
    b.signForm(f1);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}