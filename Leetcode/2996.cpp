#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int missingInteger(vector<int> &nums)
{
    int prefix = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1] + 1)
            prefix += nums[i];
        else
            break;
    }

    unordered_set<int> set(nums.begin(), nums.end());

    while (set.count(prefix))
    {
        prefix++;
    }

    return prefix;
}

int main()
{
    vector<int> test_case1 = {1, 2, 3, 2, 5};
    cout << missingInteger(test_case1) << endl; // Expected: 6

    vector<int> test_case2 = {3, 4, 5, 1, 12, 14, 13};
    cout << missingInteger(test_case2) << endl; // Expected: 15
}
