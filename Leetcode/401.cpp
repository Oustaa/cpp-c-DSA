#include <iostream>
#include <vector>

using namespace std;

vector<string> readBinaryWatch(int turnedOn)
{
    static vector<string> result = {};

    vector<int> hours{1, 2, 4, 8};
    vector<int> hoursCach = {0, 0, 0, 0};
    vector<int> minutes{1, 2, 4, 8, 16, 32};
    vector<int> minutesCash{0, 0, 0, 0, 0, 0};

    for (int i = 0; i < turnedOn; i++)
    {
    }
}

int main()
{
}