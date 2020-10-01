#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

This problem was recently asked by Amazon:

Given a binary tree, return all values given a certain height h.

Here's a starting point:

class Node():
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

def valuesAtHeight(root, height):
  # Fill this in.

#     1
#    / \
#   2   3
#  / \   \
# 4   5   7

a = Node(1)
a.left = Node(2)
a.right = Node(3)
a.left.left = Node(4)
a.left.right = Node(5)
a.right.right = Node(7)
print valuesAtHeight(a, 3)
# [4, 5, 7]

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
};

vector<int> valuesAtHeight(Node* node, int height) {
	vector<int> ans;
	queue<pair<Node*, int>> q;
	q.emplace(make_pair(node, 1));
	while(q.size()) {
		pair<Node*, int> curr = q.front();
		q.pop();

		if (curr.second == height) {
			ans.emplace_back(curr.first->val);
		}
		
		if (curr.first->left) {
			q.emplace(make_pair(curr.first->left, curr.second+1));
		}

		if (curr.first->right) {
			q.emplace(make_pair(curr.first->right, curr.second+1));
		}
	}

	return ans;
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i<ans.size()-1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	Node* a = new Node(1);
	a->left = new Node(2);
	a->right = new Node(3);
	a->left->left = new Node(4);
	a->left->right = new Node(5);
	a->right->right = new Node(7);

	print(valuesAtHeight(a, 3)); // [4, 5, 7]
	return 0;
}
