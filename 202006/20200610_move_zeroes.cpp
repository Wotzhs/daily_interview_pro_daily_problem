#include <iostream>
#include <vector>
using namespace std;

/*

This problem was recently asked by Facebook:

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

Here is a starting point:

class Solution:
  def moveZeros(self, nums):
    # Fill this in.

nums = [0, 0, 0, 2, 0, 1, 3, 4, 0, 0]
Solution().moveZeros(nums)
print(nums)
# [2, 1, 3, 4, 0, 0, 0, 0, 0, 0]

*/

vector<int>& moveZeroes(vector<int> &nums) {
	for (int i=0, zero=-1; i<nums.size(); i++) {
		if (nums[i] == 0 && zero < 0) zero = i;
		if (nums[i] != 0 && zero >= 0) {
			swap(nums[i], nums[zero]);
			zero++;
		}
	}

	return nums;
}

void print(vector<int> &nums) {
	cout << "[";
	for (int i=0; i<nums.size(); i++) {
		cout << nums[i];
		if (i < nums.size()-1) cout << ", ";
	}
	cout << "]\n";
}

int main(){
	vector<int> nums1 = {0, 0, 0, 2, 0, 1, 3, 4, 0, 0};
	print(moveZeroes(nums1)); // [2, 1, 3, 4, 0, 0, 0, 0, 0, 0]

	vector<int> nums2 = {0,1,0,3,12};
	print(moveZeroes(nums2)); // [1, 3, 12, 0, 0]

	vector<int> nums3 = {1,1,0,0};
	print(moveZeroes(nums3)); // [1, 1, 0, 0]	
	return 0;
}