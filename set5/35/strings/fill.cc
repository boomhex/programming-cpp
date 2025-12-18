#include "strings.ih"


void Strings::fill(char **environlike)
{
    for (char **begin = environlike, **end = environlike + size();
          begin != end; ++begin)
        d_strings.assign(size(), *begin);
}
