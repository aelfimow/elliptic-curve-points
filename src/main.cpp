#include <iostream>
#include <sstream>
#include <list>
#include <utility>

namespace
{
    void check(ssize_t a, ssize_t b, ssize_t m)
    {
        if (m <= 0)
        {
            throw std::invalid_argument("Wrong modulo");
        }

        ssize_t const value = (4 * a * a * a) + (27 * b * b);

        ssize_t const r = value % m;

        if (r == 0)
        {
            throw std::invalid_argument("Wrong a or b");
        }
    }
}

int main(int argc, char *argv[])
try
{
    if (argc != 4)
    {
        throw std::invalid_argument("Usage: prime-number a b");
    }

    ssize_t p = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> p;
    }

    ssize_t a = 0;
    {
        std::stringstream ss { argv[2] };
        ss >> a;
    }

    ssize_t b = 0;
    {
        std::stringstream ss { argv[3] };
        ss >> b;
    }

    check(a, b, p);

    std::list<std::pair<ssize_t, ssize_t>> result;

    for (ssize_t x = 0; x < p; ++x)
    {
        ssize_t const y1 = ((x * x * x) + (a * x) + b) % p;

        for (ssize_t y = 0; y < p; ++y)
        {
            ssize_t const y2 = (y * y) % p;

            if (y1 == y2)
            {
                result.push_back({ x, y });
            }
        }
    }

    for (auto &point: result)
    {
        ssize_t &x = point.first;
        ssize_t &y = point.second;

        std::cout << "(" << x << ", " << y << ")," << std::endl;
    }

    std::cout << "Total: " << result.size() << " points." << std::endl;

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
