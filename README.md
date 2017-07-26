# tail-recursion
C++ example of tail recursion and a comparison between iterative and typical recursion.

`04_tailRecursion.cpp` is a C++ example showing tail recursion. More background can be found at: [tail-call-optimization-in-cpp](http://www.artificialworlds.net/blog/2012/04/30/tail-call-optimisation-in-cpp/).

The main thing to keep in mind to take advantage of tail recursion is to:

  * Not have any local variables
    * so track any state as parameters
  * Have the last statement be `return` changing the state and calling itself.
  
I have found clang 5.0 very good at optimizing even when these rules aren't followed.  But when these two guidelines are followed, both clang and gcc will do an awesome job optimizing.

# Examples
The timings are based on the time it takes to call the function 100,000 times where N=65535. (*Mac Pro 3.2G Intel Xeon*.)

## 01_iterative
This is a simple iterative version.

## 02_recursion
This is a simple version making use of recursion.  Note that this is very close to the tail-recursion version. And the compilers are able to optimize this almost as well.  So I created the 03_moreWorkRecursion, just to throw the compilers off a little.

## 03_moreWorkRecursion
Added more work and local variables to try to fool the compilers.  It worked for gcc, but clang was still able to optimize it almost as well as 02_iterative.

## 04_tailRecursion
A example that is making use of tail-recursion.  The compilers are able to make this as efficient as the straight iterative code.

code snippet:

```
int32_t f_tailRecur (int32_t total, int32_t n)
{
    if (n == 0) {
        return total;
    }

    return f_tailRecur(total+n, n-1);   // tail recursion
}

```
## Tables

**clang 5.0** 

|Test|opt -O3|sec|us|
|---|---|---|---|---|
|01_iterative | | 12.5305| 1.25305e+07|
|01_iterative | X | 0.000361178 | 361.178|
|02_recursive | | 34.135 | 3.4135e+07|
|02_recursive | X | 0.000391354 | 391.354|
|03_moreWorkRecursion | | 82.6843 | 8.26843e+07|
|03_moreWorkRecursion | X | 0.000435849 | 435.849|
|04_tailRecursion | | 33.1673 | 3.31673e+07|
|04_tailRecursion | X | 0.000361176 | 361.176|

**gcc 4.2.1**

|Test|opt -O3|sec|us|
|---|---|---|---|---|
|01_iterative | | 12.591| 1.25911e+07|
|01_iterative | X | 0.000393699 | 393.699|
|02_recursive | | 33.9891 | 3.39891e+07|
|02_recursive | X | 0.000391354 | 391.354|
|03_moreWorkRecursion | | 84.0367 | 8.40367e+07|
|03_moreWorkRecursion | X | 3.84388 | 3.84388e+06|
|04_tailRecursion | | 33.3838 | 3.33838e+07|
|04_tailRecursion | X | 0.000393767 | 393.767|

