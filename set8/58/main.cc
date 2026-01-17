#include "main.ih"

int main()
{

    double lhs[4][5];
    double rhsT[6][5];        // consider this the transposed rhs

    for (size_t idx = 0; idx != 4; ++idx)
    {
        for (size_t jdx = 0; jdx != 5; ++jdx)
            lhs[idx][jdx] = idx + jdx;
    }
    for (size_t idx = 0; idx != 6; ++idx)
    {
        for (size_t jdx = 0; jdx != 5; ++jdx)
            rhsT[idx][jdx] = idx + jdx;
    }

    future<double> fut[4][6];

    for (size_t idx = 0; idx != 4; ++idx)
    {
        for (size_t jdx = 0; jdx != 6; ++jdx)
        {
            double *rowL = lhs[idx];
            double *rowR = rhsT[jdx];

            packaged_task<double()> innerProduct(
                [rowL, rowR]() -> double
                {
                    return inner_product(rowL, rowL + 5, rowR, 0);
                }
            );

            fut[idx][jdx] = innerProduct.get_future();
            thread thr(move(innerProduct));
            thr.detach();
        }
    }

    for (size_t idx = 0; idx != 4; ++idx)
    {
        for (size_t jdx = 0; jdx != 6; ++jdx)
        {
            double value = fut[idx][jdx].get();
            if (jdx != 0)
                cout << ' ';
            cout << value;
        }
        cout << '\n';
    }

}