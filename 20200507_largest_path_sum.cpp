#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

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
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

// pair first tracks the cumulative sum, second tracks the travelled path
std::pair<int, std::vector<int>*> dfs(Node* node, int max, std::vector<int>* path) {
	if (node == NULL) return make_pair(0, path);
	
	path->emplace_back(node->val);

	auto left = dfs(node->left, max, path);
	auto right = dfs(node->right, max, path);

	max = std::max(left.first, right.first);

	return make_pair(node->val+max, path);
}

// remove elements from path not chosen
void removeExtra(std::vector<int>* v, int maxSum) {
	int arrSum=0;
	for (int i: *v)
		arrSum += i;

	int excess = arrSum - maxSum;
	if (excess) {
		auto extra = std::find(v->begin(), v->end(), excess);
		v->erase(extra);	
	}
}

std::vector<int> largestPathSum(Node* root) {
	if (root == NULL) return std::vector<int>();
	
	auto left = dfs(root->left, 0, new std::vector<int> { root->val });
	auto right = dfs(root->right, 0, new std::vector<int> { root->val });

	if (left.first > right.first) {
		removeExtra(left.second, left.first + root->val);
		return *left.second;
	}

	removeExtra(right.second, right.first + root->val);
	return *right.second;
}

int main() {
	/*
		  1
		/   \
	   3	 2
	  	\	/ 
		 5 4		 
	*/
	Node treeA(1);
	treeA.left = new Node(3);
	treeA.right = new Node(2);
	treeA.right->left = new Node(4);
	treeA.left->right = new Node(5);

	for(int i: largestPathSum(&treeA))
		std::cout << i << " ";
	std::cout << "\n"; // 1 3 5


	/*
		  1
		/   \
	   2	 3
	  /		/ \
	 4     6   7
	            \
	             8
	*/
	Node treeB(1);
	treeB.left = new Node(2);
	treeB.right = new Node(3);
	treeB.right->left = new Node(6);
	treeB.right->right = new Node(7);
	treeB.right->right->right = new Node(8);
	treeB.left->left = new Node(4);

	for(int i: largestPathSum(&treeB))
		std::cout << i << " ";
	std::cout << "\n"; // 1 3 7 8


	/*
		  1
		/   \
	   2	 3
	  /	\	/ \
	 4  20 6   7
	            \
	             8
	*/
	Node treeC(1);
	treeC.left = new Node(2);
	treeC.right = new Node(3);
	treeC.right->left = new Node(6);
	treeC.right->right = new Node(7);
	treeC.right->right->right = new Node(8);
	treeC.left->left = new Node(4);
	treeC.left->left = new Node(20);

	for(int i: largestPathSum(&treeC))
		std::cout << i << " ";
	std::cout << "\n"; // 1 2 20

	return 0;
}