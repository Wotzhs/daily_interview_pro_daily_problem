#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

You are given a binary tree representation of an arithmetic expression. In this tree, each leaf is an integer value,, and a non-leaf node is one of the four operations: '+', '-', '*', or '/'.

Write a function that takes this tree and evaluates the expression.

Example:

    *
   / \
  +    +
 / \  / \
3  2  4  5

This is a representation of the expression (3 + 2) * (4 + 5), and should return 45.

Here's a starting point:

class Node:
  def __init__(self, val, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

PLUS = "+"
MINUS = "-"
TIMES = "*"
DIVIDE = "/"

def evaluate(root):
  # Fill this in.

tree = Node(TIMES)
tree.left = Node(PLUS)
tree.left.left = Node(3)
tree.left.right = Node(2)
tree.right = Node(PLUS)
tree.right.left = Node(4)
tree.right.right = Node(5)
print evaluate(tree)
# 45

*/

char PLUS = '+';
char MINUS = '-';
char TIMES = '*';
char DIVIDE = '/';

class Node {
public:
	char val;
	Node* left;
	Node* right;
	Node(int v): val(v) {};
};

void dfs(Node* node, vector<char>& v) {
	if (!node) return;
	dfs(node->left, v);
	dfs(node->right, v);
	v.emplace_back(node->val);
}

int evaluate(Node* root) {
	stack<int> s;
	vector<char> v;
	dfs(root, v);
	int a=0, b=0;
	for (char ch: v) {
		if (ch != PLUS && ch != MINUS && ch != TIMES && ch != DIVIDE) {
			s.push(ch-'0');
			continue;
		}

		a = s.top();
		s.pop();
		b = s.top();
		s.pop();

		if (ch == PLUS) s.push(a + b);
		if (ch == MINUS) s.push(a - b);
		if (ch == TIMES) s.push(a * b);
		if (ch == DIVIDE) s.push(a / b);
	}

	return s.top();
}

int main(){
	/*
	         *
	       /  \
	      +    +
	     / \  / \
	    3  2 4   5
	*/
	Node* treeA = new Node(TIMES);
	treeA->left = new Node(PLUS);
	treeA->left->left = new Node('3');
	treeA->left->right = new Node('2');
	treeA->right = new Node(PLUS);
	treeA->right->left = new Node('4');
	treeA->right->right = new Node('5');

	cout << evaluate(treeA) << "\n"; // 45

	/*
	         /
	       /  \
	      +    -
	     / \  / \
	    4  5 3   2
	*/
	Node* treeB = new Node(DIVIDE);
	treeB->left = new Node(MINUS);
	treeB->left->left = new Node('2');
	treeB->left->right = new Node('3');
	treeB->right = new Node(PLUS);
	treeB->right->left = new Node('4');
	treeB->right->right = new Node('5');

	cout << evaluate(treeB) << "\n"; // 9

	return 0;
}