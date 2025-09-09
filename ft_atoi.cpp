#include <iostream>

using namespace std;

int ft_atoi(string *str)
{
    int num = 0;
    int absulot = (*str)[0] == '-' ? -1 : 1;

    for (int i = 0; i < str->length(); i++)
    {
        if (i == 0 && (*str)[i] == '-')
        {
            continue;
        }

        num *= 10;
        int n = (*str)[i] - '0';
        num += n;
    }

    return num * absulot;
}

int main()
{
    string strnum = "-85";
    int my_num = ft_atoi(&strnum);

    cout << my_num + 5 << endl;
}
