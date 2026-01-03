#ifndef INCLUDED_TRAIN_
#define INCLUDED_TRAIN_

#include <iosfwd>
#include <stack>

class Train
{
    friend std::ostream &operator<<(std::ostream &out, Train const &train);

    std::stack<size_t> d_cars;

    public:
        Train(size_t nCars);

        std::stack<size_t> &cars();

    private:
        std::ostream &insert(std::ostream &out) const;
};

inline std::stack<size_t> &Train::cars()
{
    return d_cars;
}

inline std::ostream &operator<<(std::ostream &out, Train const &train)
{
    return train.insert(out);
}

#endif

