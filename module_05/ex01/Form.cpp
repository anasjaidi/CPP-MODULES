#include "./Form.hpp"

Form::~Form()
{
  std::cout << "Form destructor called\n";
}

const std::string &Form::get_name() const
{
  return name;
}

int Form::get_grade_exec() const {
  return grade_to_exec;
}

int Form::get_grade_sign() const {
  return grade_to_sign;
}

bool Form::get_signed() const {
  return is_signed;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too low!";
}

bool Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= grade_to_sign)
    is_signed = true;
  return is_signed;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
  out << form.get_name() << (form.get_signed() ? " (signed)" : " (not signed)") << ", grade required to sign it: " << form.get_grade_sign() << ", grade required to execute it: " << form.get_grade_exec();
  return out;
}