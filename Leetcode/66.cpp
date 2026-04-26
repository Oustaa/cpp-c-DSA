#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int rest = 1;
    int i = digits.size() - 1;

    while (rest == 1 && i >= 0)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
            if (i == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            digits[i] += 1;
            rest = 0;
        }
        i--;
    }

    return digits;
}

int main()
{
    vector<int> digits{9, 9, 9};
    vector<int> result = plusOne(digits);
    for (int num : result)
    {
        cout << num;
    }
    cout << endl;
}