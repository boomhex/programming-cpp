#include "strings.ih"


void Strings::resetInsertion()  const
{
    d_manip = &stdInsertion;
    d_sep = '\n';
}
