#include <iostream>
#include <fstream>
#include <queue>

#define INPUT_FILE "input.txt"
using namespace std;

class BinaryTreeNode {
private:
  int _value;
  BinaryTreeNode *_left;
  BinaryTreeNode *_right;
public:
  BinaryTreeNode () : _value (0), _left (nullptr), _right (nullptr) {}
  BinaryTreeNode (const int value) : _value (value), _left (nullptr), _right (nullptr) {}
  void insertLeft (BinaryTreeNode * const node) {_left = node;}
  void insertRight (BinaryTreeNode * const node) {_right = node;}
  BinaryTreeNode * left () {return _left;}
  BinaryTreeNode * right () {return _right;}
  int value () {return _value;}
  bool isLeaf ();
};

class BinaryTree {
private:
  BinaryTreeNode * _root;
public:
  BinaryTree () : _root (nullptr) {}
  void insert (BinaryTreeNode * node);
  BinaryTreeNode * root () {return _root;}
};

BinaryTreeNode * largest_btree (BinaryTreeNode * root)
{
  if (root == nullptr)
    return nullptr;

  BinaryTreeNode * current = root;
  while (current->right () != nullptr)
    current = current->right ();
  return current;
}

bool BinaryTreeNode::isLeaf () 
{
  if (_right == nullptr && _left == nullptr)
    return true;
  return false;
}

BinaryTreeNode * second_largest_btree (BinaryTreeNode * const root)
{
  if (root == nullptr || root->isLeaf())
    return nullptr;
  
  BinaryTreeNode * current = root;
  while (current->right() != nullptr)
  {
    if (current->right()->right() != nullptr)
      current = current->right ();
    else 
    {
      if (current->right()->left() != nullptr)
        return largest_btree (current->right()->left());
      else
        return current;
    }
  }
  if (current->left() != nullptr)
    return largest_btree (current->left());

  //throw something because this shouldn't execute
  return nullptr;
}   
  
void deleteBinaryTree (BinaryTreeNode * root);
void printBinaryTree (BinaryTreeNode * root);

int main () {
  ifstream f(INPUT_FILE);
  BinaryTree btree;

  if (!f.is_open ())
  {
    cout << "can not open " << INPUT_FILE << endl;
    return -1;
  }
  
  int n; f >> n;
  while (!f.eof () && !f.fail ())
  {
    btree.insert (new BinaryTreeNode (n));
    f >> n;
  }
  cout << "The binary tree is:" << endl;
  printBinaryTree (btree.root());

  cout << "The second largest element: ";
  cout << second_largest_btree (btree.root ())->value () << endl;
  
  deleteBinaryTree (btree.root ());
  return 0;
}

void deleteBinaryTree (BinaryTreeNode * root) {
  queue<BinaryTreeNode*> c;
  c.push (root);
  while (!c.empty ())
  {
    BinaryTreeNode * n = c.front ();
    if (n->left () != nullptr)
      c.push (n->left ());
    if (n->right () != nullptr)
      c.push (n->right ());
    c.pop();
    delete n;
  }
  return;
}

void BinaryTree::insert (BinaryTreeNode * node) {
  if (node == nullptr)
    return;
  if (_root == nullptr)
    _root = node;

  BinaryTreeNode * current = _root;
  while (current != node)
  {
    if (node->value () >= current->value ())
    {
      if (current->right () == nullptr)
        current->insertRight (node);
      current = current->right ();
    } 
    else
    {
      if (current->left () == nullptr)
        current->insertLeft (node);
      current = current->left ();
    }
  }
  return;
}

void printBinaryTree (BinaryTreeNode * root)
{
  queue<BinaryTreeNode*> c;
  int nextLevel = 0, currentLevel = 0;

  if (root == nullptr)
    return;
 
  c.push (root);currentLevel = 1;
  while (!c.empty ())
  {
    BinaryTreeNode * n = c.front (); c.pop ();
    currentLevel--;
    cout << n->value () << " ";
    if (n->left () != nullptr)
    {
      nextLevel++;
      c.push (n->left ());
    }
    if (n->right () != nullptr)
    {
      nextLevel++;
      c.push (n->right ());
    }
    if (currentLevel == 0)
    {
      currentLevel = nextLevel;
      nextLevel = 0;
      cout << endl;
    }
  }
  return;
}
