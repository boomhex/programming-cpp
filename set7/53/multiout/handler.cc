#include "multiout.ih"

void MultiOut::handler(size_t threadNo)
{
    osyncstream out(cout);

    for (size_t line = 0; line != 4; ++line)
    {
        cout << "thread " << threadNo << '\n';
        this_thread::yield();

        out << "Line " << line << " from  thread " << threadNo << '\n';
    }
    out.emit();
}
