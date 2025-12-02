#include "derived.ih"

Derived::Derived(Derived &&other)
:
    Base(move(other))           // added
{

}