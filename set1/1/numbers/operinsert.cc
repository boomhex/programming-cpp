#include "numbers.ih"

ostream &operator<<(ostream &out, Numbers const &numbers)
{
    bool first = true;  // avoid leading whitespace

    for (size_t index = 0; index != numbers.size(); ++index) {
        if (not first)
            out << " ";
        first = false;
        out << numbers[index];      // el wise to out
    }

    return out;
}