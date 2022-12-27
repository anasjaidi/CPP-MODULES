# pragma once
# include <iostream>
# include "Form.hpp"
# include <string>
# include <stdexcept>
class Form;

class Bureaucrat {
private:
  const std::string name;
  int grade;
  Bureaucrat();
  public : 
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &);
  Bureaucrat &operator=(const Bureaucrat &);
  class GradeTooHighException : public std::exception
  {
    virtual const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception
  {
    virtual const char *what(void) const throw();
  };
  const std::string &getName() const;
  int getGrade() const;
  void inc();
  void dec();
  void signForm(const Form &);
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);