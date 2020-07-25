#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Uber:

Given a binary tree, and a target number, find if there is a path from the root to any leaf that sums up to the target.

Here's an example and some starter code.

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def target_sum_bst(root, target):
  # Fill this in.

#      1
#    /   \
#   2     3
#    \     \
#     6     4
n6 = Node(6)
n4 = Node(4)
n3 = Node(3, None, n4)
n2 = Node(2, None, n6)
n1 = Node(1, n2, n3)

print(target_sum_bst(n1, 9))
# True
# Path from 1 -> 2 -> 6

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};

int dfs(Node* node) {
	return !node ? 0 : dfs(node->left) + dfs(node->right) + node->val;
}

bool reconstructPath(Node* node, int sum, vector<int> *path) {
	if (sum == 0) return true;
	if (!node) return false;

	bool left = reconstructPath(node->left, sum-node->val, path);
	bool right = reconstructPath(node->right, sum-node->val, path);

	if (left || right) path->emplace_back(node->val);
	
	return left || right;
}

pair<bool, vector<int>> targetSumBST(Node* root, int k) {
	bool ans=false;
	vector<int> path;
	
	if (!root) return {ans, path};
	
	ans = dfs(root->left) + root->val == k || dfs(root->right) + root->val == k;
	
	if (ans) reconstructPath(root, k, &path);
	
	return {ans, path};
}

void print(pair<bool, vector<int>> ans) {
	cout << ans.first << "\n";
	for (int i=ans.second.size()-1; i>=0; i--) {
		cout << ans.second[i];
		if (i>0) cout << " -> ";
	}
	cout << "\n";
}

int main(){
	Node* n6 = new Node(6);
	Node* n4 = new Node(4);
	Node* n3 = new Node(3, nullptr, n4);
	Node* n2 = new Node(2, nullptr, n6);
	Node* n1 = new Node(1, n2, n3);

	print(targetSumBST(n1, 9)); // true\n 1 -> 2 -> 6
	print(targetSumBST(n1, 8)); // true\n 1 -> 3 -> 4
	print(targetSumBST(n1, 7)); // false

	return 0;
}