#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Apple:

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library’s sort function for this problem.

Can you do this in a single pass?

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Here's a starting point:

class Solution:
  def sortColors(self, nums):
    # Fill this in.

nums = [0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1]
print("Before Sort: ")
print(nums)
# [0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1]

Solution().sortColors(nums)
print("After Sort: ")
print(nums)
# [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2]

*/

// credit: https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C%2B%2B-solution-with-Good-Explanation
void sortColours(vector<int>& nums) {
	for (int i=0, j=0, k=nums.size()-1; i<=k; i++) {
		if (nums[i] == 0) swap(nums[j++], nums[i]);
		else if (nums[i] == 1) continue;
		else swap(nums[k--], nums[i--]);
	}
}

void print(vector<int> ans) {
	cout << "[";
	for (int i=0; i<ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	vector<int> nums = {0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1};
	print(nums); // [0, 1, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 2, 1]
	sortColours(nums); 
	print(nums); // [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2]
	return 0;
}