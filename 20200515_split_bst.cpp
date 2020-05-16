#include <iostream>

/*

This problem was recently asked by Twitter:

Given a binary search tree (BST) and a value s, split the BST into 2 trees, where one tree has all values less than or equal to s, and the other tree has all values greater than s while maintaining the tree structure of the original BST. You can assume that s will be one of the node's value in the BST. Return both tree's root node as a tuple.

Here's an example and some starting code:

class Node:
  def __init__(self, value, left=None, right=None):
    self.value = value
    self.left = left
    self.right = right

  def __repr__(self):
    if self.left and self.right:
      return f"({self.value}, {self.left}, {self.right})"
    if self.left:
      return f"({self.value}, {self.left})"
    if self.right:
      return f"({self.value}, None, {self.right})"
    return f"({self.value})"

def split_bst(bst, s):
  # Fill this in.
  
n2 = Node(2)
n1 = Node(1, None, n2)

n5 = Node(5)
n4 = Node(4, None, n5)

root = Node(3, n1, n4)

print(root)
# (3, (1, (2)), (4, None, (5)))
# How the tree looks like
#     3
#   /   \
#  1     4
#   \     \
#    2     5

print(split_bst(root, 2))
# ((1, None, (2)), (3, None, (4, None, (5))))
# Split into two trees
# 1    And   3
#  \          \
#   2          4
#               \
#                5

*/

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node(int val): value(val) {};
	Node(int val, Node* l, Node* r): value(val), left(l), right(r) {};
};

std::pair<Node*, Node*> splitBST(Node* node, int v) {
	if (!node) return std::make_pair(nullptr, nullptr);
	if (node->value == v) {
		return std::make_pair(node->left, node->right);
	}

	Node* newNode = node;
	Node* prev = newNode;
	if (newNode->value > v) {
		while(newNode->value > v) {
			prev = newNode;
			newNode = newNode->left;
		}
	} else {
		while(newNode->value < v) {
			prev = newNode;
			newNode = newNode->right;
		}
	}

	if (prev->value > v) {
		prev->left = nullptr;
		Node* curr = newNode;
		while(1) {
			if (!curr) break;
			if (!curr->right || curr->right->value > v) {
				curr->right = nullptr;
				break;
			}
			curr = curr->right;
		}
	}

	if (prev->value < v) prev->right = nullptr;

	return std::make_pair(newNode, node);
}

void print(Node* root) {
	if(!root) return;
	if (root->left != nullptr && root->right != nullptr) {
		std::cout << "(" << root->value << ", ";
		print(root->left);
		std::cout<<", ";
		print(root->right);
		std::cout<<")";
		return;
	}
	if (root->left != nullptr) {
		std::cout << "(" << root->value << ", ";
		print(root->left);
		std::cout << ")";
		return;
	}
	if (root->right != nullptr) {
		std::cout << "(" << root->value << ", None, ";
		print(root->right);
		std::cout << ")";
		return;
	}

	std::cout << "(" << root->value << ")";
}

int main() {
	/*
	       3
	      / \
	     1   4
	      \   \
	       2   5
	*/

	Node* n2 = new Node(2);
	Node* n1 = new Node(1, nullptr, n2);
	Node* n5 = new Node(5);
	Node* n4 = new Node(4, nullptr, n5);
	Node* rootA = new Node(3, n1, n4);

	print(rootA);
	std::cout << "\n"; // (3, (1, None, (2))(4, None, (5)))

	auto bstPair = splitBST(rootA, 2);
	std::cout<<"(";
	print(bstPair.first);
	std::cout<<", ";
	print(bstPair.second);
	std::cout<<")\n"; // ((1, None, (2)), (3, None, (4, None, (5))))


	/*
	        6
	      /   \
	    /      \
	   /        \
	  1          9
	   \        /
	    2      7
	     \      \
	      3      8
	       \
	        4
	         \
	          5
	*/

	Node* m5 = new Node(5);
	Node* m4 = new Node(4, nullptr, m5);
	Node* m3 = new Node(3, nullptr, m4);
	Node* m2 = new Node(2, nullptr, m3);
	Node* m1 = new Node(1, nullptr, m2);
	Node* m8 = new Node(8);
	Node* m7 = new Node(7, nullptr, m8);
	Node* m9 = new Node(9, m7, nullptr);
	Node* rootB = new Node(6, m1, m9);

	print(rootB);
	std::cout << "\n"; // (6, (1, None, (2, None, (3, None, (4, None, (5))))), (9, (7, None, (8)))))

	bstPair = splitBST(rootB, 4);
	std::cout<<"(";
	print(bstPair.first);
	std::cout<<", ";
	print(bstPair.second);
	std::cout<<")\n"; // ((1, None, (2, None, (3, None, (4)))), (6, None, (9, (7, None, (8)))))

	return 0;
}