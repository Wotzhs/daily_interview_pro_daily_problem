#include <iostream>
using namespace std;

/*

This problem was recently asked by AirBNB:

Given a linked list and a number k, rotate the linked list by k places.

Here's some starter code and an example:

class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def __str__(self):
    current = self
    ret = ''
    while current:
      ret += str(current.value)
      current = current.next
    return ret

def rotate_list(list, k):
  # Fill this in.

# Order is 1, 2, 3, 4
llist = Node(1, Node(2, Node(3, Node(4))))

# Order should now be 3, 4, 1, 2
print(rotate_list(llist, 2))
# 3412

*/

// TC - o(2n) = o(n)
// SC - o(1)
class Node {
public:
	int val;
	Node* next;
	Node(int v): val(v), next(nullptr) {};
	Node(int v, Node* n): val(v), next(n) {};
};

Node* rotateList(Node* list, int k) {
	int n=0;
	Node *head=list, *tail, *newHead;
	while(head && ++n) head=head->next;

	int netK=k%n;
	if (!netK) return list;
	
	head=list;
	for (int i=0; i<n-netK-1; i++) head=head->next;
	tail=head;

	newHead=tail->next;
	tail->next = nullptr;
	head = newHead;
	while(head->next) head=head->next;
	head->next=list;

	return newHead;
}

void print(Node* n) {
	while(n) cout << n->val, n=n->next;
	cout << "\n";
}

int main() {
	Node* llist = new Node(1, new Node(2, new Node(3, new Node(4))));
	print(rotateList(llist, 2)); // 3412

	Node* llist2 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	print(rotateList(llist2, 2)); // 45123

	Node* llist3 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	print(rotateList(llist3, 100)); // 12345

	Node* llist4 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	print(rotateList(llist4, 5)); // 12345
	
	Node* llist5 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));
	print(rotateList(llist5, 4)); // 23451
	
	return 0;
}
