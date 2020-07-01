#include <iostream>
#include <queue>
using namespace std;

/*

This problem was recently asked by Facebook:

Given two binary trees that are duplicates of one another, and given a node in one tree, find that correponding node in the second tree.

For instance, in the tree below, we're looking for Node #4.

For this problem, you can assume that:
- There can be duplicate values in the tree (so comparing node1.value == node2.value isn't going to work).

Can you solve this both recursively and iteratively?

class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def findNode(a, b, node):
  # Fill this in.

#  1
# / \
#2   3
#   / \
#  4*  5
a = Node(1)
a.left = Node(2)
a.right = Node(3)
a.right.left = Node(4)
a.right.right = Node(5)

b = Node(1)
b.left = Node(2)
b.right = Node(3)
b.right.left = Node(4)
b.right.right = Node(5)

print(findNode(a, b, a.right.left))
# 4

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v) {};
};

Node* findNode(Node* a, Node* b, Node* node) {
	if (a == nullptr || b == nullptr) return nullptr;
	if (a->val == node->val && b->val == node->val) return node;
	Node* left = findNode(a->left, b->left, node);
	Node* right = findNode(a->right, b->right, node);
	return left == nullptr ? right : left;
}

void print(Node* node) {
	if (!node) { 
		cout << "NULL";
		return;
	}

	cout << "node->val: " << node->val;
	if (node->left != nullptr)cout << " node->left->val: " << node->left->val;
	if (node->right != nullptr) cout << " node->right->val: " << node->right->val;
	cout << "\n";
}

int main(){
	/*
	      1
	     / \
	    2   3
	       / \
	      4*  5
	*/
	Node* a = new Node(1);
	a->left = new Node(2);
	a->right = new Node(3);
	a->right->left = new Node(4);
	a->right->right = new Node(5);

	/*
	      1
	     / \
	    2   3
	       / \
	      4*  5
	*/
	Node* b = new Node(1);
	b->left = new Node(2);
	b->right = new Node(3);
	b->right->left = new Node(4);
	b->right->right = new Node(5);

	print(findNode(a, b, a->right->left)); // node->val: 4
	print(findNode(a, b, a->right->right)); // node->val: 5
	print(findNode(a, b, b)); // node->val: 1 node->left->val: 2 node->right->val: 3

	return 0;
}