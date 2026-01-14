#include "handler.ih"

void Handler::shift(ostream &out, std::string const &text)
{
    string str = text;

    for (size_t i = 0; i != str.size(); ++i)
    {
        out << str << '\n';
        char first = str.front();
        str.erase(0, 1);
        str.push_back(first);
    }
}
