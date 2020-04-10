#include "calculator.hpp"
#include <algorithm>

namespace ns
{
    double add(double a, double b)
    {
        return a+b;
    }

    double subtract(double a, double b)
    {
        return a-b;
    }

    double multiply(double a, double b)
    {
        return a*b;
    }

    double divide(double a, double b)
    {
        return a/b;
    }

    double min(double a, double b)
    {
        return std::min(a, b);
    }

    double max(double a, double b)
    {
        return std::max(a,b);
    }

}
