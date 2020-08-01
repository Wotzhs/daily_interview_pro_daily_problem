#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

Given a sorted array, convert it into a binary search tree.

Can you do this both recursively and iteratively?

class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def __str__(self):
      return f"{self.val}, ({self.left}, {self.right})"

class Solution(object):
    def sortedArrayToBST(self, nums):
      # Fill this in.

n = Solution().sortedArrayToBST([-10, -3, 0, 5, 9])
print(n)
# 0, (-3, (-10, (None, None), None), 9, (5, (None, None), None))

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

Node* subDivide(vector<int> nums, int lo, int hi) {
	if (lo>hi) return nullptr;
	int mid = (lo+hi)/2;
	Node* root = new Node(nums[mid]);
	root->left = subDivide(nums, lo, mid-1);
	root->right = subDivide(nums, mid+1, hi);
	return root;
}

Node* sortedArrayToBST(vector<int> nums) {
	return subDivide(nums, 0, nums.size()-1);
}

void print(Node* root) {
	if (!root) {
		cout << "None";
		return;
	}
	cout << root->val << ", (";
	print(root->left);
	cout << ", ";
	print(root->right);
	cout << ")";
}

int main(){
	print(sortedArrayToBST({-10,-3,0,5,9})); // 0, (-10, (None, -3, (None, None)), 5, (None, 9, (None, None)))
	return 0;
}