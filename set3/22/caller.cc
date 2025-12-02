#include "main.ih"


void caller(Base &obj)
{
    // Downcast Base& to Derived* using static_cast
    Derived *derived = static_cast<Derived *>(&obj);
    // Now we can call Derived::hello
    derived->hello();             // or d->Derived::hello();
}
