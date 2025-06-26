#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
  int value;
  Node *next;
  Node *prev;

  Node(int value) { this->value = value; }
};

class DLinkedList {
public:
  int len = 0;
  Node *head = NULL;
  Node *tail = NULL;

  void push(int value) {
    Node *n = new Node(value);

    if (len == 0) {
      head = n;
      tail = n;
    } else {
      n->prev = tail;
      tail->next = n;
      tail = n;
    }

    len++;
  }

  void display(int direction = 1) {
    if (direction == 1) {
      Node *n = head;

      while (n) {
        cout << n->value << endl;
        n = n->next;
      }
    } else {
      Node *n = tail;

      while (n) {
        cout << n->value << endl;
        n = n->prev;
      }
    }
  }

  void insert(int index, int value) {
    if (index < 0 || index > len) {
      throw std::out_of_range("Index out of range");
    }

    Node *n = new Node(value);
    if (index == 0) {
      head->prev = n;
      n->next = head;
      head = n;

      return;
    } else if (index == len) {
      n->prev = tail;
      tail->next = n;
      tail = n;
    } else {
      Node *current = head;

      int i = 0;
      while (index - 1 > i) {
        current = current->next;
        i++;
      }

      for (int i = 0; i < index; i++)
        current = current->next;

      n->prev = current->prev;
      n->next = current;

      current->prev->next = n;
      current->prev = n;
    }
    len++;
  }
};

int main() {
  DLinkedList dlk;

  dlk.push(1);
  dlk.push(3);
  dlk.push(4);
  try {
    dlk.insert(1, 2);
    dlk.insert(0, 0);
    dlk.insert(0, -1);
  } catch (const std::out_of_range &e) {
    cout << "Out of range error: " << e.what() << endl;
  } catch (...) {
    cout << "An erro Acured while inserting value" << endl;
  }
  cout << "Display in order" << endl;
  dlk.display();
  cout << "Display cros order" << endl;
  dlk.display(-1);

  // cout << dlk.len << endl;
  return 0;
}
