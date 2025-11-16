#include "numbers.ih"

ostream &operator<<(ostream &out, Numbers const &numbers)
{
    bool first = true;
    for (size_t index = 0; index != numbers.size(); ++index) {
        if (not first)
            out << " ";
        first = false;
        out << numbers[index];
    }
    return out;
}