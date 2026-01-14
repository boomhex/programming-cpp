#ifndef INCLUDED_INTERACTIVE
#define INCLUDED_INTERACTIVE

#include <iosfwd>
#include <string>
#include <unordered_map>

class Interactive
{
    struct Fields
    {
        size_t nFake = 0;
        size_t lastTime = 0;
        std::string lastDate{};
    };

    struct Record
    {
        std::string domain{};
        Fields fields;
    };
                                        // define >> op for istream it.
    friend std::istream &operator>>(std::istream &in, Record &record);    

    using FieldsMap = std::unordered_map<std::string, Fields>;

    std::string d_filename;
    FieldsMap d_map;

    public:
        Interactive(char *filename);
        void read();
        void session();
    private:
        void addRecord(Record const &record);    
        void show(FieldsMap const &map);
        bool isNumber(std::string const &string);
        bool isDate(std::string const &string);
};

#endif