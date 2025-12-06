#include "message.h"
#include "base.h"   // superfluous since included in message, but since
                    // explicitely used here, I like to include it.
#include "derived.h"

void show(Base &base)
{
    base.hello(std::cout);
}

int main()
{
    // define base and derived object
    Base base;
    std::string derivedMsg{ "hello from Derived\n" };
    Derived derived{ derivedMsg };

    // define 2 message obj
    Message msgBase{ base };
    Message msgDerived{ derived };

    // use show in both
    msgBase.show();
    msgDerived.show();
}