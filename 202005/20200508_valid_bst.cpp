#include <iostream>
#include <climits>

/*

This problem was recently asked by Facebook:

You are given the root of a binary search tree. Return true if it is a valid binary search tree, and false otherwise. Recall that a binary search tree has the property that all values in the left subtree are less than or equal to the root, and all values in the right subtree are greater than or equal to the root.

Here's a starting point:

class TreeNode:
  def __init__(self, key):
    self.left = None
    self.right = None
    self.key = key

def is_bst(root):
  # Fill this in.

a = TreeNode(5)
a.left = TreeNode(3)
a.right = TreeNode(7)
a.left.left = TreeNode(1)
a.left.right = TreeNode(4)
a.right.left = TreeNode(6)
print is_bst(a)

#    5
#   / \
#  3   7
# / \ /
#1  4 6

*/

class TreeNode {
public:
	int key;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int k): key(k) {};
};

bool dfs(TreeNode* node, int max, int min) {
	if (!node) return true;
	if (node->key > max || node->key < min) return false;
	return dfs(node->left, node->key, min) && dfs(node->right, max, node->key);
}

bool isValidBST(TreeNode* root) {
	return !root ? false : dfs(root->left, root->key, INT_MIN) && dfs(root->right, INT_MAX, root->key);
}

int main() {

	/*
	       5
	     /   \
	    3     7
	  /  \   /
	 1   4  6
	*/

	TreeNode a(5);
	a.left = new TreeNode(3);
	a.right = new TreeNode(7);
	a.left->left = new TreeNode(1);
	a.left->right = new TreeNode(4);
	a.right->left = new TreeNode(6);
	std::cout << isValidBST(&a) << "\n"; // true


	/*
	       8
	     /   \
	    3     7
	  /  \   /
	 1   4  6
	*/

	TreeNode b(8);
	b.left = new TreeNode(3);
	b.right = new TreeNode(7);
	b.left->left = new TreeNode(1);
	b.left->right = new TreeNode(4);
	b.right->left = new TreeNode(6);
	std::cout << isValidBST(&b) << "\n"; // false

	return 0;
}