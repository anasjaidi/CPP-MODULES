# pragma once
# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
private:
  const std::string name;
  int grade;
public:
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();
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
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);