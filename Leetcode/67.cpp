#include <iostream>
#include <string>

// !!! Not Donw yet

using namespace std;

string addBinary(string a, string b)
{
    string sum = "";
    int rest = 0;
    int al = a.length() - 1;
    int bl = b.length() - 1;

    while (al >= 0 && bl >= 0)
    {
        int sum_result = stoi(&a[al]) + stoi(&b[bl]) + rest;

        cout << sum_result << endl;

        if (sum_result == 2)
        {
            sum = "1" + sum;
            rest = 0;
        }
        else
        {
            sum = "0" + sum;
            rest = 1;
        }

        al--;
        bl--;
    }

    if (rest == 1)
    {
        sum = "1" + sum;
    }

    return sum;
}

int main()
{
    cout << addBinary("1010", "1011") << endl;
}
