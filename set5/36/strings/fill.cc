#include "strings.ih"


void Strings::fill(char **environlike)
{
    for (size_t index = 0; index != size(); ++index)
        at(index) = environlike[index]; // changes ptr value?
}
