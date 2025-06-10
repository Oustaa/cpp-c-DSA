#include <iostream>

using namespace std;

struct Node {
  int value;
  struct Node *next;
};

class LinkedList {
public:
  struct Node *head;
  struct Node *tail;

  void insert() {}
};

int main() { cout << "Hello Linked List World" << endl; }
