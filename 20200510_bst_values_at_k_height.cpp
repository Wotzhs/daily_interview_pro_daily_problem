#include <iostream>
#include <vector>
#include <queue>

/*

This problem was recently asked by Amazon:

Given a binary tree, return all values given a certain height h.

Here's a starting point:

class Node():
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def valuesAtHeight(root, height):
  # Fill this in.

#     1
#    / \
#   2   3
#  / \   \
# 4   5   7

a = Node(1)
a.left = Node(2)
a.right = Node(3)
a.left.left = Node(4)
a.left.right = Node(5)
a.right.right = Node(7)
print valuesAtHeight(a, 3)
# [4, 5, 7]

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

std::vector<int> bstValuesAtHeight(Node* root, int h) {
	std::vector<int> v;
	if (!root || h < 1) return v;
	
	std::queue<std::pair<Node*, int>> q;
	q.emplace(std::make_pair(root, 1));

	while(q.size()) {
		std::pair<Node*, int> p = q.front();
		q.pop();

		if (p.second == h) v.emplace_back(p.first->val);
		if (p.first->left != nullptr) q.emplace(std::make_pair(p.first->left, p.second+1));
		if (p.first->right != nullptr) q.emplace(std::make_pair(p.first->right, p.second+1));
	}

	return v;
}

int main() {

	/*
	       1
	     /   \
	    2     3
	   / \     \
	  4   5     7
	*/

	Node* a = new Node(1);
	a->left = new Node(2);
	a->right = new Node(3);
	a->left->left = new Node(4);
	a->left->right = new Node(5);
	a->right->right = new Node(7);

	for (int i: bstValuesAtHeight(a, 3))
		std::cout << i << " ";
	std::cout << "\n"; // 4 5 7

	for (int i: bstValuesAtHeight(a, 2))
		std::cout << i << " ";
	std::cout << "\n"; // 2 3

	/*
	       1
	     /   \
	    2     3
	   / \     \
	  4   5     7
	     / \   /
	    8   9 10
	*/

	Node* b = new Node(1);
	b->left = new Node(2);
	b->right = new Node(3);
	b->left->left = new Node(4);
	b->left->right = new Node(5);
	b->right->right = new Node(7);
	b->left->right->left = new Node(8);
	b->left->right->right = new Node(9);
	b->right->right->left = new Node(10);

	for (int i: bstValuesAtHeight(b, 4))
		std::cout << i << " ";
	std::cout << "\n"; // 8 9 10

	return 0;
}