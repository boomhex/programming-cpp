#include "maxfour.ih"

size_t MaxFour::d_nobjects = 0;

MaxFour::MaxFour()
{
    if (d_nobjects == 4)
        throw length_error{"max. number of objects reached.\n"};

    ++d_nobjects;
}

