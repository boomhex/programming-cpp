#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 2)
        usage();

    size_t nPrimes = stoull(argv[1]);

    Timer timer;
    jthread thr(dots);

    timer.start();
    vector<size_t> result = sieve(nPrimes); // run the sieve
    timer.stop();

    thr.request_stop();                     // stop the dot thread
    thr.join();

    display(cout, result);

    timer.display(cout);                    // display the timer
    cout << "Computation of " << nPrimes << " primes took "
         << timer.seconds() << " seconds\n";
}
