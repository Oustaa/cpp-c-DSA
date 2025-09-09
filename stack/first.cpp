#include <cstdint>
#include <iostream>

using namespace std;

class Stack {};

template <class T> struct Node {
  T value;
  Node *next;
};

int main() {
  unsigned int age = INTMAX_MAX;
  Node<int> *first, *last;

  for (int i = 0; i < 10; i++) {
  }

  cout << age << endl;

  return 0;
}
