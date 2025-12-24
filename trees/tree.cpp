#include "./Tree.hpp"

using namespace std;

int main () {
  Tree<int> tree;

  tree.create();
  cout << "Pre Order: ";
  Tree<int>::printPreOrder(tree.root);
  cout << endl;
  cout << "In Order: ";
  Tree<int>::printInOrder(tree.root);
  cout << endl;
  cout << "Post Order: ";
  Tree<int>::printPostOrder(tree.root);
  cout << endl;
  cout << "tree level is: " << Tree<int>::height(tree.root) << endl;
  cout << "tree leaf nodes are: " << Tree<int>::leafNodes(tree.root) << endl;
  cout << "tree external nodes are: " << Tree<int>::externalNodes(tree.root) << endl;
}
