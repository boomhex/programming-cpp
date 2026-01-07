#include "shrink.ih"

void Shrink::report() const
{
    d_out << "size: " << d_vect.size() << 
                ", capacity: " << d_vect.capacity() << "\n"
                "\n";
}