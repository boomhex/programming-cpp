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
        friend std::istream &operator>>(std::istream &in, Address &add);
        friend std::ostream &operator<<(std::ostream &out, Address &add);

        Address() = default;
        size_t remove(std::string const &postalCode);

    private:
        void processLine(std::string const &line);
        void trim(std::string &str)  const;
        std::tuple<std::string, std::string,
            std::string> extractInfo(std::string const &line)  const;
        
        std::istream &extractFrom(std::istream &in);
        std::ostream &insertInto(std::ostream &out);
        
};

#endif