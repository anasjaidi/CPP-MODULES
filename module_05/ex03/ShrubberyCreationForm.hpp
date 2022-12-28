# pragma once 
#include "AForm.hpp"
#include <fstream>
#include <iostream>
class ShrubberyCreationForm: public AForm
{
private:
  const std::string target;
  ShrubberyCreationForm();
  public : 
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ShrubberyCreationForm(const std::string &);
  ~ShrubberyCreationForm();
  virtual void excute(Bureaucrat const &executor) const;
};
