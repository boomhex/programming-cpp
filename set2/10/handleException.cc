#include "handleException.h"

using namespace std;

int handleException ()
try
{
    rethrow_exception(current_exception());
}
catch (int const value)
{
    return (value == 0) ? 0 : 1;
}
catch (string const &str)
{
    cerr << str << '\n';
    return 1;
}
catch (exception const &exep)
{
    cerr << exep.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "Unknown exception thrown";
    rethrow_exception(current_exception());
}
