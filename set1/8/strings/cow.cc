#include "strings.ih"
void Strings::cow()
{
    if (*d_shared == 1)          // already unique: nothing to do
        return;

    std::string *newData = new std::string[d_size];
    size_t *newCount = new size_t(1);

    std::copy(d_str, d_str + d_size, newData);

    if (--*d_shared == 0)
    {
        delete[] d_str;
        delete d_shared;
    }

    d_str    = newData;
    d_shared = newCount;
}