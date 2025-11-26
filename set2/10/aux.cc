#include "aux.h"

Arg const &Arg::instance(unsigned, char **, char const *)
{
    static Arg arg;
    return arg;
}

Process::Process(Arg const &)
{

}

void Process::run()
{

}