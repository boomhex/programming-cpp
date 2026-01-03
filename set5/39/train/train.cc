#include "train.ih"

    // by ./main.cc

Train::Train(size_t nCars)
{
                                                // construct the train pulling
                                                // nCars cars
    for (size_t idx = 1, end = nCars + 1; idx != end; ++idx)
        d_cars.push(nCars--);
}