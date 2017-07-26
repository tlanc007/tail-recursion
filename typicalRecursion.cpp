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
    constexpr auto MaxN {65535};

    if (MaxN < n) {
        throw std::overflow_error ("overflow of sum()" );
    }

    return f_recur (n);
}

int32_t main () {
    std::cout << f (65535) << "\n";
}
