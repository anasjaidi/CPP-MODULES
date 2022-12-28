#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 72, 45)
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
  if (executor.getGrade() > get_grade_exec())
    throw GradeTooLowException();
  std::cout << "%s > has been pardoned by Zaphod Beeblebrox.\n" ;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 0)
{
  std::cout << "Default Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm("PresidentialPardonForm", rhs.get_grade_sign(), rhs.get_grade_exec())
{
  std::cout << "Copy Constructor  called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
  (void)rhs;
  std::cout << "Copy assaignement  called\n";
  return *this;
}