#include "./Harl.hpp"


int main(int argc, char const *argv[])
{
  Harl hs ;
  if (argc == 2)
    hs.complain(argv[1]);
  return 0;
}
