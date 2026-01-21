#include "main.ih"

int main(int argc, char **argv)
{
    Storage storage;

    vector<Client> clients;
    clients.reserve(argc - 1);

    for (int i = 1; i != argc; ++i)
        clients.emplace_back(storage, argv[i]);

    // start threads
    vector<thread> threads;
    threads.reserve(clients.size());

    for (auto &client : clients)
        threads.emplace_back(ref(client));

    getInput(cin, storage);

    // join threads again
    for (auto &thr : threads)
        thr.join();
}
