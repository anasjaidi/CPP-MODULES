#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &n, int g) : name(n), grade(g)
{
  std::cout << "Bureaucrat constructor called\n";
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called\n";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
  return "Bureaucrat Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return "Bureaucrat Grade too low!";
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
  if (grade == 1)
    throw GradeTooHighException();
  grade--;
}

void Bureaucrat::dec()
{
  if (grade == 150)
    throw GradeTooLowException();
  grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
  return out << b.getName() << ", bureaucrat grade " << b.getGrade(), out;
}