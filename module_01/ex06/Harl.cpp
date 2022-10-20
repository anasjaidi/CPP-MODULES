#include "./Harl.hpp"

void Harl::debug(void)
{
  std::cout << "[DEBUG]" << std::endl;
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
  std::cout << "[INFO]" << std::endl;
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error(void)
{
  std::cout << "[ERROR]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}

void Harl::warning(void)
{
  std::cout << "[WARNING]" << std::endl;
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::complain(std::string line)
{
  int r = -1;
    void (Harl::*ft_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string words[4] = {"DEBUG", "INFO", "WARNING", "WRROR"};
  enum levels{
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
  };
  for (size_t i = 0; i < 4; i++)
  {
    if (line == words[i])
      r = i;
  }
  switch (r)
  {
  case 0:
    (this->*ft_ptr[0])();
  case 1:
    (this->*ft_ptr[1])();
  case 2:
    (this->*ft_ptr[2])();
  case 3:
    (this->*ft_ptr[3])();
    break ;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}
