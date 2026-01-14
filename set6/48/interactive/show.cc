#include "interactive.ih"

void Interactive::show(FieldsMap const &map)
{
    for (auto const &[domain, fields] : map)
    {
        std::cout << domain
                  << "  " << fields.nFake
                  << "  " << fields.lastTime
                  << "  " << fields.lastDate
                  << '\n';
    }
    std::cout << "kept: " << map.size() << "\n";
}
