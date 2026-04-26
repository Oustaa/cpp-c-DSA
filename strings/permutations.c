#include <stdio.h>

void permutations(char str[], int k)
{
    static int cash[20] = {0};
    static char res[20];

    if (str[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (cash[i] == 0)
            {
                res[k] = str[i];
                cash[i] = 1;
                permutations(str, k + 1);
                cash[i] = 0;
            }
        }
    }
}

int main()
{
    // permutations("ABC", 0); // n!
    permutations("Kaoutar Taki", 0); // n!
}