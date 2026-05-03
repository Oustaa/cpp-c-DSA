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
    out << "Value of the node is: " << b.value;
    return out;
  }
};

template <class T> class SearchTree {
public:
  Node<T> *head = nullptr;

  int Search() { return 0; }

  void insert(T value) {
    Node<T> *temp = new Node<T>(value, NULL, NULL);

    if (head == nullptr) {
      head = temp;
      return;
    }

    Node<T> *headTemp = head;
    Node<T> *parent = nullptr;

    while (headTemp != NULL) {
      if (headTemp->value == value) {
        break;
      }

      parent = headTemp;
      if (headTemp->value > value) {
        headTemp = headTemp->lNode;
      } else {
        headTemp = headTemp->rNode;
      }
    }

    if (parent->value > value) {
      parent->lNode = new Node<T>(value, NULL, NULL);
    } else {
      parent->rNode = new Node<T>(value, NULL, NULL);
    }
  }

  template <typename F> void travers(Node<T> *node, F callback) {
    if (node == nullptr)
      return;

    travers(node->lNode, callback);
    callback(node);
    travers(node->rNode, callback);
  }

  void display() {
    travers(head, [](Node<T> *node) { cout << node->value << " > "; });
    cout << endl;
  }

  int getNodeNumber() { return 1; }

  void displayWithLoop() {
    if (head == nullptr) {
      cout << "Tree is empty" << endl;
      return;
    }

    stack<Node<T> *> stk;
    Node<T> *current = head;

    while (!stk.empty() || current != nullptr) {
      while (current) {
        stk.push(current);
        current = current->lNode;
      }

      current = stk.top();
      stk.pop();

      cout << current->value << " > ";

      current = current->rNode;
    }

    cout << endl;
  }

  bool search(T value) {
    bool result = false;

    travers(head, [&result, value](Node<T> *node) {
      if (result != true)
        result = (node->value == value);
    });

    return result;
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
  // stree.displayWithLoop();

  cout << "saerch for 8 before, " << stree.search(8) << endl;
  stree.insert(8);
  cout << "saerch for 8 after, " << stree.search(8) << endl;
  stree.display();

  return 0;
}
