#include <iostream>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Apple:

LRU cache is a cache data structure that has limited space, and once there are more items in the cache than available space, it will preempt the least recently used item. What counts as recently used is any item a key has 'get' or 'put' called on it.

Implement an LRU cache class with the 2 functions 'put' and 'get'. 'put' should place a value mapped to a certain key, and preempt items if needed. 'get' should return the value for a given key if it exists in the cache, and return None if it doesn't exist.

Here's some examples and some starter code.

class LRUCache:
  def __init__(self, space):
    # Fill this in.

  def get(self, key):
    # Fill this in.

  def put(self, key, value):
    # Fill this in.

cache = LRUCache(2)

cache.put(3, 3)
cache.put(4, 4)
print(cache.get(3))
# 3
print(cache.get(2))
# None

cache.put(2, 2)

print(cache.get(4))
# None (pre-empted by 2)
print(cache.get(3))
# 3

*/

// TC get - o(1), put - o(1)
// SC o(capacity)
class DoublyLinkedList {
public:
	int key;
	int value;
	DoublyLinkedList* next;
	DoublyLinkedList* prev;
	DoublyLinkedList(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {};
};

class LRUCache {
	int cap;
	int currSize=0;
	DoublyLinkedList* head = nullptr;
	DoublyLinkedList* tail = nullptr;
	DoublyLinkedList* list = nullptr;
	unordered_map<int, DoublyLinkedList*> mp;
public:
	LRUCache(int capacity): cap(capacity) {};

	int get(int key) {
		if (mp.find(key) == mp.end()) return -1;
		
		DoublyLinkedList* node = mp[key];

		// return if found key is already at head position
		if (head->key == node->key) return node->value;
	
		node->prev->next = node->next;
		if (tail->key != node->key) {
			node->next->prev = node->prev;
		}
		else {
			tail = tail->prev;
			tail->next = nullptr;
		}

		node->next = head;
		head->prev = node;
		head = head->prev;

		return node->value;
	}

	void put(int key, int value) {
		if (!head && !tail) {
			list = new DoublyLinkedList(key, value);
			head = tail = list;
			mp[key] = list;
			currSize++;
			return;
		}

		// update and move key to head position if key already exists
		if (mp.find(key) != mp.end()) {
			mp[key]->value = value;
			get(key);
			return;
		}

		if (currSize == cap) {
			mp.erase(tail->key);
			tail = tail->prev;
			tail->next = nullptr;
			currSize--;
		}

		DoublyLinkedList* node = new DoublyLinkedList(key, value);
		node->next = head;
		head->prev = node;
		head = head->prev;
		mp[key] = node;
		currSize++;
	}
};

int main() {
	cout << "cache1:\n";
	LRUCache cache1(2);
	cache1.put(3,3);
	cache1.put(4,4);
	cout << cache1.get(3) << "\n"; // 3
	cout << cache1.get(2) << "\n"; // -1
	cache1.put(2,2);
	cout << cache1.get(4) << "\n"; // -1
	cout << cache1.get(2) << "\n"; // 2
	cache1.put(1,1);
	cout << cache1.get(3) << "\n"; // -1
	cout << "\n";

	cout << "cache2:\n";
	LRUCache cache2(2);
	cache2.put(2,2);
	cout << cache2.get(2) << "\n"; // 2
	cout << cache2.get(1) << "\n"; // -1
	cache2.put(1,1);
	cache2.put(1,5);
	cout << cache2.get(1) << "\n"; // 5
	cout << cache2.get(2) << "\n"; // 2
	cache2.put(8,8);
	cout << cache2.get(1) << "\n"; // -1
	cout << cache2.get(8) << "\n"; // 8
	cout << "\n";

	cout << "cache3:\n";
	LRUCache cache3(2);
	cache3.put(2,2);
	cout << cache3.get(2) << "\n"; // 2
	cout << cache3.get(1) << "\n"; // -1
	cache3.put(1,1);
	cache3.put(2,10);
	cout << cache3.get(1) << "\n"; // 1
	cout << cache3.get(2) << "\n"; // 10
	cache3.put(8,8);
	cout << cache3.get(1) << "\n"; // -1
	cout << cache3.get(8) << "\n"; // 8
	cout << "\n";

	cout << "cache4:\n";
	LRUCache cache4(3);
	cache4.put(2,2);
	cout << cache4.get(2) << "\n"; // 2
	cout << cache4.get(1) << "\n"; // -1
	cache4.put(1,1);
	cache4.put(2,10);
	cout << cache4.get(1) << "\n"; // 1
	cout << cache4.get(2) << "\n"; // 10
	cache4.put(8,8);
	cout << cache4.get(1) << "\n"; // 1
	cout << cache4.get(8) << "\n"; // 8
	cache4.put(10, 12);
	cout << cache4.get(2) << "\n"; // -1
	cout << "\n";

	cout << "cache5:\n";
	LRUCache cache5(2);
	cache5.put(2,2);
	cout << cache5.get(2) << "\n"; // 2
	cout << cache5.get(1) << "\n"; // -1
	cache5.put(1,1);
	cache5.put(2,10);
	cache5.put(8,8);
	cout << cache5.get(8) << "\n"; // 8
	cout << cache5.get(2) << "\n"; // 10
	cout << cache5.get(1) << "\n"; // -1
	cache5.put(10, 12);
	cout << cache5.get(2) << "\n"; // 10
	cout << "\n";

	return 0;
}
