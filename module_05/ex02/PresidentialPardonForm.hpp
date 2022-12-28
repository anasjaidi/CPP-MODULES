#pragma once
# include "AForm.hpp"
#include <cstdlib>
#include <iostream>
class PresidentialPardonForm : public AForm
{
private:
  const std::string target;
  PresidentialPardonForm();

public:
  PresidentialPardonForm(const PresidentialPardonForm &);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &);
  PresidentialPardonForm(const std::string &);
  ~PresidentialPardonForm();
  virtual void excute(Bureaucrat const &executor) const;
};
