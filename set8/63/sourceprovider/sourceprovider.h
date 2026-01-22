#ifndef SOURCEPROVIDER_H
#define SOURCEPROVIDER_H

#include <string>

class SourceProvider
{
  public:

    virtual ~SourceProvider() = default;

    // Produces the next source file to compile.
    virtual bool next(std::string &out) = 0;
};

#endif