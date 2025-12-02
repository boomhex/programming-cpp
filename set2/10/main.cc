#include "main.ih"

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::instance(argc, argv, "ace:fg:h");  

    Process process{ arg };                                    

    process.run();                                              
}
catch (...) 
{
    return handleException();
}
