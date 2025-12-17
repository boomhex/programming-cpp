#include "strings.ih"

size_t Strings::count(char **environlike)
{
    char **ptr = environlike;

    while (*ptr++)
        ;

    return ptr - environlike - 1;   // correct for overshoot
}
