#include "./phonebook.hpp"

int main(void)
{
  PhoneBook phone;
  std::string cmd;
  while (std::cin.good())
  {
    std::cout << "enter a command";
    std::getline(std::cin, cmd);
    if (cmd.compare("ADD"))
      phone.add();
  }
  return 0;
}