#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by Uber:

Given a list of numbers, find if there exists a pythagorean triplet in that list. A pythagorean triplet is 3 variables a, b, c where a2 + b2 = c2

Example:
Input: [3, 5, 12, 5, 13]
Output: True
Here, 52 + 122 = 132.

def findPythagoreanTriplets(nums):
  # Fill this in.

print findPythagoreanTriplets([3, 12, 5, 13])
# True

*/

// TC - o(n^2)
// SC - O(n)
bool findPythagoreanTriplets(vector<int> nums) {
	unordered_map<int, bool> mp;
	for (int i: nums) {
		mp[i*i] = true;
	}
	for (int i=0; i<nums.size(); i++) {
		for (int j=0; j<nums.size(); j++) {
			if (i == j) {
				continue;
			}
			if (mp.count(nums[i]*nums[i]+nums[j]*nums[j])) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	cout << findPythagoreanTriplets({3,12,5,13}) << "\n"; // true
	cout << findPythagoreanTriplets({3,11,5,13}) << "\n"; // false
	return 0;
}
