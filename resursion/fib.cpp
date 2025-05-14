#include <iostream>
#include <map>
#include <stdlib.h>

using lli = long long int;

lli fib(int x)
{
    static std::map<int, lli> memo = {};

    if (x == 1 || x == 0)
    {
        return x;
    }

    if (memo.count(x))
    {
        return memo[x];
    }
    else
    {
        memo[x] = fib(x - 2) + fib(x - 1);
        return memo[x];
    }
}

int main(int argc, char *argv[])
{
    // printf("2 to the power of 4 is: %d\n", _pow(2, 4));
    // printf("5! = %d\n", _fact(12));

    // printf("e(2,4) = %.90lf\n", e_linear(1, 20));
    // printf("e(2,4) = %lf\n", e(2, 4));

    std::cout << argc << std::endl;

    if (argc < 2)
    {
        std::cout << "you must provide a number" << std::endl;
        return 1;
    }
    int n = atoi(argv[1]);

    long long result = fib(n);

    std::cout << "fib(" << n << ") = " << result << std::endl;

    return 0;
}
