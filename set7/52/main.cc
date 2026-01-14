#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 3)
        return usage();

    string const outFile = argv[1];
    string const text    = argv[2];

    ofstream out(outFile);
    
    Handler handler;

    
    thread thr(&Handler::shift, &handler, ref(out), cref(text));
    thr.join();
}