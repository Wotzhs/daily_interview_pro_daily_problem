#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Twitter:

You are given the root of a binary tree. Find the level for the binary tree with the minimum sum, and return that value.

For instance, in the example below, the sums of the trees are 10, 2 + 8 = 10, and 4 + 1 + 2 = 7. So, the answer here should be 7.

class Node:
  def __init__(self, value, left=None, right=None):
    self.val = value
    self.left = left
    self.right = right

def minimum_level_sum(root):
  # Fill this in.

#     10
#    /  \
#   2    8
#  / \    \
# 4   1    2
node = Node(10)
node.left = Node(2)
node.right = Node(8)
node.left.left = Node(4)
node.left.right = Node(1)
node.right.right = Node(2)

print minimum_level_sum(node)

*/

// n - number of nodes in binary tree
// TC - o(n)
// SC - o(n)
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

int minimumLevelSum(Node* root) {
	if (!root) return 0;
	int ans=INT_MAX;
	queue<Node*> q;
	q.push(root);
	while(q.size()) {
		int n=q.size(), tmpSum=0;
		for (int i=0; i<n; i++) {
			Node* curr = q.front();
			q.pop();
			tmpSum+=curr->val;
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
		ans=min(ans,tmpSum);
	}
	return ans;
}

int main() {
	/*
	       10
	      /  \
	     2    8
	    / \    \
	   4   1    2
	*/

	Node* node = new Node(10);
	node->left = new Node(2);
	node->right = new Node(8);
	node->left->left = new Node(4);
	node->left->right = new Node(1);
	node->right->right = new Node(2);
	cout << minimumLevelSum(node) << "\n"; // 7

	/*
	        10
	      /   \
	     2     1
	    / \   / \
	   4   1 5   2
	*/

	Node* node2 = new Node(10);
	node2->left = new Node(2);
	node2->right = new Node(1);
	node2->left->left = new Node(4);
	node2->left->right = new Node(1);
	node2->right->left = new Node(5);
	node2->right->right = new Node(2);
	cout << minimumLevelSum(node2) << "\n"; // 3

	/*
	        1
	      /   \
	     2     8
	    / \   / \
	   4   1 4   2
	*/

	Node* node3 = new Node(1);
	node3->left = new Node(2);
	node3->right = new Node(8);
	node3->left->left = new Node(4);
	node3->left->right = new Node(1);
	node3->right->left = new Node(4);
	node3->right->right = new Node(2);
	cout << minimumLevelSum(node3) << "\n"; // 1

	return 0;
}
