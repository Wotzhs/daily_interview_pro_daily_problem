#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a tree, the leaves form a certain order from left to right. Two trees are considered "leaf-similar" if their leaf orderings are the same.

For instance, the following two trees are considered leaf-similar because their leaves are [2, 1]:
    3
   / \ 
  5   1
   \
    2 
    7
   / \ 
  2   1
   \
    2 
Our job is to determine, given two trees, whether they are "leaf similar."

class Node(object):
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None
  
class Solution(object):
  def leafSimilar(self, root1, root2):
    # Fill this in.

#    3
#   / \ 
#  5   1
#   \
#    2 

t1 = Node(3)
t1.left = Node(5)
t1.right = Node(1)
t1.left.left = Node(6)
t1.left.right = Node(2)

#    7
#   / \ 
#  2   1
#   \
#    2 
t2 = Node(7)
t2.left = Node(2)
t2.right = Node(1)
t2.left.left = Node(6)
t2.left.right = Node(2)

print(Solution().leafSimilar(t1, t2))
# True

*/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

void dfs(Node* node, vector<int>* leafs) {
	if (node == nullptr) return;
	if (node->left == nullptr && node->right == nullptr)
		leafs->emplace_back(node->val);
	dfs(node->left, leafs);
	dfs(node->right, leafs);
}

bool leafSimilar(Node* t1, Node* t2) {
	if (!t1 && !t2) return true;
	vector<int> leafs1, leafs2;
	dfs(t1, &leafs1);
	dfs(t2, &leafs2);
	if (leafs1.size() != leafs2.size()) return false;
	for (int i=0; i<leafs1.size(); i++)
		if (leafs1[i] != leafs2[i]) return false;
	return true;
}

int main(){
	/*
	        3
	       / \ 
	      5   1
	     / \
	    6    2 
	*/
	Node* t1 = new Node(3);
	t1->left = new Node(5);
	t1->right = new Node(1);
	t1->left->left = new Node(6);
	t1->left->right = new Node(2);

	/*
	        7
	       / \ 
	      2   1
	     / \
	    6   2 
	*/
	Node* t2 = new Node(7);
	t2->left = new Node(2);
	t2->right = new Node(1);
	t2->left->left = new Node(6);
	t2->left->right = new Node(2);

	cout << leafSimilar(t1, t2) << "\n"; // true

	return 0;
}