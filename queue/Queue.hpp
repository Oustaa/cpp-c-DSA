#include <iostream>

using namespace std;

template <class T>
class Node {
public:
  T value;
  Node *next;

  Node(T value) : value(value), next(nullptr) {}

  friend ostream &operator<<(ostream &o, Node *node){
    o << node->value;
    return o;
  }
};

template  <typename  T>
class Queue {
private:
  Node<T> *front = NULL;
  Node<T> *rare = NULL;
 
public:
  void enqueue(T value){
    Node<T> *temp = new Node(value);
    if (rare == nullptr && front == nullptr) {
      front = rare = temp;
    } else {
      rare->next = temp;
      rare = temp;
    }
  }

  T dequeue () {
    T deleted;
    if (front == nullptr){
      cout << "Queue is empty" << endl;
    } else {
      deleted = front->value;
      front = front->next;
    } 
    if (front == nullptr) {
      rare = nullptr;
    }

    return deleted;
  }

  void display(){
    if (isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }

    Node<T> *temp = front;

    while (temp) {
      cout << temp->value;

      if (temp->next) {
        cout << " << ";
      }

      temp = temp->next;
    }

    cout << endl;
  }

  bool isEmpty() {
    return front == nullptr;
  }
};
