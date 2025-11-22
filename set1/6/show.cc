#include "msg.h"
#include <iostream>

namespace
{
  Msg const msgValues[] =
  {
    Msg::DEBUG,
    Msg::INFO,
    Msg::NOTICE,
    Msg::WARNING,
    Msg::ERR,
    Msg::CRIT,
    Msg::ALERT,
    Msg::EMERG
  };

  char const *const msgNames[] =
  {
    "DEBUG",
    "INFO",
    "NOTICE",
    "WARNING",
    "ERR",
    "CRIT",
    "ALERT",
    "EMERG"
  };
}

void show(Msg msg)
{
  if (msg == Msg::NONE)
  {
		std::cout << "NONE\n";
		return;
  }

  bool first = true;

  std::size_t const count = sizeof (msgValues) / sizeof(msgValues[0]);

  for (std::size_t index = 0; index != count; ++index)
  {
    Msg const flag = msgValues[index];

    if ((msg & flag) == flag)
    {
      if (not first)
        std::cout << ' ';

      std::cout << msgNames[index];
      first = false;
    }
  }

  std::cout << '\n';
}
