#include "handler.ih"

void Handler::shift(ostream &out, std::string const &text)
{
    if (text.empty())
        return;

    string str = text;

    for (size_t i = 0; i != str.size(); ++i)
    {
        out << str << '\n';
        // rotate left by 1: "mouse" -> "ousem"
        char first = str.front();
        str.erase(0, 1);
        str.push_back(first);
    }
}
