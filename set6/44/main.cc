#include "main.ih"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    vector<Student> students = read(argv[1]);

    writeNames(cout, students);
    writeNrs(cout, students);
}