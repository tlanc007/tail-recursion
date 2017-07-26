/*
 * C++ example of tail-recursion
 *
 * Many of the major C++ compilers take advantage of tail-recursion and make
 * a special effort to heavily optimize this pattern.
 *
 * Tal Lancaster
 * 2017-07-24
 */

#include <iostream>
#include <cstdint>

int32_t f_tailRecur (int32_t total, int32_t n)
{
    if (n == 0) {
        return total;
    }

    return f_tailRecur(total+n, n-1);   // tail recursion
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

    auto result {f_tailRecur (0, n) };
    if (isNegativeVal) {
        result = -result;
    }

    return result;
}
