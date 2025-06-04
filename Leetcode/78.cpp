#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>> &finalResult, vector<int> &result, vector<int> &nums, int startIndex)
{
    finalResult.push_back(result);

    for (int i = startIndex; i < nums.size(); i++)
    {
        result.push_back(nums[i]);
        backtrack(finalResult, result, nums, i + 1);
        result.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> solutions;
    vector<int> solution;

    backtrack(solutions, solution, nums, 0);

    return solutions;
}

void display(const vector<vector<int>> &r)
{
    for (const auto &row : r)
    {
        cout << "[ ";
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    display(result);
}