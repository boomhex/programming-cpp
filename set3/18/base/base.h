
class Base
{
    public:
        Base();                     // default
        Base(Base const &other);    // copy
        Base(Base &&other);         // move
};