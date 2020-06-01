#include <iostream>
#include <vector>
#include <unordered_map>

/*

This problem was recently asked by Amazon:

Given two arrays, write a function to compute their intersection - the intersection means the numbers that are in both arrays.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.

Here's a starting point:

class Solution:
  def intersection(self, nums1, nums2):
    # Fill this in.

print Solution().intersection([4, 9, 5], [9, 4, 9, 8, 4])
# [9, 4]

*/

std::vector<int> arrayIntersection(std::vector<int> &nums1, std::vector<int> &nums2) {
	std::unordered_map<int, bool> mp;
	for (int i=0; i < nums1.size(); i++)
		mp[nums1[i]] = true;

	std::vector<int> ans;
	for (int i=0; i < nums2.size(); i++)
		if(mp.find(nums2[i])!=mp.end()) {
			ans.emplace_back(nums2[i]);
			mp.erase(nums2[i]);
		}

	return ans;
}

int main() {
	std::vector<int> nums1 = {4,9,5};
	std::vector<int> nums2 = {9,4,9,8,4};
	std::vector<int> ans = arrayIntersection(nums1, nums2);

	std::cout << "[";
	for (int i=0; i < ans.size(); i++) {
		std::cout << ans[i];
		if (i != ans.size()-1)
			std::cout << ", ";
	}
	std::cout << "]"; // [9, 4]

	return 0;
}