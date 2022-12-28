#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
  try
  {
    // Bureaucrat b("anas", 12);
    // ShrubberyCreationForm s = ShrubberyCreationForm("anas");
    // s.excute(b);
    // PresidentialPardonForm p = PresidentialPardonForm("presedent");
    // p.excute(b);
    // b.executeForm(s);
    // std::cout << "---------------------- \n";
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