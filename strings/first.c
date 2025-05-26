#include <stdio.h>

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

int main()
{
    char temp = 'A';

    printf("%c\n", temp);
    printf("%d\n", temp);

    char name1[20] = {'O', 'U', 'S', 'S', 'A', 'M', 'A'};
    char name2[] = "Oussama";

    displayArrStr(name1);
    printf("%s\n", name1);
    printf("%s\n", name2);

    char my_name[20];

    printf("Enter your first name: ");
    scanf("%s", my_name);
    printf("You entered: %s\n", my_name);

    to_uppercase('a');
    to_uppercase('b');

    printf("%c\n", 87);
}