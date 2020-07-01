#include <iostream>
#include <queue>
using namespace std;

/*

This problem was recently asked by Twitter:

You are given the root of a binary tree. Find and return the largest subtree of that tree, which is a valid binary search tree.

Here's a starting point:

class TreeNode:
  def __init__(self, key):
    self.left = None
    self.right = None
    self.key = key

  def __str__(self):
    # preorder traversal
    answer = str(self.key)
    if self.left:
      answer += str(self.left)
    if self.right:
      answer += str(self.right)
    return answer

def largest_bst_subtree(root):
  # Fill this in.

#     5
#    / \
#   6   7
#  /   / \
# 2   4   9
node = TreeNode(5)
node.left = TreeNode(6)
node.right = TreeNode(7)
node.left.left = TreeNode(2)
node.right.left = TreeNode(4)
node.right.right = TreeNode(9)
print largest_bst_subtree(node)
#749

*/

class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int key;
	TreeNode(int k): key(k), left(nullptr), right(nullptr) {};
};

TreeNode* largestBstSubtree(TreeNode* root) {
	if (!root) return nullptr;
	
	int sum = 0;
	TreeNode* ans;
	queue<TreeNode*> q;
	q.emplace(root);

	while(q.size()) {
		TreeNode* node = q.front();
		q.pop();

		int tmpSum = node->key;

		if (node->left != nullptr) {
			tmpSum += node->left->key;
			q.emplace(node->left);
		}

		if (node->right != nullptr) {
			tmpSum += node->right->key;
			q.emplace(node->right);
		}

		if (tmpSum > sum) {
			sum = tmpSum;
			ans = node;
		}
	}

	return ans;
}

void print(TreeNode* node) {
	int key=node->key, leftKey, rightKey;
	if (node->left != nullptr) leftKey = node->left->key;
	if (node->right != nullptr) rightKey = node->right->key;
	printf("%i%i%i\n", key, leftKey, rightKey);
}

int main(){
	TreeNode* node = new TreeNode(5);
	node->left = new TreeNode(6);
	node->right = new TreeNode(7);
	node->left->left = new TreeNode(2);
	node->right->left = new TreeNode(4);
	node->right->right = new TreeNode(9);
	
	print(largestBstSubtree(node)); // 749

	return 0;
}