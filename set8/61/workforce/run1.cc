#include "workforce.ih"

void WorkForce::run(string const &input, string const &output)
{
    ifstream in(input);
    ofstream out(output);

    run(in, out);
}