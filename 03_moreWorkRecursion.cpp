/*
 * 03_moreWorkRecursion.cpp: C++ example with recursion; doing extra work.
 * 02_recursion.cpp is too close to a tail-recursion so many compilers
 * are able unroll the recursion into a loop.  
 * So this version is an attempt to prevent this.
 *
 * Tal Lancaster
 * 2017-07-24
 */

#include <iostream>
#include <cstdint>

int32_t f_recurMoreWork (int32_t n)
{
    constexpr auto MaxN {65535};
    if (MaxN < n) {
        throw std::overflow_error ("overflow of sum()" );
    }

    if (n == 1) {
        return n;
    }

    auto val {n};
    return val + f_recurMoreWork (n-1);
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

    auto result {f_recurMoreWork (n) };
    if (isNegativeVal) {
        result = -result;
    }

    return result;
}
