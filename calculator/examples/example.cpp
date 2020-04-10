#include "calculator.hpp"


constexpr double v1 = 3.0;
constexpr double v2 = 2.0;

int main(int argc, char** argv)
{
    auto r1 = ns::add(v1, v2);
    auto r2 = ns::subtract(v1, v2);
    auto r3 = ns::multiply(v1, v2);
    auto r4 = ns::divide(v1, v2);
    auto r5 = ns::max(v1, v2);
    auto r6 = ns::min(v2, v2);

    return 0;
}
