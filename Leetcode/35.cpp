#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size();
    int middle;

    if (target < nums[0])
    {
        return 0;
    }

    if (target > nums[nums.size() - 1])
    {
        return nums.size();
    }

    while (start < end)
    {
        middle = (start + end) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle] > target)
        {
            end = middle;
        }
        else
        {
            start = middle;
        }
    }

    return middle;
}

int main()
{
    vector<int> nums{1, 3, 5, 6};
    int result = searchInsert(nums, 2);

    cout << result << endl;
}