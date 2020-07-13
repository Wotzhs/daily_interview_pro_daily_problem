#include <iostream>
using namespace std;

/*

This problem was recently asked by Twitter:

You are given an array of k sorted singly linked lists. Merge the linked lists into a single sorted linked list and return it.

Here's your starting point:

class Node(object):
  def __init__(self, val, next=None):
    self.val = val
    self.next = next

  def __str__(self):
    c = self
    answer = ""
    while c:
      answer += str(c.val) if c.val else ""
      c = c.next
    return answer

def merge(lists):
  # Fill this in.

a = Node(1, Node(3, Node(5)))
b = Node(2, Node(4, Node(6)))
print merge([a, b])
# 123456

*/

class Node {
public:
	int val;
	Node* next;
	Node(int v, Node* n): val(v), next(n) {};
};

Node* merge(Node* a, Node* b) {
	Node* merged;
	Node* head = merged;
	while(a != nullptr && b != nullptr) {
		if (a->val > b->val) {
			head->next = new Node(b->val, nullptr);
			b = b->next;
		} else {
			head->next = new Node(a->val, nullptr);
			a = a->next;
		}
		head = head->next;
	}

	while (a != nullptr) {
		head->next = new Node(a->val, nullptr);
		a = a->next;
	}

	while (b != nullptr) {
		head->next = new Node(b->val, nullptr);
		b = b->next;
	}

	return merged->next;
}

void print(Node* ans) {
	while(ans != nullptr) {
		cout << ans->val;
		ans = ans->next;
	}
	cout << "\n";
}

int main(){
	Node* a = new Node(1, new Node(3, new Node(5, nullptr)));
	Node* b = new Node(2, new Node(4, new Node(6, nullptr)));
	print(merge(a, b)); // 123456
	return 0;
}