#ifndef FILESOURCE_H
#define FILESOURCE_H

#include "../sourceprovider/sourceprovider.h"
#include <fstream>
#include <string>

class FileSource: public SourceProvider
{
    std::ifstream d_in;
    std::string d_line;

    public:
        FileSource(std::string const &listFile);

        bool next(std::string &out) override;
};

#endif