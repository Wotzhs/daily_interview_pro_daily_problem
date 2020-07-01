#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Microsoft:

You are given an array of integers in an arbitrary order. Return whether or not it is possible to make the array non-decreasing by modifying at most 1 element to any value.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example:

[13, 4, 7] should return true, since we can modify 13 to any value 4 or less, to make it non-decreasing.

[13, 4, 1] however, should return false, since there is no way to modify just one element to make the array non-decreasing.

Here is the function signature:

def check(lst):
  # Fill this in.

print check([13, 4, 7])
# True
print check([5,1,3,2,5])
# False

Can you find a solution in O(n) time?

*/

bool check(vector<int> list) {
	for (int i=0, mod=0; i<list.size()-1; i++) {
		if (list[i] > list[i+1]) {
			if (i-1 >=0 && list[i-1] >= list[i+1]) list[i+1] = list[i];    
			else list[i] = list[i+1];
			mod++;
		}
		if (mod > 1) return false;
	}

	return true;
}

int main(){
	cout << check({13,4,7}) << "\n"; // true
	cout << check({5,1,3,2,5}) << "\n"; // false
	cout << check({4,2,3}) << "\n"; // true
	cout << check({3,4,2,3}) << "\n"; // false
	return 0;
}