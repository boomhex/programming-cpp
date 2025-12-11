#include "base/base.h"
#include "derived/derived.h"


Base **derivedFactory(size_t size)
{
    Base **derivedPtr = new Base*[size];
    for (size_t index = 0; index != size; ++index)
        derivedPtr[index] = new Derived();
    return derivedPtr;
}


int main()
{
    size_t size = 10;
    Base **baseptr = derivedFactory(size);

    for (size_t index = size; --index != 0;)
        delete baseptr[index];
    
    delete[] baseptr;
}
