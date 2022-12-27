#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
  std::cout << "Bureaucrat constructor called\n";
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat()
{
  std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called\n";
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too low!";
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
    throw GradeTooHighException();
}

void Bureaucrat::dec()
{
  if (++grade > 150)
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
  return out << b.getName() << ", bureaucrat grade " << b.getGrade(), out;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
  *this = b;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
  grade = b.getGrade();
  return *this;
}

void Bureaucrat::signForm(const Form &f) {
  if (f.get_signed()) {
    std::cout << name << " signed " << f.get_name() << std::endl;
    return ;
  }
  std::cout << name << " couldn't signe " << f.get_name() <<  " because grade is lower than grade required to sign" << std::endl;
}