#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
    Intern i;
    std::string name = "robotomy request";
    std::string target = "anas";
    AForm *f = i.makeForm(name, target);
    if (f != nullptr)
      std::cout << f->get_name() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << '\n';
  }
}