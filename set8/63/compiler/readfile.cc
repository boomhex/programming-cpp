#include "compiler.ih"

string Compiler::readFile(string const &fileName)
{
    ifstream in(fileName, ios::binary);
    if (not in)
        throw runtime_error("Compiler: Could not read filename: " + fileName);
    
    ostringstream oss;
    oss << in.rdbuf();
    return oss.str();
}
