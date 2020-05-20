#include <iostream>
#include <unordered_map>

/*

This problem was recently asked by Amazon:

Given a sorted linked list of integers, remove all the duplicate elements in the linked list so that all elements in the linked list are unique.

Here's an example and some starter code:

class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def __repr__(self):
    return f"({self.value}, {self.next})"


def remove_dup(lst):
  # Fill this in.

lst = Node(1, Node(2, Node(2, Node(3, Node(3)))))

remove_dup(lst)
print(lst)
# (1, (2, (3, None)))

*/

class Node {
public:
	int value;
	Node* next;
	Node(int v): value(v), next(nullptr) {};
	Node(int v, Node* n): value(v), next(n) {};
};

Node* removeDup(Node* node) {
	if (!node) return node;
	std::unordered_map<int, bool> mp;
	Node* curr=node;
	mp[curr->value] = true;
	while(curr!=nullptr && curr->next != nullptr) {
		if (mp.find(curr->next->value) != mp.end()) {
			curr->next = curr->next->next;
			continue;
		}
		mp[curr->next->value] = true;
		curr = curr->next;
	}
	
	return node;
}

void print(Node* node) {
	if (node != nullptr) {
		std::cout << "(" << node->value << ", ";
		print(node->next);
		std::cout << ")";
		return;
	}
	
	std::cout << "None)";
}

int main() {
	Node* listA = new Node(1, new Node(2, new Node(2, new Node(3, new Node(3)))));
	print(removeDup(listA)); // (1, (2, (3, None))))
	std::cout << "\n";

	Node* listB = new Node(1, new Node(2, new Node(2, new Node(3, new Node(1)))));
	print(removeDup(listB)); // (1, (2, (3, None))))
	std::cout << "\n";

	Node* listC = new Node(1, new Node(2, new Node(2, new Node(3, new Node(4, new Node(2))))));
	print(removeDup(listC)); // (1, (2, (3, (4, None))))
	std::cout << "\n";
	return 0;
}