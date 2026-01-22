#include "compiler.ih"

int Compiler::exitCodeFromSystem(int sysReturn)
{
    if (sysReturn == -1)
        return -1;

    if (WIFEXITED(sysReturn))
        return WEXITSTATUS(sysReturn);

    return -1;
}