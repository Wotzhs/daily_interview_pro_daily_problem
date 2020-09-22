#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

This problem was recently asked by Amazon:

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Here is the method signature:

class Solution:
  def minSubArrayLen(self, nums, s):
    # Fill this in

print Solution().minSubArrayLen([2, 3, 1, 2, 4, 3], 7)
# 2

*/

// tc o(n)
// sc o(1)
int minSubArrayLen(vector<int> nums, int s) {
	int l=0, r=0, ans=INT_MAX, sum=0;
	while(r<nums.size()) {
		if (sum>=s) {
			ans = min(ans, r-l);
			sum -= nums[l++];
			continue;
		}
		sum+=nums[++r];
	}
	return ans;
}

int main() {
	cout << minSubArrayLen({2,3,1,2,4,3}, 7) << "\n"; // 2
	cout << minSubArrayLen({2,3,1,2,4,3}, 4) << "\n"; // 1
	cout << minSubArrayLen({2,3,1,2,4,3}, 6) << "\n"; // 2
	return 0;
}
