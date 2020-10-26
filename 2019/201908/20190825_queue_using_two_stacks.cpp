#include <iostream>
#include <stack>
using namespace std;

/*

This problem was recently asked by Apple:

Implement a queue class using two stacks. A queue is a data structure that supports the FIFO protocol (First in = first out). Your class should support the enqueue and dequeue methods like a standard queue.

Here's a starting point:

class Queue:
  def __init__(self):
    # Fill this in.
    
  def enqueue(self, val):
    # Fill this in.

  def dequeue(self):
    # Fill this in.

q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print q.dequeue()
print q.dequeue()
print q.dequeue()
# 1 2 3

*/
	
class Queue {
public:
	stack<int> main, tmp;
	Queue() {}

	// TC - o(stack.size())
	// SC - o(stack.size())
	void enqueue(int v) {
		while(main.size()) {
			int top = main.top();
			main.pop();
			tmp.push(top);
		}
		main.push(v);
		while(tmp.size()) {
			int top = tmp.top();
			tmp.pop();
			main.push(top);
		}
	}

	// TC - o(1)
	// SC - o(1)
	int dequeue() {
		if (!main.size()) {
			return 0;
		}
		int top = main.top();
		main.pop();
		return top;
	}
};

int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.dequeue() << "\n"; // 1
	cout << q.dequeue() << "\n"; // 2
	cout << q.dequeue() << "\n"; // 3
	return 0;
}
