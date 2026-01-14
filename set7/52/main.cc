#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 3)
        return usage();

    string const outFile = argv[1];
    string const text    = argv[2];

    ofstream out(outFile);

    // create handler in main
    Handler handler;
    thread thr1(&Handler::shift, &handler, ref(out), cref(text));
    thr1.join();

    out << '\n';

    // create handler in thread
    std::thread thr2(&inFunc, ref(out), cref(text));
    thr2.join();
}
