#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person() = delete;

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display() const
    {
        cout << name << " is " << age << " years old" << endl;
    }
};

int maxArea(vector<int> height)
{
    int start = 0, end = height.size() - 1;
    int area = 0;

    while (start < end)
    {

        int a;
        if (height[start] < height[end])
        {
            a = height[start] * (end - start);
            start++;
        }
        else
        {
            a = height[end] * (end - start);
            end--;
        }
        if (a > area)
        {
            area = a;
        }
    }

    return area;
}

// vector<int>
void duplicatSortArr(vector<int> nums)
{
    map<int, int> seen{};

    for (int num : nums)
    {
        if (seen.count(num))
        {
            cout << num << " is duplicated" << endl;
            seen[num]++;
        }
        else
        {
            seen[num] = 1;
        }
    }
}

bool findPairToSUm(vector<int> nums, int k)
{
    map<int, int> cach = {};

    for (int num : nums)
    {
        if (cach[k - num])
        {
            return true;
        }

        cach[num] = k - num;
    }

    return false;
}

int main()
{
    int B[2][2];
    int **A = new int *[3];

    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    // printf("%p\n", &A[0][0]);
    // printf("%p\n", &A[1][0]);
    // printf("%ld\n", sizeof(int));

    // Person me{"Oussama Tailba", 27};

    // vector<int> l = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // int maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    // l = {1, 1};
    // maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    // l = {1, 2, 1, 1, 1, 1, 1, 3};
    // maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    // l = {0, 2};
    // maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    // l = {8, 7, 2, 1};
    // maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    // l = {1, 8, 100, 2, 100, 4, 8, 3, 7};
    // maxA = maxArea(l);
    // cout << "max area is " << maxA << endl;

    duplicatSortArr(vector<int>{1, 2, 8, 8, 8, 8, 8, 8, 3, 4, 5, 7, 8, 9});

    // me.display();

    cout << "pair is found/notfoud << " << findPairToSUm(vector<int>{-21, -12, 40, 31, 7, 8, 9, 6}, 10) << endl;
}