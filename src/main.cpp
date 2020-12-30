#include <iostream>
#include <list>
#include <utility>

int main(int, char **)
try
{
    size_t const p = 23;

    std::list<std::pair<size_t, size_t>> result;

    for (size_t x = 0; x < p; ++x)
    {
        size_t const y1 = (x * x * x - x) % p;

        for (size_t y = 0; y < p; ++y)
        {
            size_t const y2 = (y * y) % p;

            if (y1 == y2)
            {
                result.push_back({ x, y });
            }
        }
    }

    for (size_t &point: result)
    {
        size_t &x = point.first;
        size_t &y = point.second;

        std::cout << "(" << x << ", " << y << ")," << std::endl;
    }

    return EXIT_SUCCESS;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
