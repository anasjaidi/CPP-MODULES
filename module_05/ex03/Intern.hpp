# pragma once

# include "./Bureaucrat.hpp"
# include "./RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"
#include <map>

class Intern
{
private:
public:
  Intern();
  ~Intern();
  Intern(const Intern &src);
  Intern &operator=(const Intern &rhs);
  AForm *makeForm(std::string &, std::string &);
};