#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
  std::cout << "ShrubberyCreationForm constuctor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::excute(const Bureaucrat  &executor) const
{
  if (!get_signed())
    throw FormNotSigned();
  else if (executor.getGrade() > get_grade_exec())
    throw GradeTooHighException();
  else if (executor.getGrade() < 1)
    throw GradeTooLowException();
  std::ofstream outFile;
  outFile.open(get_name() + "_shrubbery");
  if (outFile.is_open())
  {
    outFile << "   *           "  << "   *   " << std::endl;
    outFile << "  ***          "  << "  ***  " << std::endl;
    outFile << " *****         "  << " ***** " << std::endl;
    outFile << "*******        "  << "*******" << std::endl;
    outFile << "   *           "  << "   *   " << std::endl;
    outFile << "   *           "  << "   *   " ;
  }
  else
  {
    std::cout << "Error creating file." << std::endl;
  }
  outFile.close();
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 0, 0) {
  std::cout << "Default Constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm("ShrubberyCreationForm", rhs.get_grade_sign(), rhs.get_grade_exec())
{
  std::cout << "Copy Constructor  called\n";

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  (void)rhs;
  std::cout << "Copy assaignement  called\n";
  return *this;
}