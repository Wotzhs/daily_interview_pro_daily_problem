#include <iostream>

/*

This problem was recently asked by Microsoft:

You are given two linked-lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
Here is the function signature as a starting point (in Python):

# Definition for singly-linked list.
class ListNode(object):
  def __init__(self, x):
    self.val = x
    self.next = None

class Solution:
  def addTwoNumbers(self, l1, l2, c = 0):
    # Fill this in.

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

result = Solution().addTwoNumbers(l1, l2)
while result:
  print result.val,
  result = result.next
# 7 0 8

*/

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int v): val(v), next(nullptr) {};
};

ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
	ListNode* ans = new ListNode(0);
	ListNode* head = ans;
	int carryOver=0;
	while(l1 != nullptr || l2 != nullptr) {
		if (l1 != nullptr) head->val += l1->val;
		if (l2 != nullptr) head->val += l2->val;

		if (head->val > 9) {
			head->val %= 10;
			head->next = new ListNode(1);
		} 
		else if (l1->next != nullptr && l2->next != nullptr) {
			head->next = new ListNode(0);
		} 

		head = head->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	return ans;
}

void print(ListNode* ans) {
	while (ans != nullptr) {
		std::cout << ans->val << " ";
		ans = ans->next;
	}
	std::cout << "\n";
}

int main(){
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	print(addTwoNumber(l1, l2)); // 7 0 8
	
	ListNode* l3 = new ListNode(9);
	l3->next = new ListNode(9);
	l3->next->next = new ListNode(9);

	ListNode* l4 = new ListNode(9);
	l4->next = new ListNode(9);
	l4->next->next = new ListNode(9);

	print(addTwoNumber(l3, l4)); // 8 9 9 1

	return 0;
}