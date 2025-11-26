#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <iostream>

int main (int argc, char **argv)
try 
{
  if (argc == 0)
    throw std::string { "need an argument"};

  if (std::isdigit(static_cast<unsigned char>(argv[1][0])))
    throw static_cast<size_t>(argv[1][0]);

  throw std::invalid_argument{argv[1]};
}
catch (std::string const &str) 
{
  std::cerr << " No arguments: " << str << "\n";
  std::cerr << " finally: always used, called from catch clause 1 ";
}
catch (std::size_t value) 
{
  std::cerr << " Value: " << value << "\n";
  std::cerr << " finally: always used, called from catch clause 2 ";
}
catch (std::invalid_argument except )
{
  std::cerr << " Exception's what: " << except.what()  << "\n";
  std::cerr << " finally: always used, called from catch clause 3 ";
}