#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<string> &result, string binary, string)
{
}

void display(vector<string> vs)
{
    for (string s : vs)
    {
        cout << s << endl;
    }
}

vector<string> GenerateAllBinaryStringsOfLength(string s)
{
    vector<string> result;

    backtrack(result);

    return result;
}

int main()
{
    vector<string> r = GenerateAllBinaryStringsOfLength("abc");

    display(r);
}