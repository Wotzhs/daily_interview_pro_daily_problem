#include <iostream>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Twitter:

Given a linked list, remove all duplicate values from the linked list.

For instance, given 1 -> 2 -> 3 -> 3 -> 4, then we wish to return the linked list 1 -> 2 -> 4.

class Node(object):
  def __init__(self, val, next=None):
    self.val = val
    self.next = next
  def __str__(self):
    if not self.next:
      return str(self.val)
    return str(self.val) + " " + str(self.next)

class Solution(object):
  def deleteDuplicates(self, node):
    # Fill this in.


n = Node(1, Node(2, Node(3, Node(3, Node(4)))))
print(n)
# 1 2 3 3 4
Solution().deleteDuplicates(n)
print(n)
# 1 2 4

*/

// TC o(2n) = o(n)
// SC o(n)
class Node {
public:
	int val;
	Node* next;
	Node(int v): val(v), next(nullptr) {};
	Node(int v, Node* n): val(v), next(n) {};
};

Node* deleteDuplicates(Node* n) {
	if (!n) return n;
	Node* head = n;
	unordered_map<int, int> freq;

	// populate frequency map
	while (head) {
		freq[head->val]++;
		head = head->next;
	}
	
	// remove head node if dupes
	while(freq[n->val]>1) n = n->next;

	head = n->next;
	Node* prev = n;
	
	// head is no longer a dupe can start to look for the node ahead of head
	while(head && head->next) {
		if (freq[head->val]>1) prev->next = head->next->next;
		prev = head;
		head = head->next;
	}

	return n;
}

void print(Node* n) {
	if (!n) return;
	while (n!=nullptr) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << "\n";
}

int main() {
	Node* n = new Node(1, new Node(2, new Node(3, new Node(3, new Node(4)))));
	print(n); // 1 2 3 3 4
	print(deleteDuplicates(n)); // 1 2 4

	Node* m = new Node(1, new Node(1, new Node(2, new Node(3, new Node(3, new Node(4))))));
	print(m); // 1 1 2 3 3 4
	print(deleteDuplicates(m)); // 2 4
	return 0;
}
