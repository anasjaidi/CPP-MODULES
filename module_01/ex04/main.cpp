#include <iostream>
# include <fstream>

void replace(std::string &line, std::string from, std::string to)
{
  size_t pos = line.find(from);
  while (pos != std::string::npos)
  {
    line.erase(pos, from.length());
    line.insert(pos, to);
    pos = line.find(from);
  }
}

int main(int ac, char **av)
{
  std::ifstream infile;
  std::ofstream outfile;
  std::string line, outfFileName = av[1];
  infile.open(av[1], std::ios::in);
  outfile.open(outfFileName + ".replace" , std::ios::out);
  if (!infile.is_open())
    return (0);
  while (std::getline(infile, line)) {
    replace(line, av[2], av[3]);
    outfile << line << std::endl;
  }
  infile.close();
  outfile.close();
}