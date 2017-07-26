/*
 * C++ example iterative solution: iterative.cpp
 *
 * Tal Lancaster
 * 2017-07-24
 */

#include <iostream>
#include <cstdint>

int32_t f_iter (int32_t n)
{
    int32_t result {};
    while (n) {
        result += n;
        --n;
    }

    return result;
}

int32_t f (int32_t n)
{
    auto isNegativeVal {false};
    if (n < 0) {
        isNegativeVal = true;
        n = -n;
    }

    constexpr auto MaxN {65535};
    if (MaxN < n) {
        throw std::overflow_error ("overflow of sum()" );
    }

    auto result {f_iter (n) };
    if (isNegativeVal) {
        result = -result;
    }

    return result;
}

int32_t main () {
    //std::cout << f (65535) << "\n";
    int i;
    std::cin >> i;
    std::cout << f (i) << '\n';
}
