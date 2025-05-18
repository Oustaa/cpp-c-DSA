#include <iostream>

using namespace std;

int main()
{
    int B[2][2];
    int **A = new int *[3];

    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    printf("%p\n", &A[0][0]);
    printf("%p\n", &A[1][0]);
    printf("%ld\n", sizeof(int));
}