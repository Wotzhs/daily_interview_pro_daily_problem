#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

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

// TC - o(nm)
// SC - o(nm)
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};

int dfs(Node* node, unordered_map<string, vector<Node*>> &mp) {
	if (!node) return 0;
	string key = to_string(node->val)+to_string(dfs(node->left, mp))+to_string(dfs(node->right, mp));
	mp[key].emplace_back(node);
	return node->val;
}

vector<vector<Node*>> dupTrees(Node* root) {
	unordered_map<string, vector<Node*>> mp;
	dfs(root, mp);

	vector<vector<Node*>> ans;
	for (auto it = mp.begin(); it != mp.end(); it++)
		if (it->second.size()>1) ans.emplace_back(it->second);
	return ans;
}

void printTree(Node* root) {
	if (!root) return;
	cout << "(" << root->val;
	if (root->left) {
		cout << ", ";
		printTree(root->left);
	}
	if (root->right) {
		cout << ", ";
		printTree(root->right);
	}
	cout << ")" ;
}

void print(vector<vector<Node*>> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "[";
		for (int j=0; j<ans[i].size(); j++) {
			printTree(ans[i][j]);
			if (j<ans[i].size()-1) cout << ", ";
		}
		cout << "]";
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	/*
	       1
	      / \
	     2   2
	    /   /
	   3   3
	*/
	Node* n3_1 = new Node(3);
	Node* n2_1 = new Node(2, n3_1, nullptr);
	Node* n3_2 = new Node(3);
	Node* n2_2 = new Node(2, n3_2, nullptr);
	Node* n1 = new Node(1, n2_1, n2_2);

	print(dupTrees(n1)); // [[(2, (3)), (2, (3))], [3, 3]]

	/*
	        1
	      /   \
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

	print(dupTrees(m1)); // [(2, (3), (4)), (2, (3), (4)), [3, 3], [4, 4]]
	
	return 0;
}
