#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
  try
  {
    Bureaucrat b("bur", 1);
    ShrubberyCreationForm s = ShrubberyCreationForm("sh");
    s.excute(b);
    PresidentialPardonForm p = PresidentialPardonForm("presedent");
    p.beSigned(b);
    p.excute(b);
    b.executeForm(s);
    std::cout << "---------------------- \n";
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}