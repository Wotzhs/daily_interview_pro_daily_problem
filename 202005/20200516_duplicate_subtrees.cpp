#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*

This problem was recently asked by Uber:

Given a binary tree, find all duplicate subtrees (subtrees with the same value and same structure) and return them as a list of list [subtree1, subtree2, ...] where subtree1 is a duplicate of subtree2 etc.

Here's an example and some starter code:

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

  def __repr__(self):
    if self.left and self.right:
      return f"({self.value}, {self.left}, {self.right})"
    if self.left:
      return f"({self.value}, {self.left})"
    if self.right:
      return f"({self.value}, None, {self.right})"
    return f"({self.value})"

def dup_trees(root):
  # Fill this in.

n3_1 = Node(3)
n2_1 = Node(2, n3_1)
n3_2 = Node(3)
n2_2 = Node(2, n3_2)
n1 = Node(1, n2_1, n2_2)
# Looks like
#     1
#    / \
#   2   2
#  /   /
# 3   3

print(dup_trees(n1))
# [[(3), (3)], [(2, (3)), (2, (3))]]
# There are two duplicate trees
#
#     2
#    /
#   3
# and just the leaf
#
# 3

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};

std::vector<Node*> dupTrees(Node* root) {
	std::vector<Node*> ans;
	if (!root) return ans;
	std::queue<Node*> q;
	q.emplace(root);
	while(q.size()) {
		Node* prev = q.front();
		q.pop();

		for (int i=0; i < q.size(); i++) {
			Node* curr = q.front();
			q.pop();
			if (
				curr->val == prev->val 
				&& (
					curr->left == prev->left
					|| (curr->left != nullptr && prev->left != nullptr && curr->left->val == prev->left->val)
				)
				&& (
					curr->right == prev->right
					|| (curr->right != nullptr && prev->right != nullptr && curr->right->val == prev->right->val)
				)
			) {
				ans.emplace_back(prev);
				ans.emplace_back(curr);
			}
			if (curr->left != nullptr) q.emplace(curr->left);
			if (curr->right != nullptr) q.emplace(curr->right);
		}

		if (prev->left != nullptr) q.emplace(prev->left);
		if (prev->right != nullptr) q.emplace(prev->right);
	}

	std::reverse(ans.begin(), ans.end());
	return ans;
}

void print(Node* root) {
	if(!root) return;
	if (root->left != nullptr && root->right != nullptr) {
		std::cout << "(" << root->val << ", ";
		print(root->left);
		std::cout<<", ";
		print(root->right);
		std::cout<<")";
		return;
	}
	if (root->left != nullptr) {
		std::cout << "(" << root->val << ", ";
		print(root->left);
		std::cout << ")";
		return;
	}
	if (root->right != nullptr) {
		std::cout << "(" << root->val << ", None, ";
		print(root->right);
		std::cout << ")";
		return;
	}

	std::cout << "(" << root->val << ")";
}

int main() {
	/*
	      1
	     / \
	    2  2
	   /  /
	  3  3
	*/

	Node* n3_1 = new Node(3);
	Node* n2_1 = new Node(2, n3_1, nullptr);
	Node* n3_2 = new Node(3);
	Node* n2_2 = new Node(2, n3_2, nullptr);
	Node* n1 = new Node(1, n2_1, n2_2);

	for (auto node: dupTrees(n1))
		print(node); // (3)(3)(2, (3))(2, (3))
	std::cout << "\n";

	/*
	         1
	      /    \
	     2     2
	    / \   / \
	   3   4 3   4
	*/

	Node* m4_1 = new Node(4);
	Node* m3_1 = new Node(3);
	Node* m2_1 = new Node(2, m3_1, m4_1);
	Node* m4_2 = new Node(4);
	Node* m3_2 = new Node(3);
	Node* m2_2 = new Node(2, m3_2, m4_2);
	Node* m1 = new Node(1, m2_1, m2_2);

	for (auto node: dupTrees(m1))
		print(node); // (2, (3), (4))(2, (3), (4))
	std::cout << "\n";

	return 0;
}