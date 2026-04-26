#include <iostream>

using namespace std;

class Diagnal
{
    int n;
    int *A;

public:
    Diagnal(int len)
    {
        n = len;
        A = new int[len];
    }

    ~Diagnal()
    {
        delete[] A;
    }

    int get(int i, int j)
    {
        if (i == j)
            return A[i];
        return 0;
    }

    void set(int i, int j, int x)
    {
        if (i == j)
            A[i] = x;
    }

    friend ostream &operator<<(ostream &o, Diagnal &d);
};

ostream &operator<<(ostream &o, Diagnal &d)
{
    for (int i = 0; i < d.n; i++)
    {
        for (int j = 0; j < d.n; j++)
        {
            if (i == j)
                cout << d.A[i] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }

    return o;
}

int main()
{
    Diagnal d(3);

    d.set(0, 0, 1);
    d.set(1, 1, 2);
    d.set(2, 2, 3);

    cout << d;
}