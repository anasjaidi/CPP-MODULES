#include "./phonebook.hpp"

int main(void)
{
  PhoneBook phone;
  std::string cmd;
  while (std::cin.good())
  {
    std::cout << "ENTER A COMMAND: ";
    std::getline(std::cin, cmd);
    if (!cmd.compare("ADD"))
      phone.add();
    else if (!cmd.compare("SEARCH"))
      phone.search();
    else if (!cmd.compare("EXIT"))
      break ;
  }
  return 0;
}