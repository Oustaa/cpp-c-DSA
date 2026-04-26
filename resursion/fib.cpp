#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

// using lli = long long int;

// lli fib(int x)
// {
//     static std::map<int, lli> memo = {};

//     if (x == 1 || x == 0)
//     {
//         return x;
//     }

//     if (memo.count(x))
//     {
//         return memo[x];
//     }
//     else
//     {
//         memo[x] = fib(x - 2) + fib(x - 1);
//         return memo[x];
//     }
// }

// int ncr(int n, int r)
// {
//     static std::map<std::string, int> memo{};

//     if (r == 0 || r == n)
//     {
//         return 1;
//     }

//     std::string key = std::to_string(n) + std::to_string(r);
//     if (!memo.count(key))
//     {
//         memo[key] = ncr(n - 1, r - 1) + ncr(n - 1, r);
//     }

//     return memo[key];
// }

// int main(int argc, char *argv[])
// {
//     // printf("e(2,4) = %.90lf\n", e_linear(1, 20));
//     // printf("e(2,4) = %lf\n", e(2, 4));

//     std::cout << argc << std::endl;

//     if (argc < 2)
//     {
//         std::cout << "you must provide a number" << std::endl;
//         return 1;
//     }
//     int n = atoi(argv[1]);

//     lli result = fib(n);

//     std::cout << "fib(" << n << ") = " << result << std::endl;

//     std::cout << ncr(5, 2) << std::endl;

//     return 0;
// }

// int f(int n)

// {
//     static int i = 1;

//     if (n >= 5)
//         return n;

//     n = n + i;

//     i++;

//     return f(n);
// }

// void foo(int n, int sum)
// {

//     int k = 0, j = 0;

//     if (n == 0)
//         return;

//     k = n % 10;

//     j = n / 10;

//     sum = sum + k;

//     foo(j, sum);

//     printf("%d", k);
// }

// int main2()

// {

//     int a = 2048, sum = 0;

//     foo(a, sum);

//     printf("% d\n", sum);
// }

// int f2(int &x, int c)
// {
//     c = c - 1;

//     if (c == 0)
//         return 1;

//     x = x + 1;

//     return f2(x, c) * x;
// }

// int fun(int n)
// {
//     int x = 1, k;

//     if (n == 1)
//         return x;

//     for (k = 1; k < n; ++k)

//         x = (k)*fun(n - k);

//     return x;
// }

void count(int n)
{

    static int d = 1;

    printf("%d", n);

    printf("%d", d);

    d++;

    if (n > 1)
        count(n - 1);

    printf("%d", d);
}

int main()
{
    count(3);

    return 0;
}