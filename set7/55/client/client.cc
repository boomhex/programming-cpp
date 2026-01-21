#include "client.ih"

Client::Client(Storage &storage, string const &fileName)
:
    d_storage(storage),
    d_fileName(fileName),
    d_count(0)
{}