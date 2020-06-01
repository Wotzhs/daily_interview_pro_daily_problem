#include <iostream>
#include <vector>
#include <unordered_map>
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

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v): val(v), left(nullptr), right(nullptr) {};
	TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {};
};

void dfs(TreeNode* node, int sum, vector<int>* path, unordered_map<int, vector<int>> &mp) {
	if (node == nullptr) return;

	sum += node->val;
	path->emplace_back(node->val);

	if (!node->left && !node->right) {
		mp[sum] = *path;
		path->pop_back();
	}

	dfs(node->left, sum, path, mp);
	dfs(node->right, sum, path, mp);
}

pair<bool, vector<int>> targetSumBST(TreeNode* root, int target) {
	vector<int> emptyVector;

	if (!root) return make_pair(false, emptyVector);
	if (target == 0) return make_pair(true, emptyVector);

	unordered_map<int, vector<int>> mp;

	dfs(root->left, root->val, new vector<int>{ root->val}, mp);
	dfs(root->right, root->val, new vector<int>{root->val}, mp);

	if (mp.find(target) != mp.end()) return make_pair(true, mp[target]);

	return make_pair(false, emptyVector);
}

void printResult(pair<bool, vector<int>> p) {
	if (!p.first) {
		cout << "False\n";
		return;
	}
	
	cout << "True\nPath from ";
	for (int i=0; i < p.second.size(); i++) {
		cout << p.second[i];
		if (i != p.second.size()-1) cout << " -> ";
	}
	cout << "\n"; 
}

int main() {

	/*
	       1
	     /   \
	    2     3
	     \     \
	      6    4
	*/

	TreeNode n6(6);
	TreeNode n4(4);
	TreeNode n3(3, nullptr, &n4);
	TreeNode n2(2, nullptr, &n6);
	TreeNode n1(1, &n2, &n3);

	printResult(targetSumBST(&n1, 9)); // True\n 1 -> 2 -> 6

	/*
	       1
	     /   \
	    2     3
	   / \
	  4   5
	     /
	    6
	     \
	      7
	*/

	TreeNode m7(7);
	TreeNode m6(6, nullptr, &m7);
	TreeNode m5(5, &m6, nullptr);
	TreeNode m4(4);
	TreeNode m2(2, &m4, &m5);
	TreeNode m3(3);
	TreeNode m1(1, &m2, &m3);

	printResult(targetSumBST(&m1, 21)); // True\n 1 -> 2 -> 5 -> 6 -> 7

	/*
	       1
	     /   \
	    2     3
	     \
	      4
	*/

	TreeNode o4(4);
	TreeNode o2(2, nullptr, &o4);
	TreeNode o3(3);
	TreeNode o1(1, &o2, &o3);

	printResult(targetSumBST(&o1, 10)); // False

	return 0;
}