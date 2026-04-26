#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<string> &result, string s, int n)
{
    if (s.length() == n)
    {
        result.push_back(s);
        return;
    }

    backtrack(result, s + "0", n);
    backtrack(result, s + "1", n);
}

vector<string> getCommbinations(int n)
{
    vector<string> result;

    backtrack(result, "", n);

    return result;
}

void backtrack2(vector<string> &result, string base, string s, int currentIndex)
{
    if (currentIndex == base.length())
    {
        result.push_back(s);
        return;
    }

    for (int i = currentIndex; i < base.length(); i++)
    {
        backtrack2(result, base, s + base[i], i + 1);
    }
}

vector<string> getStringVarient(string base)
{
    vector<string> result;

    backtrack2(result, base, "", 0);

    return result;
}

int main()
{
    vector<string> r = getStringVarient("ABC");

    for (string s : r)
    {
        cout << s << endl;
    }
}

/*
    ABC
    ACB
    BAC
    BCA
    CAB
    CBA
*/