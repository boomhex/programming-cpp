#include "main.ih"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cerr << "arg 1: the number of cars pulled by a train\n"
                "arg 2 (optional, default 10): max number of cars on the "
                                                            "side track\n";
        return 1;
    }

    Train train{ stoul(argv[1]) };      // define the train pulling cars
    cout << "initial train:\n" << 
                train << '\n';

    Factory factory{ argc > 2 ? stoul(argv[2]) : 10U };
    factory.reverse(train);

    cout << "\n"
            "leaving train:\n" <<
            train << '\n';
}