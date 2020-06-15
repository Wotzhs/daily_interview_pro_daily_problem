#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
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

int minSubArrayLen(vector<int>& nums, int s) {
	int next=0, prev=0, sum=0, len=INT_MAX;
	while(next < nums.size()) {
		sum += nums[next++];
		while(sum >= s) {
			len = min(len, next-prev);
			sum -= nums[prev++];
		}
	}
	return len == INT_MAX ? 0 : len;
}

int main(){
	vector<int> nums1 = {2, 3, 1, 2, 4, 3};
	int s1 = 7;
	cout << minSubArrayLen(nums1, s1) << "\n"; // 2

	vector<int> nums2 = {2, 3, 1, 2, 4, 3};
	int s2 = 4;
	cout << minSubArrayLen(nums2, s2) << "\n"; // 1

	vector<int> nums3 = {2, 3, 1, 2, 4, 3};
	int s3 = 16;
	cout << minSubArrayLen(nums3, s3) << "\n"; // 0

	return 0;
}