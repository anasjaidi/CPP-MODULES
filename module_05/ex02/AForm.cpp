#include "./AForm.hpp"

AForm::~AForm()
{
  std::cout << "AForm destructor called\n";
}
AForm::AForm(const std::string &name, const int &grade_sign, const int &grad_exec) : name(name), grade_to_sign(grade_sign), grade_to_exec(grad_exec)
{
  std::cout << "AForm Typed constructor called\n";
}

const std::string &AForm::get_name() const
{
  return name;
}

int AForm::get_grade_exec() const {
  return grade_to_exec;
}

int AForm::get_grade_sign() const {
  return grade_to_sign;
}

bool AForm::get_signed() const {
  return is_signed;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
  return "Bureaucrat Exception Grade too low!";
}

bool AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= grade_to_sign)
    is_signed = true;
  return is_signed;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
  out << AForm.get_name() << (AForm.get_signed() ? " (signed)" : " (not signed)") << ", grade required to sign it: " << AForm.get_grade_sign() << ", grade required to execute it: " << AForm.get_grade_exec();
  return out;
}