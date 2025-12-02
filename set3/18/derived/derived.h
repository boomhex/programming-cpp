#include "../base/base.h"
class Derived: public Base 
{
    public:
        Derived();
        Derived(Derived const &other);
        Derived(Derived &&other);
};