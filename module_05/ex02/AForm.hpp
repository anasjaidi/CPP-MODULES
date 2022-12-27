#pragma once

#include "./Bureaucrat.hpp"

class AForm
{
private:
  const std::string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_exec;
  AForm();

public:
  AForm(const std::string &, const int &, const int &);
  AForm(const AForm &);
  AForm &operator=(const AForm &);
  ~AForm();
  const std::string &get_name() const;
  bool beSigned(const Bureaucrat &bur);
  int get_grade_sign() const;
  int get_grade_exec() const;
  bool get_signed() const;
  class GradeTooHighException : public std::exception
  {
    virtual const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception
  {
    virtual const char *what(void) const throw();
  };
  virtual void functionality(void) = 0;
};

std::ostream &operator<<(std::ostream &, const AForm &);