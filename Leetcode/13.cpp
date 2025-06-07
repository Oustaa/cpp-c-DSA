#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s)
{
    map<char, int> romanNumbers{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int result = 0;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && romanNumbers[s[i]] < romanNumbers[s[i + 1]])
        {
            result -= romanNumbers[s[i]];
        }
        else
        {
            result += romanNumbers[s[i]];
        }
    }

    return result;
}

int main()
{
    int result = romanToInt("MCMXCIV");
    // int result = romanToInt("III");
    cout << result << endl;
}