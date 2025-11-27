#include "main.ih"

int main(int argc, char **argv)
try
{
    Arg const &arg = Arg::instance(argc, argv, "ace:fg:h");  

    Process process{ arg };                                    

    process.run();                                              
}
catch (int const value)
{
    if (value == 0)
        return 0;
    return 1;
}
catch (std::string const &str)
{
    std::cerr << str << '\n';
    return 1;
}
catch (std::exception const &exep)
{
    std::cerr << exep.what() << '\n';
    return 1;
}
catch (...){
    std::cerr << "Unknown exception thrown";
    return 1;
}