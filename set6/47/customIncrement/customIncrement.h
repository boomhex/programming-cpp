#ifndef CUSTOMINCREMENT_H
#define CUSTOMINCREMENT_H

// A struct that is used to customize the increment step
// used a struct because i did not see the need for any
// of the extra features of a class
struct customIncrement
{
    unsigned value;
    unsigned step; 

    customIncrement(unsigned value, unsigned step);

    customIncrement &operator++();
    operator unsigned() const;
};

#endif
