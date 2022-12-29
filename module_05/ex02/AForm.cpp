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
  return "AForm Exception Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
  return "AForm Exception Grade too low!";
}

const char *AForm::FormNotSigned::what(void) const throw()
{
  return "AForm Exception Form Not Signed!";
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

AForm::AForm(const AForm &rhs) : name(rhs.get_name()), grade_to_sign(rhs.get_grade_sign()), grade_to_exec(rhs.get_grade_exec())
{
  std::cout << "AForm copy constructor called\n";
}

AForm &AForm::operator=(const AForm &rhs)
{
  (void)rhs;
  std::cout << "AForm copy assaingnement operator called\n";
  return *this;
}

AForm::AForm() : grade_to_sign(0), grade_to_exec(0)
{
  std::cout << "AForm constructor called\n";
}