/*
  if the BST is 
|     1
|   2   3
|  4 5 6 7

Then the output should be 4, 2, 5, 1, 6, 3, 7
*/

#include <iostream>

using namespace std;

class Node {
  Node *m_left;
  Node *m_right;
  int m_val;
public:
  Node (int val): m_val (val), m_left (NULL), m_right (NULL) {}
  Node (Node *left, Node *right, int val): m_val (val), m_left (left), m_right (right) {}
  int val();
  Node* left();
  Node* right();
  int left (Node *n);
  int right (Node *n);
}; 

int Node::left (Node *n) {
  m_left = n;
  return 0;
}

int Node::right (Node *n) {
  m_right = n;
  return 0;
}

Node* Node::left() {
  return m_left;
}

Node* Node::right() {
  return m_right;
}

int Node::val() {
  return m_val;
}

int traverse (Node *node) {
  if (node == NULL)
    return 0;

  if (node->left() != NULL)
    traverse (node->left());
  cout << node->val() << " ";
  if (node->right() != NULL)
    traverse (node->right());
  return 0;
}

int main () {
  Node *n = new Node (1);
  Node *n2 = new Node (2);
  Node *n3 = new Node (3);
  Node *n4 = new Node (4);
  Node *n5 = new Node (5);
  Node *n6 = new Node (6);
  Node *n7 = new Node (7);
  n->left (n2);
  n->right (n3);  
  n->left()->left (n4);
  n->left()->right (n5);
  n->right()->left (n6);
  n->right()->right (n7);

  traverse (n);
  cout << endl;
  delete n;
  delete n2;
  delete n3;
  delete n4;
  delete n5;
  delete n6;
  delete n7;
  return 0;
}
