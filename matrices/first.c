#include <stdio.h>

struct Matrice
{
    int A[10];
    int n;
};

void set(struct Matrice *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i] = x;
    }
}

int get(struct Matrice m, int i, int j)
{
    if (i == j)
        return m.A[i];
    else
        return 0;
}

void display(struct Matrice m)
{
    for (int i = 0; i < m.n; i++)
    {

        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrice m;
    m.n = 3;

    set(&m, 0, 0, 1);
    set(&m, 1, 1, 2);
    set(&m, 2, 2, 3);

    display(m);
}
