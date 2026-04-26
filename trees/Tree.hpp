#include "./TreeNode.hpp"
#include "../queue/Queue.hpp"

template<typename T>

class Tree{
public:
  TreeNode<T> *root;

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
        currentNode->right = rChild;
        q.enqueue(rChild);
      }

      // left child
      cout << "Enter Left child for " << currentNode->value << ": ";
      cin >> userValue;
      if (userValue != -1) {
        TreeNode<int> *lChild = new TreeNode<int>(userValue);
        currentNode->left = lChild;
        q.enqueue(lChild);
      }
    }
  }

  static int leafNodes(TreeNode<int> * node) {
    if (node == nullptr)
      return 0;

    if (!node->left && !node->right) return 1;

    return leafNodes(node->right) + leafNodes(node->left); 
  }

  static int externalNodes(TreeNode<int> * node) {
    if (node) {
      if (node->left || node->right) 
        return 
          leafNodes(node->right) + 
          leafNodes(node->left) + 1; 
    }

    return 0;
  }

  static int height(TreeNode<int> * node) {
    if (node == nullptr)
      return 0;

    int x = height(node->left);
    int y = height(node->right);

    return (x > y ? x : y) + 1;
  }

  static void printPreOrder(TreeNode<int> * root) {
    if (root) {
      cout << root->value << ", ";
      printPreOrder(root->right);
      printPreOrder(root->left);
    }
  } 

  static void printInOrder(TreeNode<int> * root) {
    if (root) {
      printInOrder(root->right);
      cout << root->value << ", ";
      printInOrder(root->left);
    }
  } 

  static void printPostOrder(TreeNode<int> * root) {
    if (root) {
      printPostOrder(root->right);
      printPostOrder(root->left);
      cout << root->value << ", ";
    }
  } 
};
