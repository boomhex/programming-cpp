#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <iosfwd>
#include <unordered_map>
#include <string>
#include <vector>

struct PairHash
{
    std::size_t operator()(std::pair<std::string, std::string> const &pair) const
    {
        std::hash<std::string> hasher;
        return hasher(pair.first) + hasher(pair.second);
    }
};

class Address
{
    std::unordered_map<
        std::pair<std::string, std::string>,    
        std::vector<std::string>,               
        PairHash
        > d_data;                               // vector of strings

    public:
        Address() = default;
        size_t remove(std::string const &postalCode);

    private:
        void extractFrom(std::istream &in);
        void processLine(std::string const &line);

        std::tuple<std::string, std::string,
            std::string> extractInfo(std::string const &line)  const;
        
        std::ostream &insertInto(std::ostream &out);
        void trim(std::string &str)  const;
};

std::istream &operator>>(std::istream &in, Address &add);   // get from file
std::ostream &operator<<(std::istream &out, Address &add);  // write to file

#endif