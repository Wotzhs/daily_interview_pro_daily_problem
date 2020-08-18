#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int v): val(v), left(nullptr), right(nullptr) {};
	Node(int v, Node* l, Node* r): val(v), left(l), right(r) {};
};


typedef vector<Node*> vn;
typedef vector<vector<Node*>> vvn;

vvn dupTrees(Node* root) {
	vvn ans;
	if (!root) return ans;
	queue<Node*> q;
	q.emplace(root);
	while(q.size()) {
		Node* prev = q.front();
		q.pop();
		vn tmp;

		int n = q.size();
		for (int i=0; i < n; i++) {
			Node* curr = q.front();
			q.pop();
			if (
				curr->val == prev->val 
				&& (
					curr->left == prev->left
					|| (curr->left != nullptr && prev->left != nullptr && curr->left->val == prev->left->val)
				)
				&& (
					curr->right == prev->right
					|| (curr->right != nullptr && prev->right != nullptr && curr->right->val == prev->right->val)
				)
			) {
				tmp.emplace_back(prev);
				tmp.emplace_back(curr);
			}
			if (curr->left != nullptr) q.emplace(curr->left);
			if (curr->right != nullptr) q.emplace(curr->right);
		}
			if (tmp.size()) ans.emplace_back(tmp);

		if (prev->left != nullptr) q.emplace(prev->left);
		if (prev->right != nullptr) q.emplace(prev->right);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

void printTree(Node* root) {
	if (!root) return;
	cout << "(" << root->val;
	if (root->left) {
		cout << ", ";
		printTree(root->left);
	}
	if (root->right) {
		cout << ", ";
		printTree(root->right);
	}
	cout << ")" ;
}

void print(vvn ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << "[";
		for (int j=0; j<ans[i].size(); j++) {
			printTree(ans[i][j]);
			if (j<ans[i].size()-1) cout << ", ";
		}
		cout << "]";
		if (i<ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main() {
	/*
	       1
	      / \
	     2   2
	    /   /
	   3   3
	*/
	Node* n3_1 = new Node(3);
	Node* n2_1 = new Node(2, n3_1, nullptr);
	Node* n3_2 = new Node(3);
	Node* n2_2 = new Node(2, n3_2, nullptr);
	Node* n1 = new Node(1, n2_1, n2_2);

	print(dupTrees(n1)); // [[(3), (3)], [(2, (3)), (2, (3))]]

	/*
	         1
	      /    \
	     2     2
	    / \   / \
	   3   4 3   4
	*/

	Node* m4_1 = new Node(4);
	Node* m3_1 = new Node(3);
	Node* m2_1 = new Node(2, m3_1, m4_1);
	Node* m4_2 = new Node(4);
	Node* m3_2 = new Node(3);
	Node* m2_2 = new Node(2, m3_2, m4_2);
	Node* m1 = new Node(1, m2_1, m2_2);

	print(dupTrees(m1)); // (2, (3), (4))(2, (3), (4))
	
	return 0;
}
