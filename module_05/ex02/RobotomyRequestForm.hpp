#pragma once
# include "AForm.hpp"


class RobotomyRequestForm: public AForm
{
public:
  RobotomyRequestForm(const std::string &);
  ~RobotomyRequestForm();
  virtual void functionality(void);
};
