#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

struct _Time
{
    int hour;
    int minute;

    string stringify()
    {
        return to_string(min(hour, 11)) + ":" + (minute < 10 ? "0" : "") + to_string(min(minute, 59));
    }
};

void backTrack(vector<string> &result, vector<int> hours, vector<int> minuts, _Time t, int turnedOn, int current)
{
    if (current >= turnedOn)
    {
        result.push_back(t.stringify());
        return;
    }

    for (int i = 0; i < 10 * turnedOn; i++)
    {
        if (minuts.size() != 0)
        {
            _Time tt{t.hour, t.minute + minuts[minuts.size() - 1]};
            minuts.pop_back();
            backTrack(result, hours, minuts, tt, turnedOn, current + 1);
        }
        else if (hours.size() != 0)
        {
            _Time tt{t.hour + hours[hours.size() - 1], t.minute};
            hours.pop_back();
            backTrack(result, hours, minuts, tt, turnedOn, current + 1);
        }
    }
}

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> result;
    vector<int> hours{8, 4, 2, 1};
    vector<int> minuts{32, 16, 8, 4, 2, 1};

    if (turnedOn > 8)
    {
        return result;
    }

    _Time
        t{0, 0};
    backTrack(result, hours, minuts, t, turnedOn, 0);
    return result;
}

int main()
{
    vector<string> r = readBinaryWatch(2);
    for (string x : r)
    {
        cout << x << endl;
    }
}
