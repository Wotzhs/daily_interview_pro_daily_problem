#include <iostream>
#include <queue>
#include <unordered_map>

/*

This problem was recently asked by LinkedIn:

You are only allowed to perform 2 operations, multiply a number by 2, or subtract a number by 1. Given a number x and a number y, find the minimum number of operations needed to go from x to y.

Here's an example and some starter code.

def min_operations(x, y):
  # Fill this in.

print(min_operations(6, 20))
# (((6 - 1) * 2) * 2) = 20 : 3 operations needed only
# print 3


*/


// credit: https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/
int minimumOperations(int x, int y) {
	std::queue<std::pair<int, int>> q;
	std::unordered_map<int, bool> visited;

	q.push(std::make_pair(x, 0));
	while(q.size()) {
		std::pair<int, int> p = q.front();
		q.pop();

		if (p.first == y) return p.second;
		if (p.first*2 == y || p.first-1 == y) return p.second+1;

		visited[p.first] = true;

		if (visited.find(p.first*2) == visited.end()) q.push(std::make_pair(p.first*2, p.second+1));
		if (visited.find(p.first-1) == visited.end()) q.push(std::make_pair(p.first-1, p.second+1));
	}
	return -1;
}	


int main() {
	int x=6,y=20;
	std::cout << "minimumOperations(" << x << ", " << y << ")\n";
	std::cout << minimumOperations(x, y) << "\n"; // 3

	x=6,y=13;
	std::cout << "minimumOperations(" << x << ", " << y << ")\n";
	std::cout << minimumOperations(x, y) << "\n"; // 6

	x=2,y=8;
	std::cout << "minimumOperations(" << x << ", " << y << ")\n";
	std::cout << minimumOperations(x, y) << "\n"; // 2
	return 0;
}