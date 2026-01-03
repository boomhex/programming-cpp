#include "train.ih"

    // by 

// the last car is at the stack top. 
// Add the cars to a vector's back and write the vector's elements to the

ostream &Train::insert(ostream &out) const
{
    auto copy{ d_cars };
    vector<size_t> cars;            // the engine pulls the cars from the 
                                    // stack's bottom to the stack's top

    while (not copy.empty())        // add all cars to a vector so they can be
    {                               // displayed from the bottom (engine) to 
        cars.push_back(copy.top()); // the top
        copy.pop();
    }

    out << "Engine ";               // show the cars following the engine
    for (size_t count = 0, idx = cars.size(); idx--; )
    {
        out << cars[idx] << ' ';
        if (++count % 20 == 0 and idx != 0)
            out << "\n       ";
    }

    return out;
}