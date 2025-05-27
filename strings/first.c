#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void displayArrStr(char *str)
{
    // for (int i = 0; i < sizeof(str) / sizeof(char); i++)
    // {
    //     printf("%c", str[i]);
    // }

    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }

    printf("\n");
}

void to_uppercase(char c)
{
    printf("%c\n", c - 32);
}

bool is_palindrome(const char *str)
{
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main()
{
    // char temp = 'A';

    // printf("%c\n", temp);
    // printf("%d\n", temp);

    // char name1[20] = {'O', 'U', 'S', 'S', 'A', 'M', 'A'};
    // char name2[] = "Oussama";

    // displayArrStr(name1);
    // printf("%s\n", name1);
    // printf("%s\n", name2);

    // char my_name[20];

    // printf("Enter your first name: ");
    // scanf("%s", my_name);
    // printf("You entered: %s\n", my_name);

    // to_uppercase('a');
    // to_uppercase('b');

    // printf("%c\n", 87);

    // char str[] = "Oussama";

    // printf("Before revering: %s\n", str);
    // int i = 0, j = sizeof(str) / sizeof(char) - 2;

    // while (i < j)
    // {
    //     char temp = str[i];
    //     str[i] = str[j];
    //     str[j] = temp;
    //     j--;
    //     i++;
    // }
    // str[8] = '\0';

    // printf("After revering: %s\n", str);

    char str[] = "OUAaUO";

    printf("%d\n", is_palindrome(str));
}