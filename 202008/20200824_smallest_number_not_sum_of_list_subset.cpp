#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

This problem was recently asked by AirBNB:

Given a sorted list of positive numbers, find the smallest positive number that cannot be a sum of any subset in the list.

Example:
Input: [1, 2, 3, 8, 9, 10]
Output: 7
Numbers 1 to 6 can all be summed by a subset of the list of numbers, but 7 cannot.

def findSmallest(nums):
  # Fill this in.

print findSmallest([1, 2, 3, 8, 9, 10])
# 7

*/

// credit: https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
// TC - o(n)
// SC - o(1)
int findSmallest(vector<int> nums) {
	int ans = 1;
	for (int i=0; i<nums.size() && nums[i]<=ans; i++)
		ans += nums[i];
	return ans;
}

int main() {
	cout << findSmallest({1,2,3,8,9,10}) << "\n"; // 7
	cout << findSmallest({1,2,3,4}) << "\n"; // 11
	cout << findSmallest({2,3,4}) << "\n"; // 1
	cout << findSmallest({1,2,4}) << "\n"; // 8

	return 0;
}
