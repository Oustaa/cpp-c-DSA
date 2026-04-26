#include <iostream>

using namespace std;

int sumNaturalNums(int to)
{
    if (to > 0)
    {
        return to + sumNaturalNums(to - 1);
    }

    return 0;
}

int fact(int num)
{
    if (num <= 1)
    {
        return 1;
    }

    return num * fact(num - 1);
}

int main()
{
    std::cout << sumNaturalNums(500) << std::endl;
    std::cout << fact(5) << std::endl;
}