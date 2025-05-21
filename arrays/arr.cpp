#include <iostream>

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

    me.display();
}