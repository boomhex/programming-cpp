#include "strings.ih"


Strings::Strings(char **environlike)
:
    Strings(count(environlike), environlike)
{}
