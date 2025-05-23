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
#include <stdbool.h>

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

int get(struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length)
    {
        return arr.A[index];
    }

    return 0;
}

void set(struct Array arr, int index, int elem)
{
    if (index >= 0 && index <= arr.length)
    {
        arr.A[index] = elem;
    }
}

int max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }

    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }

    return min;
}

int totalArray(struct Array arr)
{
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
}

int totalArrayRec(struct Array arr, int index)
{
    if (index < 0)
    {
        return 0;
    }

    return totalArrayRec(arr, index - 1) + arr.A[index];
}

float avg(struct Array arr)
{
    return totalArray(arr) / arr.length;
}

void revers(struct Array *arr)
{
    for (int i = arr->length - 1, j = 0; i > j; i--, j++)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void rotateArr(struct Array *arr, int rotateBy)
{
    for (int i = 0; i < rotateBy; i++)
    {
        swap(&arr->A[i], &arr->A[arr->length - rotateBy + i]);
    }
}

bool isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }

    return true;
}

void arrangePN(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

struct Array unionArr(struct Array arr1, struct Array arr2)
{

    struct Array arr3 = arr1;
    //  {
    //     arr1.A,
    //     arr1.size + arr2.size,
    //     arr1.length + arr2.length,
    // };
    arr3.size += arr2.size;

    int k = arr2.length;

    for (int i = 0; i < arr2.length; i++)
    {
        printf("%d found att => %d\n", arr2.A[i], linearSearch(&arr3, arr2.A[i]));
        if (linearSearch(&arr1, arr2.A[i]) == -1)
        {
            arr3.A[k] = arr2.A[i];
            arr3.length++;
            k++;
        }
    }

    return arr3;
}

//    int i = 0, j = 0, k = 0, length = 0;
// while (i < arr1.length && j > arr2.length)
// {
// }

// arr1.size > arr2.size ? arr1.size : arr2.size,
// arr1.length > arr2.length ? arr1.length : arr2.length,

int main()
{
    // struct Array arr = {{1, 2, 3, 5}, 20, 4};
    // // printf("Before insert\n");
    // // Dispaly(arr);
    // insert(&arr, 3, 4);
    // append(&arr, 6);
    // // append(&arr, 7);
    // // append(&arr, 8);
    // // append(&arr, 9);
    // // append(&arr, 10);
    // // printf("12 found at %d\n", linearSearch(&arr, 10));
    // // printf("2 found at %d\n", binarySearch(&arr, 5));
    // // printf("arr sum = %d\n", totalArrayRec(arr, arr.length - 1));
    // // printf("%d was deleted\n", delete(&arr, 2));
    // // printf("After insert\n");
    // // Dispaly(arr);
    // // revers(&arr);
    // // rotateArr(&arr, 5);
    // // Dispaly(arr);
    // printf("%B\n", isSorted(arr));

    struct Array arr1 = {{-1, 2, 3, -6, 45, -67, 4, -54, 6, -46}, 10, 10};
    struct Array arr2 = {{122, 2, 3123, -6, 45, -67, 4, -54, 6, -46}, 10, 10};

    struct Array arr3 = unionArr(arr1, arr2);

    // arrangePN(&arr);
    Dispaly(arr3);
}
