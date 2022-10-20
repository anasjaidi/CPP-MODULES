#include "./Harl.hpp"


void  Harl::debug(void) {
  std::cout << "DEBUG" << std::endl;
}

void  Harl::info(void) {
  std::cout << "INFO" << std::endl;
}

void  Harl::error(void) {
  std::cout << "ERROR" << std::endl;
}

void  Harl::warning(void) {
  std::cout << "WARNING" << std::endl;
}

void Harl::complain(std::string line) {
  void (Harl::*ft_ptr[4])(void) = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
  std::string words[4] = {"debug", "error", "info", "warning"};
  for (size_t i = 0; i < 4; i++)
  {
    if (line == words[i])
      (this->*ft_ptr[i])();
  }
}

