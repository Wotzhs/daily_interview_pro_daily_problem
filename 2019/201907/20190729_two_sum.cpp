#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Facebook:

You are given a list of numbers, and a target number k. Return whether or not there are two numbers in the list that add up to k.

Example:
Given [4, 7, 1 , -3, 2] and k = 5,
return true since 4 + 1 = 5.

def two_sum(list, k):
  # Fill this in.

print two_sum([4,7,1,-3,2], 5)
# True

Try to do it in a single pass of the list.

*/

// tc - o(n)
// sc - o(n)
bool twoSum(vector<int> nums, int k) {
	unordered_map<int, int> mp;
	for (int i: nums) {
		mp[i]++;
	}

	for (int i: nums) {
		mp[i]--;
		int diff = k-i;
		if (mp.count(diff) && mp[diff]>=0) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << twoSum({4,7,1,-3,2}, 5)	<< "\n"; // true
	cout << twoSum({4,7,1,-3,2,5,5}, 10) << "\n"; // true
	cout << twoSum({4,7,1,-3,2,5,5}, 15) << "\n"; // false
	return 0;
}
