#include <iostream>
#include <vector>
#include <map>

using namespace std;

void backtrack(vector<string> &result, string s, int open, int close, int max)
{
    // 1
    if (s.length() == max * 2)
    {
        result.push_back(s);
        return;
    }

    // 2
    if (open < max)
    {
        backtrack(result, s + "(", open + 1, close, max);
    }

    // 3
    if (close < open)
    {
        backtrack(result, s + ")", open, close + 1, max);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;

    backtrack(result, "", 0, 0, n);

    return result;
}

void print_vector(vector<string> v)
{
    for (string sol : v)
    {
        cout << sol << endl;
    }
}

int main()
{
    print_vector(generateParenthesis(2));

    return 0;
}