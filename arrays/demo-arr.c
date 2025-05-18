// #include <stdio.h>
// #include <stdlib.h>

// struct Array
// {
//     int *A;
//     int size;
//     int length;
// };

// void Dispaly(struct Array arr)
// {
//     printf("Displaying Element: \n");
//     for (int i = 0; i < arr.length; i++)
//     {
//         printf("%d", arr.A[i]);
//         if (i == arr.length - 1)
//             continue;
//         printf(", ");
//     }
//     printf("\n");
// }

// int main()
// {
//     struct Array arr;
//     int l;

//     printf("Enter the size of the array: ");
//     scanf("%d", &arr.size);
//     arr.A = (int *)malloc(arr.size * sizeof(int));

//     printf("enter the number of element of the arr: ");
//     scanf("%d", &l);
//     arr.length = l;

//     printf("Start enteriung the numbers: \n");
//     for (int i = 0; i < l; i++)
//     {
//         scanf("%d", &arr.A[i]);
//     }

//     Dispaly(arr);
// }

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Dispaly(struct Array arr)
{
    printf("Displaying Element: \n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
        if (i == arr.length - 1)
            continue;
        printf(", ");
    }
    printf("\n");
}

void append(struct Array *arr, int element)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = element;
        arr->length++;
    }
}

void insert(struct Array *arr, int index, int item)
{
    if (index >= 0 && index <= arr->length && arr->length < arr->size)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->length++;
        arr->A[index] = item;
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 5}, 20, 4};
    printf("Before insert\n");
    Dispaly(arr);
    insert(&arr, 3, 4);
    append(&arr, 6);
    append(&arr, 7);
    append(&arr, 8);
    append(&arr, 9);
    printf("After insert\n");
    Dispaly(arr);
}
