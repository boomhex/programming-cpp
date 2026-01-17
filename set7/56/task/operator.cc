#include "task.ih"

void Task::operator()()
{
    d_count = 0;

    if (!d_file)
        return;

    ifstream in(*d_file);
    char ch;
    while (in.get(ch))
    {
        unsigned char uch = static_cast<unsigned char>(ch);
        if (d_func(uch))
            ++d_count;
    }
}