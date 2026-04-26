#include <stdio.h>
#include <stdlib.h>

void test(int size)
{
    int *p = (int *)malloc(size * sizeof(int));

    for (int i = 1; i <= size; i++)
    {
        p[i - 1] = i;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", p[i]);
    }

    free(p);
}

int main()
{

    int i;

    // test(100000);
    // test(100000);
    // test(100000);

    printf("Enter a value :");
    scanf("%d", &i);

    int arr[20] = {};
    printf("length = %ld\n", sizeof(arr) / sizeof(int));

    return 0;
}

//  no free => 92MB
//   with free => 385.0KB