#include <iostream>
#include <stack>
using namespace std;

/*

This problem was recently asked by LinkedIn:

Given a binary tree, perform an in-order traversal both recursively and iteratively.

class Node:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


def inorder(node):
  # Fill this in.

def inorder_iterative(node):
  # Fill this in.

#     12
#    /  \
#   6    4
#  / \   / \
# 2   3 7   8
n = Node(12, Node(6, Node(2), Node(3)), Node(4, Node(7), Node(8)))

inorder(n)
# 2 6 3 12 7 4 8

inorder_iterative(n)
# 2 6 3 12 7 4 8

*/

// n = number of nodes
// TC - o(n)
// SC - o(n)
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};

void inorder(Node* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void inorderIterative(Node* root) {
	stack<Node*> st;
	Node* node=root;
	while(node || st.size()) {
		while(node) st.push(node), node=node->left;
		node = st.top(), st.pop();
		cout << node->val << " ";
		node = node->right;
	}
}

int main() {
	Node* n = new Node(12, new Node(6, new Node(2), new Node(3)), new Node(4, new Node(7), new Node(8)));
	inorder(n); // 2 6 3 12 7 4 8
	cout << "\n";

	inorderIterative(n); // 2 6 3 12 7 4 8
	cout << "\n";
	return 0;
}
