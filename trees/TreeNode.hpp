#include <iostream>

using namespace std;

template<class T>
class TreeNode {
public:
  T value;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode() : value(), left(nullptr), right(nullptr) {}

  TreeNode(T value) : value(value), left(nullptr), right(nullptr) {}

  friend ostream &operator<<(ostream &o, TreeNode<T> &node) {
    o << node.value;

    return o;
  } 
};
