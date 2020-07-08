#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

Given a binary tree, return the list of node values in zigzag order traversal. Here's an example

# Input:
#         1
#       /   \
#      2     3
#     / \   / \
#    4   5 6   7
#
# Output: [1, 3, 2, 4, 5, 6, 7]

Here's some starter code

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def zigzag_order(tree):
  # Fill this in.

n4 = Node(4)
n5 = Node(5)
n6 = Node(6)
n7 = Node(7)
n2 = Node(2, n4, n5)
n3 = Node(3, n6, n7)
n1 = Node(1, n2, n3)

print(zigzag_order(n1))
# [1, 3, 2, 4, 5, 6, 7]

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};

void dfs(Node* node, vector<int>* ans, bool flip) {
	if (!node) return;
	if (flip) {
		if (node->left != nullptr) 
			ans->emplace_back(node->left->val);
		if (node->right != nullptr)
			ans->emplace_back(node->right->val);
	} else {
		if (node->right != nullptr)
			ans->emplace_back(node->right->val);
		if (node->left != nullptr) 
			ans->emplace_back(node->left->val);
	}
	
	dfs(node->left, ans, !flip);
	dfs(node->right, ans, !flip);
}

vector<int> zigzagOrder(Node* root) {
	vector<int> ans;
	if (!root) return ans;
	ans.emplace_back(root->val);
	dfs(root, &ans, false);
	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n2 = new Node(2, n4, n5);
	Node* n3 = new Node(3, n6, n7);
	Node* n1 = new Node(1, n2, n3);
	print(zigzagOrder(n1)); // [1, 3, 2, 4, 5, 6, 7]

	return 0;
}