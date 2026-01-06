#include "main.ih"

string lowerStr(string str)
{
    for (char &ch : str)
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    return str;
}