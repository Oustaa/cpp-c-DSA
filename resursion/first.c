// // #include <stdio.h>

// // void fun(int num)
// // {
// //   if (num > 0)
// //   {
// //     printf("%d\n", num);
// //     fun(num - 1);
// //   }
// // }

// // int sumToValue(int to)
// // {
// //   static int x = 0;
// //   if (to > 0)
// //   {
// //     x++;
// //     return sumToValue(to - 1) + x;
// //   }

// //   return 0;
// // }

// // int withStatic()
// // {
// //   static int x = 0;
// //   x++;

// //   printf("value of x is: %d\n", x);
// // }

// // int main()
// // {

// //   // fun(300000);
// //   printf("the result is: %d\n", sumToValue(5));
// //   printf("the result is: %d\n", sumToValue(5));
// //   printf("the result is: %d\n", sumToValue(5));
// //   printf("the result is: %d\n", sumToValue(5));

// //   return 0;
// // }

// #include <stdio.h>

// void fun(int n)
// {
//   if (n > 0)
//   {
//     fun(n - 1);
//     printf("%d,", n);
//     fun(n - 1);
//   }
// }

// int main()
// {
//   fun(3);
//   return 0;
// }

// #include <stdio.h>

// void funB(int b);

// void funA(int a)
// {
//   if (a > 0)
//   {
//     printf("%d\n", a);
//     funB(a - 1);
//   }
// }

// void funB(int b)
// {
//   if (b > 1)
//   {
//     printf("%d\n", b);
//     funA(b / 2);
//   }
// }

// int main()
// {
//   funA(20);
// }

#include <stdio.h>
#include <stdlib.h>

int _pow(int x, int p)
{
    if (p < 1)
    {
        return 1;
    }

    return x * _pow(x, p - 1);
}

int _fact(int x)
{
    if (x <= 1)
    {
        return 1;
    }

    return _fact(x - 1) * x;
}

double e(double x, double times)
{
    static double p = 1, f = 1;
    double r;

    if (times == 0)
        return 1.0;

    r = e(x, times - 1);
    p = p * x;
    f = f * times;
    // return e(x, times - 1) + (_pow(x, times) / _fact(times));
    return r + (p / f);
}

// double e_linear(double x, double times)
// {
//     // static double p = 1, f = 1;
//     // double r;

//     if (times == 0)
//         return 1.0   ;
//     // p = p * x;
//     // f = f * times;

//     return (1 + x / times) * e_linear(x, times - 1);
//     // return e(x, times - 1) + (_pow(x, times) / _fact(times));
//     // return r + (p / f);
// }

double e_linear(double x, double n)
{
    static double sum;

    if (n == 0)
        return sum;

    sum = 1 + x * sum / n;
    return e_linear(x, n - 1);
}

int fib(int x)
{
    if (x == 1 || x == 0)
    {
        return x;
    }

    return fib(x - 2) + fib(x - 1);
}

int main(int argc, char **argv)
{
    // printf("2 to the power of 4 is: %d\n", _pow(2, 4));
    // printf("5! = %d\n", _fact(12));

    // printf("e(2,4) = %.90lf\n", e_linear(1, 20));
    // printf("e(2,4) = %lf\n", e(2, 4));

    if (argc >= 2)
    {
        printf("argv[1] = %s\n", argv[1]);
    }

    printf("fib(3) = %d\n", fib(atoi(argv[1])));

    return 0;
}
