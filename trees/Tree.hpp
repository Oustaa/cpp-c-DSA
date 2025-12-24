#include "./TreeNode.hpp"
#include "../queue/Queue.hpp"

template<typename T>

class Tree{
public:
  TreeNode<T> root;

  void create(){
    Queue<TreeNode<int> *> q;

    root = new TreeNode<int>;
    cout << "Enter root value: ";
    cin >> root->value;
  
    q.enqueue(root);

    int userValue;
    while (q.isEmpty() == false) {
      TreeNode<int> *currentNode = q.dequeue();  

      // right child
      cout << "Enter Right child for " << currentNode->value << ": ";
      cin >> userValue;
      if (userValue != -1) {
        TreeNode<int> *rChild = new TreeNode<int>(userValue);
        q.enqueue(rChild);
      }

      // left child
      cout << "Enter Left child for " << currentNode->value << ": ";
      cin >> userValue;
      if (userValue != -1) {
        TreeNode<int> *lChild = new TreeNode<int>(userValue);
        q.enqueue(lChild);
      }
    }
  }
};
