#include <iostream>

using namespace std;

template <typename T> struct Node {
  T value;
  struct Node *next;
};

template <typename T> class LinkedList {
public:
  struct Node<T> *head = NULL;
  struct Node<T> *tail = NULL;
  int lenght = 0;

  void push(T value) {
    struct Node<T> *n = new Node<T> {
      value,
    };
    if (head == NULL) {
      head = tail = n;
    } else {
      tail->next = n;
      tail = n;
    }
    lenght++;
  };

  void Display() {
    Node<T> *temp = head;
    while (temp != NULL) {
      cout << temp->value;
      if (temp->next != NULL) {
        cout << ",";
      }
      temp = temp->next;
    }
    cout << endl;
  }

  int insert(int index, T value) {
    Node<T> *temp = head;
    if (index > lenght || index < 0) {
      return -1;
    }

    Node<T> *node = new Node<T>{value};
    if (index == 0) {
      node->next = head;
      head = node;
      return 0;
    }

    for (int i = 1; i < index; i++)
      temp = temp->next;

    Node<T> *current_next = temp->next;
    temp->next = node;
    node->next = current_next;

    return index;
  }
  // sort linked list
  // merger two linked lists
  // is it has a loop
};

class IntLinkedList : public LinkedList<int> {
public:
  int getMax() {
    Node<int> *temp = head;
    int current_max = head->value;

    while (temp != NULL) {
      if (temp->value > current_max)
        current_max = temp->value;
      temp = temp->next;
    }

    return current_max;
  }
};

int main() {
  IntLinkedList il;
  il.push(1);
  il.push(3);
  il.push(4);
  il.insert(1, 2);
  il.insert(0, 0);
  il.insert(2, 110);

  il.Display();
  // l.Display();
  cout << "Max is " << il.getMax() << endl;
  // LinkedList<string> ls;
  // ls.push("Youness");
  // ls.push("Oussama");
  // ls.push("Abde El adim");
  // ls.push("Khalid");
  // ls.Display();

  return 0;
}
