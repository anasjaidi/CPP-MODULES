#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
  std::cout << "Bureaucrat constructor called\n";
  if (grade > 150)
  {
    throw GradeTooLowException();
  }
  else if (grade < 1)
  {
    throw GradeTooHighException();
  }
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called\n";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
  return "Bureaucrat: Exception Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return "Bureaucrat: Exception Grade too low!";
}

const std::string &Bureaucrat::getName() const
{
  return name;
}

int Bureaucrat::getGrade() const
{
  return grade;
}

void Bureaucrat::inc()
{
  if (--grade < 1)
  {
    throw GradeTooHighException();
  }
}

void Bureaucrat::dec()
{
  if (++grade > 150)
  {
    throw GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
  return os << bur.getName() << ", bureaucrat grade " << bur.getGrade(), os;
}