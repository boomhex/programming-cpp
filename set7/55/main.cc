#include "main.ih"

int main(int argc, char **argv)
{
    Storage storage;

    vector<Client> clients;
    clients.reserve(argc - 1);

    for (int index = 1; index != argc; ++index)
        clients.emplace_back(storage, argv[index]);

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
