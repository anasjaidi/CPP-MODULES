#include "Intern.hpp"

Intern::Intern()
{
  std::cout << "Intern default constructor\n";
}

Intern::Intern(const Intern &src)
{
  *this = src;
  std::cout << "Intern copy constructor\n";
}

Intern::~Intern()
{
  std::cout << "Intern  destructor\n";
}

Intern &Intern::operator=(const Intern &rhs)
{
  (void)rhs;
  std::cout << "Intern Copy operator\n";
  return (*this);
}

AForm *Intern::makeForm(std::string &name, std::string &target)
{
  std::map<std::string, AForm *> forms;
  forms.insert(std::make_pair("robotomy request", new RobotomyRequestForm(target)));
  forms.insert(std::make_pair("presidential pardon", new PresidentialPardonForm(target)));
  forms.insert(std::make_pair("shrubbery creation", new ShrubberyCreationForm(target)));
  std::map<std::string, AForm *>::iterator it = forms.find(name);
  
  if (it != forms.end())
    return it->second;
  std::cout << "Intern cannot create " << name << " form" << std::endl;
  return nullptr;
}