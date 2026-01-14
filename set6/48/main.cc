#include "main.ih"

int main(int argc, char **argv)
try
{
                                // argc not required: argv[1] == 0 if no args
    Interactive interactive(argv[1]);   
    interactive.read();
    interactive.session();
}
catch (...)
{
    return 1;
}
