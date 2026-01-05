#include "lines.ih"

Lines::~Lines()
{
    Safe::g_lines.erase(this);
    for (Lines const *&ptr : Safe::g_order)
    {
        if (ptr == this)
        {
            ptr = nullptr;
            break;
        }
    }
}