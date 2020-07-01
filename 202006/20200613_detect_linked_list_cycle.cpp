#include <iostream>

/*

This problem was recently asked by Uber:

Given a linked list, determine if the linked list has a cycle in it. For notation purposes, we use an integer pos which represents the zero-indexed position where the tail connects to.

Example:
Input: head = [4,3,2,1,0], pos = 1.  
Output: true
The example indicates a list where the tail connects to the second node.

class ListNode(object):
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution(object):
  def hasCycle(self, head):
    # Fill this in.

testHead = ListNode(4)
node1 = ListNode(3)
testHead.next = node1
node2 = ListNode(2)
node1.next = node2
node3 = ListNode(1)
node2.next = node3
testTail = ListNode(0)
node3.next = testTail
testTail.next = node1

print(Solution().hasCycle(testHead))
# True

*/

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int v): val(v), next(nullptr) {};
};

bool hasCycle(ListNode* node) {
	ListNode *slow=node, *fast=node->next;
	while(slow != fast) {
		if (slow == nullptr || fast == nullptr) return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

int main(){
	ListNode* testHeadA = new ListNode(4);
	ListNode* node1 = new ListNode(3);
	testHeadA->next = node1;
	ListNode* node2 = new ListNode(2);
	node1->next = node2;
	ListNode* node3 = new ListNode(1);
	node2->next = node3;
	ListNode* testTailA = new ListNode(0);
	node3->next = testTailA;
	testTailA->next = node1;

	std::cout << hasCycle(testHeadA) << "\n"; // true

	ListNode* testHeadB = new ListNode(4);
	ListNode* node4 = new ListNode(3);
	testHeadB->next = node4;
	ListNode* node5 = new ListNode(2);
	node4->next = node5;
	ListNode* node6 = new ListNode(1);
	node5->next = node6;
	ListNode* testTailB = new ListNode(0);
	node6->next = testTailB;
	
	std::cout << hasCycle(testHeadB) << "\n"; // false

	return 0;
}