#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137)
{
  std::cout << "ShrubberyCreationForm constuctor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::functionality(void) {
  std::ofstream outFile;
  outFile.open(get_name() + "_shrubbery");
  if (outFile.is_open())
  {
    outFile << "   *   " << std::endl;
    outFile << "  ***  " << std::endl;
    outFile << " ***** " << std::endl;
    outFile << "*******" << std::endl;
    outFile << "   *   " << std::endl;
    outFile << "   *   " << std::endl;
  }
  else
  {
    std::cout << "Error creating file." << std::endl;
  }

  outFile.close();
}