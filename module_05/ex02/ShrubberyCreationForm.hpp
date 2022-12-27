# pragma once 
#include "AForm.hpp"
#include <fstream>
#include <iostream>
class ShrubberyCreationForm: public AForm
{
public:
  ShrubberyCreationForm(const std::string &);
  ~ShrubberyCreationForm();
  virtual void functionality(void);
};
