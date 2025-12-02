#include <cctype>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        try
        {
            if (argc == 1)
                throw string{"need an argument"};

            if (isdigit(static_cast<unsigned char>(argv[1][0])))
                throw static_cast<size_t>(argv[1][0]);

            throw invalid_argument{argv[1]};
        }
        catch (string const &str)             
        {
            cerr << "No arguments: " << str << '\n';
            throw 1;                                 
        }
        catch (size_t const value)              
        {
            cerr << "Value: " << value << '\n';
            throw 2;                                 
        }
        catch (invalid_argument const &except)  
        {
            cerr << "Exception's what: " << except.what() << '\n';
            throw 3;                                  
        }
    }
    catch (int const val)                                   
    {
        cerr << "finally: always used, called from catch clause " << val << '\n';
    }
}
