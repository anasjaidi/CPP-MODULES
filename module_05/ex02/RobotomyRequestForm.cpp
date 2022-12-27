#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45)
{
  std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::functionality() {
  
}