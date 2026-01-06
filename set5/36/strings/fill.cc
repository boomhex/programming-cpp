#include "strings.ih"


void Strings::fill(char **environlike)
{
    for (size_t index = 0; index != d_size; ++index)
        d_sp[index] = environlike[index];
}
