#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
  try
  {
    Bureaucrat b("anas", 12);
    ShrubberyCreationForm s = ShrubberyCreationForm("anas");
    s.excute(b);
    PresidentialPardonForm p = PresidentialPardonForm("presedent");
    p.excute(b);
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}