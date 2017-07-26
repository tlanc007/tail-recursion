/*
 * C++ example of a typical recursion as an counter example to tailRecursion.cpp
 *
 * Tal Lancaster
 * 2017-07-24
 */

#include <iostream>
#include <cstdint>

int32_t f_recur (int32_t n)
{
    if (n == 1) {
        return n;
    }

    return n + f_recur(n-1);
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

    auto result {f_recur (n) };
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
