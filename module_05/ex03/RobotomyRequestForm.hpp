#pragma once
# include "AForm.hpp"
#include <cstdlib>
#include <iostream>
class RobotomyRequestForm : public AForm
{
private:
  const std::string target;
  RobotomyRequestForm();

public:
  RobotomyRequestForm(const RobotomyRequestForm &);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &);
  RobotomyRequestForm(const std::string &);
  ~RobotomyRequestForm();
  virtual void excute(Bureaucrat const &executor) const;
};
