/*
In Binary Tree, Inorder successor of a node is the next node in inorder traversal of the Binary Tree. Inorder Successor in NULL for the last node in Inorder traversal.

In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of input node. So, it is sometimes important to find next node in sorted order.
*/
#include <iostream>

class BSTNode {
  int m_value;
  BSTNode *m_parent;
  BSTNode *m_left;
  BSTNode *m_right;
public:
  BSTNode(int);
  BSTNode* left();
  BSTNode* right();
  BSTNode* parent();
  int value();
  BSTNode* insert(BSTNode*);
};

BSTNode::BSTNode(int v) {
  m_value = v;
  m_parent = NULL;
  m_left = NULL;
}

BSTNode* BSTNode::left() {
  return m_left;
}

BSTNode* BSTNode::right() {
  return m_right;
}

BSTNode* BSTNode::parent() {
  return m_parent;
}

int BSTNode::value() {
  return m_value;
}

//If the inserted node value is equal to a node in the BST
// then I put the inserted node in the right hand side of the BST
BSTNode* BSTNode::insert(BSTNode *n) {
  if (n == NULL)
    return NULL;

  if (m_value < n->value())
  {
    if (m_left == NULL) {
      m_left = n;
      n->setParent(m_left);
    } else {
      m_left->insert(n);
    }
  } else {
    if (m_right == NULL) {
      m_right = n;
      n->setParent(m_right);
    } else {
      m_right->insert(n);
    }
  }

  return n;
}

class BST {
  BSTNode *m_root;
  int m_number;
public:
  BST (BSTNode*);
  BSTNode* insert (BSTNode*);
  BSTNode* pop ();
  BSTNode* root();
  ~BST ();
};

BST::BST (BSTNode *n) {
  m_root = n;
  m_number = 0;
}

BSTNode* BST::insert (BSTNode *node) {
  
  if (m_root == NULL)
  {
    m_root = node;
    m_number = 0;
  }

  m_root->insert (node);
  m_number++;
  return node;
}

BSTNode* BST::root () {
  return m_root;
}

int main () {
  BST *bst = new BST(new BSTNode (20));
  bst->insert (new BSTNode (8));
  bst->insert (new BSTNode (22));
  bst->insert (new BSTNode (4));
  bst->insert (new BSTNode (12));
  bst->insert (new BSTNode (10));
  bst->insert (new BSTNode (14));
  
  

  return 0;
}
