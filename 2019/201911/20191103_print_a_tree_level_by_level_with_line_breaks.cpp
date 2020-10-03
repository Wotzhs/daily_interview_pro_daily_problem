#include <iostream>
#include <queue>
using namespace std;

/*

This problem was recently asked by Apple:

You are given a tree, and your job is to print it level-by-level with linebreaks.

    a
   / \
  b   c
 / \ / \
d  e f  g

The output should be
a
bc
defg
Here's a starting point:

from collections import deque

class Node(object):
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

  def __str__(self):
    # Fill this in.

tree = Node('a')
tree.left = Node('b')
tree.right = Node('c')
tree.left.left = Node('d')
tree.left.right = Node('e')
tree.right.left = Node('f')
tree.right.right = Node('g')

print tree
# a
# bc
# defg

*/

// n - number of nodes
// TC - o(n)
// SC - o(n)
class Node {
public:
	char val;
	Node* left;
	Node* right;
	Node(char ch): val(ch), left(nullptr), right(nullptr) {};
};

void print(Node* root) {
	if (!root) return;
	queue<Node*> q;
	q.emplace(root);
	while(q.size()) {
		int n=q.size();
		for (int i=0; i<n; i++) {
			Node* curr = q.front();
			q.pop();

			if (curr->left) {
				q.emplace(curr->left);
			}

			if (curr->right) {
				q.emplace(curr->right);
			}

			cout << curr->val;
		}
		cout << "\n";
	}
}

int main() {
	Node* tree = new Node('a');
	tree->left = new Node('b');
	tree->right = new Node('c');
	tree->left->left = new Node('d');
	tree->left->right = new Node('e');
	tree->right->left = new Node('f');
	tree->right->right = new Node('g');
	print(tree);
	// a
	// bc
	// defg

	return 0;
}
