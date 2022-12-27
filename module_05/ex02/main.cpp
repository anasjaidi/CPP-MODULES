#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    ShrubberyCreationForm s = ShrubberyCreationForm("anas");
    s.functionality();
    }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}