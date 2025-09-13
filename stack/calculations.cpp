#include <iostream>

using namespace std;

template <typename T>
struct Node {
  T value;
  struct Node *next;
};

template <typename T>
class Stack {
  struct Node<T> *top;
 
public:
  void push(T value){
    struct Node<T> *node = new Node<T>{value};
    if (node == nullptr){
      cout << "stack is full" << endl;
    }
    else {
      node->next = top;
      top = node;
    }
  }

  T pop() {
    T deleted;
    
    if (top != nullptr){
      deleted = top->value;
      top = top->next;
    }else {
      cout << "stack is empty" << endl;
    }

    return deleted;
  } 

  void display() {
  struct Node<T> *temp = top;
    while(temp){
      cout << temp->value << ", ";
      temp = temp->next;
    }

    cout << endl;
  }
  
  T peak(){
    T top_value;
    if (top != nullptr) 
      top_value = top->value;

    return top_value;
  }

  bool isEmpty() {
    if (top == nullptr) return true;
    return false;
  }

  bool isFull() {
    struct Node<T> *temp = new Node<T>();
    bool is_full = false;

    if (temp == nullptr) is_full = true;

    delete temp;
    return is_full;
  }
};

string from_infix_to_postFix(string expresion){
  string converted = "";

  return converted;
}


int main () {
  Stack<int> *st = new Stack<int>();

  st->push(1);
  st->push(2);
  st->push(3);
  st->push(4);
  st->push(5);

  cout << "deleted value is: " << st->pop() << endl;

  st->display();

  cout << st->peak() << endl;

  return 0;
}
