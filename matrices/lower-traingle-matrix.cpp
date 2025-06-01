#include <iostream>

class LowerTriangularMatrix
{
private:
    int nonZeroValues;
    int size;
    int *data;

    virtual int getIndex(int i, int j) = 0;

public:
    // size is the size of the matrix, if size = 5 then matrix is 5 * 5
    LowerTriangularMatrix(int size)
    {
        this->size = size;
        nonZeroValues = size * (size + 1) / 2;
        data = new int[nonZeroValues];
    }

    ~LowerTriangularMatrix()
    {
        delete[] data;
    }

    void set(int i, int j, int item)
    {
        if (i >= j)
        {
            int index = getIndex(i, j);

            data[index] = item;
        }
    }

    int get(int i, int j)
    {
        if (i >= j)
        {
            int index = getIndex(i, j);

            return data[index];
        }
        else
        {
            return 0;
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (i >= j)
                    std::cout << get(i, j) << " ";
                else
                    std::cout << "0 ";
            }
            std::cout << "\n";
        }
    }
};

class rowMajorLTM : public LowerTriangularMatrix
{
private:
    int getIndex(int i, int j) override
    {
        return ((i * (i - 1)) / 2) + j - 1;
    };

public:
    rowMajorLTM(int size) : LowerTriangularMatrix(size) {}
};

class columnMajorLTM : public LowerTriangularMatrix
{
private:
    int getIndex(int i, int j) override
    {
        return (i * (j - 1)) - (((j - 2) * (j - 1)) / 2) + (i - j);
    }

public:
    columnMajorLTM(int size) : LowerTriangularMatrix(size) {}
};

int main()
{
    rowMajorLTM m(4);

    m.set(1, 1, 1);

    m.set(2, 1, 2);
    m.set(2, 2, 3);

    m.set(3, 1, 4);
    m.set(3, 2, 5);
    m.set(3, 3, 6);

    m.set(4, 1, 7);
    m.set(4, 2, 8);
    m.set(4, 3, 9);
    m.set(4, 4, 10);

    m.display();
}