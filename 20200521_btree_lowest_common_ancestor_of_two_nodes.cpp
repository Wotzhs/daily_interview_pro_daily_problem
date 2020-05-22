#include <iostream>
#include <vector>
#include <unordered_map>

/*

This problem was recently asked by Apple:

You are given the root of a binary tree, along with two nodes, A and B. Find and return the lowest common ancestor of A and B. For this problem, you can assume that each node also has a pointer to its parent, along with its left and right child.

class TreeNode:
  def __init__(self, val):
    self.left = None
    self.right = None
    self.parent = None
    self.val = val


def lowestCommonAncestor(root, a, b):
  # Fill this in.

#   a
#  / \
# b   c
#    / \
#   d*  e*
root = TreeNode('a')
root.left = TreeNode('b')
root.left.parent = root
root.right = TreeNode('c')
root.right.parent = root
a = root.right.left = TreeNode('d')
root.right.left.parent = root.right
b = root.right.right = TreeNode('e')
root.right.right.parent = root.right

print lowestCommonAncestor(root, a, b).val
# c

*/

class TreeNode {
public:
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(char v): val(v), left(nullptr), right(nullptr), parent(nullptr) {};
};

char lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
	std::vector<char> va, vb;
	while (a != nullptr) {
		va.emplace_back(a->val);
		a = a->parent;
	}

	while (b != nullptr) {
		vb.emplace_back(b->val);
		b = b->parent;
	}

	std::unordered_map<char, bool> mp;
	for (char ch: va)
		mp[ch] = true;
	for (char ch: vb) {
		if (mp.find(ch) != mp.end()) return ch;
	}

	return '\0';
}

int main() {
	/*
	       a
	      / \
	     b   c
	        / \
	       d  e
	*/

	TreeNode* rootA = new TreeNode('a');
	rootA->left = new TreeNode('b');
	rootA->left->parent = rootA;
	rootA->right = new TreeNode('c');
	rootA->right->parent = rootA;
	TreeNode* a = rootA->right->left = new TreeNode('d');
	rootA->right->left->parent = rootA->right;
	TreeNode* b = rootA->right->right = new TreeNode('e');
	rootA->right->right->parent = rootA->right;

	std::cout << lowestCommonAncestor(rootA, a, b) << "\n"; // c
	std::cout << lowestCommonAncestor(rootA, rootA->left, rootA->right) << "\n"; // a
	std::cout << lowestCommonAncestor(rootA, rootA->left, b) << "\n"; // a

	/*
	       a
	      / \
	     b   c
	    /   / \
	   d   e   f
	            \
	             g
	*/

	TreeNode* rootB = new TreeNode('a');
	rootB->left = new TreeNode('b');
	rootB->left->parent = rootB;
	rootB->right = new TreeNode('c');
	rootB->right->parent = rootB;
	TreeNode* d = rootB->left->left = new TreeNode('d');
	rootB->left->left->parent = rootB->left;
	TreeNode* e = rootB->right->left = new TreeNode('e');
	rootB->right->left->parent = rootB->right;
	TreeNode* f = rootB->right->right = new TreeNode('f');
	rootB->right->right->parent = rootB->right;
	TreeNode* g = rootB->right->right->right = new TreeNode('g');
	rootB->right->right->right->parent = rootB->right->right;

	std::cout << lowestCommonAncestor(rootB, e, g) << "\n"; // c
	std::cout << lowestCommonAncestor(rootB, d, g) << "\n"; // a
	std::cout << lowestCommonAncestor(rootB, rootB->left, f) << "\n"; // a

	return 0;
}