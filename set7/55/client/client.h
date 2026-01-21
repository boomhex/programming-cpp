#ifndef INCLUDED_CLIENT
#define INCLUDED_CLIENT

#include "../storage/storage.h"     // see 54 for impl.
#include <string>
#include <cstddef>

class Client
{
    Storage &d_storage;
    std::string d_fileName;
    size_t d_count;

  public:
    Client(Storage &storage, std::string const &fileName);

    void operator()();
    std::size_t size()  const;   // no. of lines written inline
};

inline size_t Client::size()   const
{
    return d_count;
}

#endif