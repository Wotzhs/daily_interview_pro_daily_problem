#include <iostream>
using namespace std;

/*

This problem was recently asked by Apple:

You are given two singly linked lists. The lists intersect at some node. Find, and return the node. Note: the lists are non-cyclical.

Example:

A = 1 -> 2 -> 3 -> 4
B = 6 -> 3 -> 4

This should return 3 (you may assume that any nodes with the same value are the same node).

Here is a starting point:

def intersection(a, b):
  # fill this in.

class Node(object):
  def __init__(self, val):
    self.val = val
    self.next = None
  def prettyPrint(self):
    c = self
    while c:
      print c.val,
      c = c.next

a = Node(1)
a.next = Node(2)
a.next.next = Node(3)
a.next.next.next = Node(4)

b = Node(6)
b.next = a.next.next

c = intersection(a, b)
c.prettyPrint()
# 3 4

*/

// n - length of linked list a, m - length of linked list b
// TC - o(n+m)
// SC - o(1)
class Node {
public:
	int val;
	Node* next;
	Node(int v): val(v), next(nullptr) {};
};

Node* intersection(Node* a, Node* b) {
	Node *dummyA=a, *dummyB=b;
	while (dummyA && dummyB) {
		if (dummyA->val == dummyB->val) return dummyA;
		dummyA = dummyA->next, dummyB = dummyB->next;
	}

	if (!dummyB) {
		dummyB=a;
		while(dummyA) {
			if (dummyA->val == dummyB->val) return dummyA;
			dummyA = dummyA->next, dummyB = dummyB->next;
		}
	}

	if (!dummyA) {
		dummyA=b;	
		while(dummyB) {
			if (dummyA->val == dummyB->val) return dummyA;
			dummyA = dummyA->next, dummyB = dummyB->next;
		}
	}


	return nullptr;
}

void print(Node* n) {
	while(n) cout << n->val << " ", n=n->next;
	cout << "\n";
}

int main() {
	Node* a = new Node(1);
	a->next = new Node(2);
	a->next->next = new Node(3);
	a->next->next->next = new Node(4);

	Node* b = new Node(6);
	b->next = a->next->next;

	print(intersection(a,b)); // 3 4
	return 0;
}
