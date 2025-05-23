#include <iostream>
#include <vector>

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
        for (int i = start; i < end; i++)
        {
            int a;
            if (height[i] < height[end])
            {
                a = height[i] * (end - i);
            }
            else
            {
                a = height[end] * (end - i);
            }
            if (a > area)
            {
                area = a;
            }
        }
        if (height[start] > height[end])
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    return area;
}

// {1, 8, 6, 2, 5, 4, 8, 3, 7}
// start; end; i;
// 0    ; 8;

int main()
{
    int B[2][2];
    int **A = new int *[3];

    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    printf("%p\n", &A[0][0]);
    printf("%p\n", &A[1][0]);
    printf("%ld\n", sizeof(int));

    Person me{"Oussama Tailba", 27};

    vector<int> l = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxA = maxArea(l);
    cout << "max area is " << maxA << endl;

    l = {1, 1};
    maxA = maxArea(l);
    cout << "max area is " << maxA << endl;

    l = {1, 2, 1, 1, 1, 1, 1, 3};
    maxA = maxArea(l);
    cout << "max area is " << maxA << endl;

    l = {0, 2};
    maxA = maxArea(l);
    cout << "max area is " << maxA << endl;

    l = {8, 7, 2, 1};
    maxA = maxArea(l);
    cout << "max area is " << maxA << endl;

    // me.display();
}