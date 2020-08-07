#include <iostream>
using namespace std;

/*

This problem was recently asked by Microsoft:

A unival tree is a tree where all the nodes have the same value. Given a binary tree, return the number of unival subtrees in the tree.

For example, the following tree should return 5:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

The 5 trees are:
- The three single '1' leaf nodes. (+3)
- The single '0' leaf node. (+1)
- The [1, 1, 1] tree at the bottom. (+1)

Here's a starting point:

class Node(object):
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

    def count_unival_subtrees(root):
      # Fill this in.

a = Node(0)
a.left = Node(1)
a.right = Node(0)
a.right.left = Node(1)
a.right.right = Node(0)
a.right.left.left = Node(1)
a.right.left.right = Node(1)

print count_unival_subtrees(a)
# 5

*/

// TC o(n*m)
// SC o(1)
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

int dfs(Node* node) {
	if (!node) return 0;
	int tmp=0;
	if (!node->left && !node->right) tmp=1;
	else if (node->left->val == node->right->val && node->left->val == node->val) tmp=1;
	return tmp+dfs(node->left)+dfs(node->right);
}

int countUnivalSubtrees(Node* root) {
	if (!root) return 0;
	return dfs(root->left)+dfs(root->right);
}

int main() {
	/*
	         0
	        / \
	       1   0
	          / \
	         1   0
		/ \
	       1   1
	*/
	Node* a = new Node(0);
	a->left = new Node(1);
	a->right = new Node(0);
	a->right->left = new Node(1);
	a->right->right = new Node(0);
	a->right->left->left = new Node(1);
	a->right->left->right = new Node(1);

	cout << countUnivalSubtrees(a) << "\n"; //5

	/*
	         0
	        / \
	       1   1
	          / \
	         1   1
		/ \
	       1   1
	*/

	Node* b = new Node(0);
	b->left = new Node(1);
	b->right = new Node(1);
	b->right->left = new Node(1);
	b->right->right = new Node(1);
	b->right->left->left = new Node(1);
	b->right->left->right = new Node(1);

	cout << countUnivalSubtrees(b) << "\n"; //6

	return 0;
}
