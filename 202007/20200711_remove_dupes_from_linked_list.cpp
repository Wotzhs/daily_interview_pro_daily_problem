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

class Node {
public:
	int val;
	Node* next;
	Node(int v, Node* n): val(v), next(n) {};
};

void deleteDuplicates(Node* node) {
	if (!node) return;

	unordered_map<int, int> mp;
	Node* n = node;
	while(n != nullptr) {
		mp[n->val]++;
		n = n->next;
	}

	n = node;
	while(n != nullptr && n->next != nullptr) {
		if (mp[n->next->val]>1) n->next = n->next->next;
		else n = n->next;
	}
}

void print(Node* ans) {
	while(ans != nullptr){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << "\n";
}

int main(){
	Node* n = new Node(1, new Node(2, new Node(3, new Node(3, new Node(4, nullptr)))));
	print(n); // 1 2 3 3 4
	deleteDuplicates(n);
	print(n); // 1 2 4

	return 0;
}