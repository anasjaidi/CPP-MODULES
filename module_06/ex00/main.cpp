#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <cmath>
std::string *get_char(double d)
{
  std::string *notd = new std::string("Non displayable");
  std::string *imp = new std::string("Imposible");
  if (static_cast<int>(d) == -2147483648)
    return imp;
  std::string *c = new std::string(1, static_cast<char>(d));
  if (isprint((*c)[0]))
    return c;
  else if ((static_cast<int>((*c)[0]) >= 0 && static_cast<int>((*c)[0]) <= 31) || static_cast<int>((*c)[0]) == 127)
    return notd;
  return imp;
}

std::string *get_int(double d)
{
  std::string *imp = new std::string("Imposible");
  if (static_cast<int>(d) == -2147483648)
    return imp;
  std::string *i = new std::string(std::to_string(static_cast<int>(d)));
  return i;
}

void trim(std::string *d)
{
  int i = d->find_last_not_of("0");
  if ((*d)[i] == '.')
    i--;
  d->erase(i + 1);
}

std::string *get_double(double d)
{
  std::string *sd = new std::string(std::to_string(d));
  if (!isinf(d))
  {
    if (!std::fmod(d, 1))
      return (trim(sd), *sd += ".0", sd);
  }
  return (trim(sd), sd);
}

std::string *get_float(double d)
{
  float f = static_cast<float>(d);
  std::string *fs = new std::string(std::to_string(f));
  if (!isinf(d))
  {
    if (!std::fmod(d, 1))
      return (trim(fs), *fs += ".0f", fs);
  }
  return (trim(fs), *fs += "f", fs);
}

int main(int argc, char const *argv[])
{
  if (argc == 2)
  {
    (void)argc;
    char *end;
    double d = std::strtod(argv[1], &end);
    std::cout << "char: " << *get_char(d) << std::endl;
    std::cout << "int: " << *get_int(d) << std::endl;
    std::cout << "float: " << *get_float(d) << std::endl;
    std::cout << "double: " << *get_double(d) << std::endl;
  }
  return 0;
}
