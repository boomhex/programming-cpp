#include "main.ih"

namespace First 
{
  enum Enum 
  {};

  void fun(Enum enumVar)
  {
    std::cout << "First::fun() called\n";
  }
}

namespace Second 
{
  void fun(First::Enum enumVar)
  {
    std::cout << "Second::fun() called\n";
  }
}

int main()
{
  First::Enum enumVar;
  fun(enumVar);
}