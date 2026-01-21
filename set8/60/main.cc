#include "main.ih"

string threadFun()
{
    cerr << "entry\n";

    this_thread::sleep_for(chrono::seconds(5));

    cerr << "first cerr\n";

    this_thread::sleep_for(chrono::seconds(5));

    cerr << "second cerr\n";

    return "end the program";
}

int main()
{
    auto fut = std::async(launch::async, threadFun);

    size_t count = 0;

    while (true)
    {
        // dummy for main task
        this_thread::sleep_for(chrono::seconds(1));

        cerr << "inspecting: " << ++count << '\n';
        // inspect
        if (fut.wait_for(chrono::seconds(0)) == std::future_status::ready)
        {
            fut.get();          // retrieve return value
            cerr << "done\n";
            break;
        }
    }
}