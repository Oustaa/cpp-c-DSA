#include <iostream>
#include <stack>

using namespace std;

template <class T> class Node {

public:
  T value;
  Node<T> *lNode;
  Node<T> *rNode;

  Node(T value, Node<T> *left, Node<T> *right) {
    this->value = value;
    lNode = left;
    rNode = right;
  }

  friend ostream &operator<<(std::ostream &out, const Node<T> &b) {
    out << "Value of the node is: " << b->value;
    return out;
  }
};

template <class T> class SearchTree {
public:
  Node<T> *head;

  int Search() { return 0; }

  void insert(T value) {
    cout << "value: " << value << endl;

    Node<T> *temp = new Node<T>(value, NULL, NULL);

    if (head == nullptr) {
      head = temp;
      return;
    }

    Node<T> *headTemp = head;

    while (headTemp != NULL) {
      cout << headTemp << endl;
      if (headTemp->value == value) {
        return;
      }

      if (headTemp) {
        if (headTemp->value > value) {
          headTemp = headTemp->lNode;
        } else {
          headTemp = headTemp->rNode;
        }
      } else {
      }
    }
  }

  void display() {
    stack<Node<T> *> stk;
    stk.push(head);

    while (head != nullptr) {
      Node<T> *temp = stk.top();
      stk.pop();
      stk.push(head->lNode);
      stk.push(head->rNode);
    }
  }
};

int main() {
  SearchTree<int> stree;

  stree.insert(20);
  stree.insert(15);
  stree.insert(10);
  stree.insert(40);
  stree.insert(16);
  stree.insert(30);
  stree.insert(45);

  // stree.display();

  return 0;
}
