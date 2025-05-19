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

int delete(struct Array *arr, int index)
{
    int element = arr->A[index];
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
    }

    return element;
}

int swap(int *i, int *j)
{
    int perm = *i;
    *i = *j;
    *j = perm;
}

int linearSearch(struct Array *arr, int elem)
{
    int index;
    for (index = 0; index < arr->length; index++)
    {
        if (arr->A[index] == elem)
        {
            swap(&arr->A[index], &arr->A[index - 1]);
            return index - 1;
        }
    }

    return -1;
}

int binarySearch(struct Array *arr, int elem)
{
    int head = 0;
    int tail = arr->length - 1;
    int middleIndex;

    while (head <= tail)
    {
        middleIndex = (head + tail) / 2;
        if (arr->A[middleIndex] == elem)
        {
            return middleIndex;
        }
        if (elem > arr->A[middleIndex])
        {
            head = middleIndex + 1;
        }
        else
        {
            tail = middleIndex - 1;
        }
    }

    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 5}, 20, 4};
    // printf("Before insert\n");
    // Dispaly(arr);
    insert(&arr, 3, 4);
    append(&arr, 6);
    append(&arr, 7);
    append(&arr, 8);
    append(&arr, 9);
    append(&arr, 10);
    // printf("12 found at %d\n", linearSearch(&arr, 10));
    printf("2 found at %d\n", binarySearch(&arr, 5));
    // printf("%d was deleted\n", delete(&arr, 2));
    // printf("After insert\n");
    // Dispaly(arr);
}
