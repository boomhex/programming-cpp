#include "base.ih"

Base::Base(Base &&other)
{
    cout << "Base(): move constructor\n";
}