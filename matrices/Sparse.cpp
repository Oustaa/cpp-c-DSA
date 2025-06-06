#include <iostream>

struct SparesElement
{
    int x;
    int y;
    int element;
};

class Sparse
{
private:
    int x, y, n;
    SparesElement *elements;

public:
    Sparse()
    {
        std::cout << "Enter Dimentions (x, y, n): ";
        std::cin >> this->x;
        std::cin >> this->y;
        std::cin >> this->n;

        this->elements = new SparesElement[this->n];
        printf("x = %d, y = %d, n = %d\n", x, y, n);

        for (int i = 0; i < this->n; i++)
        {
            std::cout << "Enter Element ( " << i << " )";
            int x, y, num;
            std::cin >> x;
            std::cin >> y;
            std::cin >> num;

            this->elements[i] = SparesElement{x, y, num};

            std::cout << std::endl;
        }
    }

    Sparse(int x, int y, int n)
    {
        this->x = x;
        this->y = y;
        this->n = n;

        this->elements = new SparesElement[this->n];
    }

    ~Sparse()
    {
        delete[] this->elements;
    }

    void display()
    {
        int k = 0;

        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < this->y; j++)
            {
                if (i == this->elements[k].x && j == this->elements[k].y)
                    std::cout << this->elements[k++].element << " ";
                else
                    std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }

    friend Sparse operator+(const Sparse &first, const Sparse &second);
};

Sparse operator+(const Sparse &first, const Sparse &second)
{
    if (first.x != second.x || first.y != second.y)
    {
        std::cout << "Can't add two matrices with different dimentison" << std::endl;
        return Sparse();
    }
    Sparse sumSparse(first.x, first.y, first.n + second.n);

    int i = 0, j = 0, k = 0;

    while (i < first.n && j < second.n)
    {
        if (first.elements[i].x < second.elements[j].x)
            sumSparse.elements[k++] = first.elements[i++];
        else if (first.elements[i].x > second.elements[j].x)
            sumSparse.elements[k++] = second.elements[j++];
        else
        {
            if (first.elements[i].y < second.elements[j].y)
                sumSparse.elements[k++] = first.elements[i++];
            else if (first.elements[i].y > second.elements[j].y)
                sumSparse.elements[k++] = second.elements[j++];
            else
            {
                sumSparse.elements[k] = first.elements[i++];
                sumSparse.elements[k++].element += second.elements[j++].element;
            }
        }
    }

    printf("after first while loop: i = %d, j = %d\n", i, j);

    while (i < first.n)
        sumSparse.elements[k++] = first.elements[i++];
    while (j < second.n)
        sumSparse.elements[k++] = second.elements[j++];

    return sumSparse;
};

int main()
{
    Sparse spare1;
    spare1.display();
    Sparse spare2;
    spare2.display();
    auto spare3 = spare1 + spare2;
    spare3.display();
}
