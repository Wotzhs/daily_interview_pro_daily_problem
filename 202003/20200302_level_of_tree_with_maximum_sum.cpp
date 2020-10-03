#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/*

This problem was recently asked by Microsoft:

Given a binary tree, find the level in the tree where the sum of all nodes on that level is the greatest.

Here's an example and some starter code.

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

  def __repr__(self):
    return f"(Value: {self.value} Left: {self.left} Right: {self.right})"


def tree_level_max_sum(root):
  # Fill this in.

n3 = Node(4, Node(3), Node(2))
n2 = Node(5, Node(4), Node(-1))
n1 = Node(1, n2, n3)

"""
    1          Level 0 - Sum: 1
   / \
  4   5        Level 1 - Sum: 9 
 / \ / \
3  2 4 -1      Level 2 - Sum: 8

"""

print(tree_level_max_sum(n1))
# Should print 1 as level 1 has the highest level sum

*/

// n - number of nodes
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

int treeLevelMaxSum(Node* root) {
	if (!root) return -1;
	int mxv=INT_MIN, mxl=-1;
	queue<pair<Node*, int>> q;
	q.emplace(make_pair(root, 0));
	while (q.size()) {
		int tmp=0, n=q.size(), lvl;
		for (int i=0; i<n; i++) {
			pair<Node*, int> p = q.front();
			q.pop();
			lvl = p.second;
			tmp += p.first->val;
			if (p.first->left) {
				q.emplace(make_pair(p.first->left, p.second+1));
				
			}
			if (p.first->right) {
				q.emplace(make_pair(p.first->right, p.second+1));
			}
		}
		if (tmp>mxv) {
			mxv = tmp;
			mxl = lvl;
		}
	}
	return mxl;
}

int main() {
	Node* n3 = new Node(4, new Node(3), new Node(2));
	Node* n2 = new Node(5, new Node(4), new Node(-1));
	Node* n1 = new Node(1, n2, n3);
	cout << treeLevelMaxSum(n1) << "\n"; // 1
	return 0;
}
