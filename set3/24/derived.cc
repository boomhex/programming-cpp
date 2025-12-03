#include "derived.h"

Derived::Derived(std::string const &name)
:
    Aux{name},    // constructs d_out_stream first with the provided name
    Base(d_out_stream)          // passes the stream to Base
{}