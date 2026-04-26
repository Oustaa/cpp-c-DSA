#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<string> &result, string binary, int max)
{
    if (binary.length() == max)
    {
        result.push_back(binary);
        return;
    }

    backtrack(result, binary + "0", max);

    backtrack(result, binary + "1", max);
}

void display(vector<string> vs)
{
    for (string s : vs)
    {
        cout << s << endl;
    }
}

vector<string> GenerateAllBinaryStringsOfLength(int n)
{
    vector<string> result;

    backtrack(result, "", n);

    return result;
}

int main()
{
    vector<string> r = GenerateAllBinaryStringsOfLength(19);

    display(r);
}