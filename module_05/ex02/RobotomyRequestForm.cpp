#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("ShrubberyCreationForm", 72, 45), target(target)
{
  std::cout << "RobotomyRequestForm constuctor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::excute(const Bureaucrat &executor) const
{
  if (!get_signed())
    throw FormNotSigned();
  else if (executor.getGrade() > get_grade_exec())
    throw GradeTooHighException();
  else if (executor.getGrade() < 1)
    throw GradeTooLowException();
  // Seed the random number generator with the current time.
  srand(time(NULL));

  // Generate a random number in the range 0 to 9.
  int randomNumber = rand() % 10;
  if (randomNumber & 1)
  {
    std::cout << target << " has been robotomized successfully 50  of the time.\n";
  }
  else {
    std::cout << "the robotomy failed.\n";
  }
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 0, 0)
{
  std::cout << "RobotomyRequestForm Default Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm("RobotomyRequestForm", rhs.get_grade_sign(), rhs.get_grade_exec())
{
  std::cout << "RobotomyRequestForm Copy Constructor  called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
  (void)rhs;
  std::cout << "RobotomyRequestForm Copy assaignement  called\n";
  return *this;
}