#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("ShrubberyCreationForm", 25, 5) , target(target)
{
  std::cout << "PresidentialPardonForm constuctor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "PresidentialPardonForm destructor called\n";
}

void PresidentialPardonForm::excute(const Bureaucrat &executor) const
{
  if (!get_signed())
    throw FormNotSigned();
  else if (executor.getGrade() > get_grade_exec())
    throw GradeTooHighException();
  else if (executor.getGrade() < 1)
    throw GradeTooLowException();
  std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n" ;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 0)
{
  std::cout << "PresidentialPardonForm Default Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm("PresidentialPardonForm", rhs.get_grade_sign(), rhs.get_grade_exec())
{
  std::cout << "PresidentialPardonForm Copy Constructor  called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
  (void)rhs;
  std::cout << "PresidentialPardonForm Copy assaignement  called\n";
  return *this;
}