#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*

This problem was recently asked by Google:

Given a binary tree, find and return the largest path from root to leaf.

Here's an example and some starter code:

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def largest_path_sum(tree):
  # Fill this in.

tree = Node(1)
tree.left = Node(3)
tree.right = Node(2)
tree.right.left = Node(4)
tree.left.right = Node(5)
#    1
#  /   \
# 3     2
#  \   /
#   5 4
print(largest_path_sum(tree))
# [1, 3, 5]

*/

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int val): value(val), left(nullptr), right(nullptr) {};
};

int dfs(Node* root) {
	if (!root) return 0;
	int left = dfs(root->left);
	int right = dfs(root->right);
	return max(left, right) + root->value;
}

// credit: https://www.techiedelight.com/find-maximum-sum-root-to-leaf-path-binary-tree/
bool reconstructSumPath(Node* root, int sum, vector<int>* v) {
	if (sum == 0) return true;
	if (!root) return false;
	bool left = reconstructSumPath(root->left, sum-root->value, v);
	bool right = reconstructSumPath(root->right, sum-root->value, v);

	if (left || right) v->emplace_back(root->value);

	return left || right;
}

vector<int> largestPathSum(Node* root) {
	vector<int> ans;
	int sum = max(dfs(root->left), dfs(root->right)) + root->value;
	reconstructSumPath(root, sum, &ans);
	return ans;
}

void print(vector<int> v) {
	cout << "[";
	for (int i=v.size()-1; i>=0; i--) {
		cout << v[i];
		if (i > 0) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	/*
	        1
	      /   \
	     3     2
	      \   /
	       5 4
	*/
	Node* treeA = new Node(1);
	treeA->left = new Node(3);
	treeA->right = new Node(2);
	treeA->right->left = new Node(4);
	treeA->left->right = new Node(5);
	print(largestPathSum(treeA)); // [1, 3, 5];

	/*
	          1
	      /      \
	     2        3
	      \      / \
	       4    7   5
	           /
	          10
	*/
	Node* treeB = new Node(1);
	treeB->left = new Node(2);
	treeB->left->right = new Node(4);
	treeB->right = new Node(3);
	treeB->right->left = new Node(7);
	treeB->right->left->left = new Node(10);
	treeB->right->right = new Node(5);
	print(largestPathSum(treeB)); // [1, 3, 7, 10];

	/*
	        1
	      /   \
	     3     2
	      \   /
	       5 4
	          \
	           6
	          / \
	         10 20
	             \
	             15
	*/
	Node* treeC = new Node(1);
	treeC->left = new Node(3);
	treeC->right = new Node(2);
	treeC->right->left = new Node(4);
	treeC->left->right = new Node(5);
	treeC->right->left->right = new Node(6);
	treeC->right->left->right->left = new Node(10);
	treeC->right->left->right->right = new Node(20);
	treeC->right->left->right->right->right = new Node(15);
	print(largestPathSum(treeC)); // [1, 2, 4, 6, 20, 15];

	return 0;
}